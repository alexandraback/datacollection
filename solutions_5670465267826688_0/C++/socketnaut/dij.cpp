#include <iostream>
using namespace std;

int T, L, X;
string s;

int tb[4][4] = {{ 1,  2,  3,  4},
                { 2, -1,  4, -3},
                { 3, -4, -1,  2},
                { 4,  3, -2, -1}}; 

int mult(int a, int b){
    int sign = (a * b > 0) ? 1 : -1;
    a = abs(a);
    b = abs(b);
    return sign * tb[a-1][b-1];
}

int findi(){
    int st = 1;
    for(int i=0; i<min(4, X)*L; i++){
        st = mult(st, s[i%L]-'i'+2);
        if(st == 2) return i;
    }
    return -1;
}

int findk(){
    int st = 1;
    for(int k=L*X-1; k>=max(0, X-4)*L; k--){
        st = mult(s[k%L]-'i'+2, st);
        if(st == 4) return k;
    }
    return -1;
}

int eval(){
    int st = 1;
    for(int i=0; i<(X%4)*L; i++)
        st = mult(st, s[i%L]-'i'+2);
    return st;
}

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> L >> X >> s;
        int i = findi(), k = findk(), e = eval();
        
        cout << "Case #" << t << ": ";
        if(i!=-1 && k!=-1 && i+1 < k && e == -1)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
