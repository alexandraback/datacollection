#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

const long long INF = 1000000000000000000LL;

long long myabs (long long a) {
    if (a > 0) return a;
    else
        return -a;
}

long long greedy (string a, string b, int pos, int ch1, int ch2) {
    a[pos] = '0' + ch1;
    b[pos] = '0' + ch2;
    
    if (ch1 > ch2) {
        for(int i = pos+1; i < a.length(); ++i) if (a[i] == '?') a[i] = '0';
        for(int i = pos+1; i < b.length(); ++i) if (b[i] == '?') b[i] = '9';
    } else {
        for(int i = pos+1; i < a.length(); ++i) if (a[i] == '?') a[i] = '9';
        for(int i = pos+1; i < b.length(); ++i) if (b[i] == '?') b[i] = '0';
    }
    
    long long q1 = 0, q2 = 0;
    for(int i = 0; i < a.length(); i++) q1 = q1 * 10LL + a[i] - '0';
    for(int i = 0; i < b.length(); i++) q2 = q2 * 10LL + b[i] - '0';
    
    return myabs(q1 - q2);
    
}

long long smallestDiff (string A, string B) {
    int n = A.length();
    long long ret = INF;
    for(int i = 0; i < n; i++) {
        for(int c1 = 0; c1 < 10; c1++) for(int c2 = 0; c2 < 10; c2++) if (c1 != c2 && (A[i] - '0' == c1 || A[i] == '?') && (B[i] - '0' == c2 || B[i] == '?')) {
            ret = min(ret, greedy(A, B, i, c1, c2));
        }
        if (A[i] != '?' && B[i] != '?' && A[i] != B[i]) break;
        A[i] = B[i] = '0';
    }
    if (A==B) return 0;
    return ret;
}

int tn;

int main () {
    
    cin >> tn;
    for(int ti = 1; ti <= tn; ti++) {
        string A, B;
        cin >> A >> B;
        long long ideal = smallestDiff(A, B);
        
        for(int i = 0; i < A.length(); ++i) if (A[i] == '?') for(int j = 0; j < 10; j++) {
            A[i] = '0' + j;
            if (ideal == smallestDiff(A, B)) break;
        }
        
        for(int i = 0; i < B.length(); ++i) if (B[i] == '?') for(int j = 0; j < 10; j++) {
            B[i] = '0' + j;
            if (ideal == smallestDiff(A, B)) break;
        }
        
        cout << "Case #" << ti << ": " << A << " " << B << endl;
        
    }
    
    return 0;
}