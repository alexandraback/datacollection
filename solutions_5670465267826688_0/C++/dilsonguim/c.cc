#include <iostream>
#include <cstdlib>

using namespace std;

int mul_table[4][4] = {{1, 2, 3, 4},
                       {2, -1, 4, -3},
                       {3, -4, -1, 2},
                       {4, 3, -2, -1}};

int mul(const int a, const int b){
    const int sign = a * b / abs(a * b);
    const int value = mul_table[abs(a) - 1][abs(b) - 1];
    return sign * value;
}

int pow(const int a, const long long p){
    if(p == 0){
        return 1;
    }else if(p == 1){
        return a;
    }else{
        const int part = pow(a, p / 2);
        return p % 2 ? mul(mul(part, part), a) : mul(part, part);
    }
}

int value(const char c){
    if(c == 'i') return 2;
    if(c == 'j') return 3;
    return 4;
}


bool check(const string& s, const long long x){
    int a = 1;
    for(const auto si : s) a = mul(a, value(si));
    return pow(a, x) == mul(mul(2, 3), 4);
}

int leftMostI(const string& s){
    const int L = int(s.size());
    int a = 1;
    for(int i = 0; i < 8 * L; i++){
        a = mul(a, value(s[i % L]));
        if(a == 2) return i;
    }
    return -1;
}

int rightMostK(const string& s){
    const int L = int(s.size());
    int a = 1;
    for(int i = 0; i < 8 * L; i++){
        a = mul(value(s[L - (i % L) - 1]), a);
        if(a == 4) return i;
    }
    return -1;
}

bool solve(const string& s, const long long x){
    if(not check(s, x)) return false;
    const int i = leftMostI(s);
    if(i == -1) return false;
    const int k = rightMostK(s);
    if(k == -1) return false;
    const long long L = s.size();
    return i + k + 2 < L * x;
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int l;
        long long x;
        cin >> l >> x;
        string s;
        cin >> s;

        bool sol = solve(s, x);

        cout << "Case #" << tc << ": " << (sol ? "YES" : "NO") << "\n";
    }
}
