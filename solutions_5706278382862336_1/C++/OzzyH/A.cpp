#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

long long GCD(long long A, long long B) {
    while (B != 0LL) {
        long long t = B;
        B = A % B;
        A = t;
    }
    return A;
}

int run_once(ifstream &fin) {
    long long A, B;
    char c;
    fin >> A >> c >> B;
    long long G = GCD(A, B);
    A /= G; B /= G;
    if (A > B) return -1;
    int cnt = 0;
    long long B2 = B;
    while (B2 != 1) {
        if (B2 % 2LL != 0) return -1;
        B2 /= 2LL;
        cnt++;
    }
    if (cnt > 40) return -1;
    cnt = 0;
    while (A < B) {
        A *= 2LL;
        cnt ++;
    }
    return cnt;
}

int main() {
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");
    int N;
    fin >> N;
    for (int i=0; i<N; i++) {
        fout << "Case #" << i+1 << ": ";
        int t = run_once(fin);
        if (t == -1) fout << "impossible";
        else fout << t;
        fout << endl;
    }
    return 0;
}
