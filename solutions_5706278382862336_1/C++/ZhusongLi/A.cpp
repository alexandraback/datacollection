#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

long long gcd(long long a,long long b) {
    if (a < b) {
        long long temp = a;
        a = b;
        b = temp;
    }
    //cout << a << ' ' << b << endl;
    if (b == 1) return 1;
    if (a % b == 0) return b;
    a = a - b * (a / b);
    return gcd (b,a);
}

long long calcu(long long a,long long b) {
    if (a % 2 != 0) return -1;
    long long res = 0;
    long long c = a;
    while (c % 2 == 0) {
        if (double(1.0)/double(a/c) <= double(b)/double(a)) {
            return res;
        }
        c = c / 2;
        res++;
    }
    return res;
}

bool check (long long a) {
    while (a % 2 == 0) a = a / 2;
    if (a == 1) return 1;
    return 0;
}
long long tl(string s) {
    int N = s.size();
    long long res = 0;
    for (int i = 0;i < N;i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

int main() {
    ifstream filein;
    ofstream fileout;
    //filein.open("A.in",ios::in);
    //filein.open("A-small-attempt1.in",ios::in);
    filein.open("A-large.in",ios::in);
    fileout.open("output",ios::out);
    int T;
    int j;
    filein >> T;
    string s2;
    getline(filein,s2);
    for (int i = 0;i < T;i++) {
        fileout << "Case #" << i+1 << ": ";
        long long P,Q;
        string s,s1;
        getline(filein,s);
        //cout << s << endl;
        j = 0;
        while (s[j] != '/') {
            j++;
        }
        s1 = s.substr(0,j);
        s2 = s.substr(j+1,s.size() - j - 1);
        //cout << s1 << ' ' << s2 << endl;
        P = tl(s1);
        Q = tl(s2);
        //P = 123;
        //Q = 31488;
        long long K = gcd(P,Q);
        Q = Q / K;
        P = P / K;
        if (check(Q) == 1) {
            //cout << calcu(Q,P) << endl;
            if (calcu(Q,P) == -1) fileout << "impossible" << endl;
            else fileout << calcu(Q,P) << endl;
        }
        else {
            fileout << "impossible" << endl;
        }
    }
    fileout.close();
}