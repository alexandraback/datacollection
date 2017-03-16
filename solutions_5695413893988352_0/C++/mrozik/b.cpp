#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;

string A, B;

int bestdist = 0x7fffffff;
string bestA, bestB;

void consider(string a, string b, int d) {
    for (int i=0; i<int(a.length()); i++) {
        if (A[i]!='?' && a[i]!=A[i])
            return;
        if (B[i]!='?' && b[i]!=B[i])
            return;
    }
    
    if (d >= bestdist)
        return;
    bestdist = d;
    bestA = a, bestB = b;
}


int main() {
    int T; scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        cin>>A>>B;

        char a[30], b[30];
        bestdist = 0x7fffffff;
        if (A.length()==1) {
            for (int i=0; i<10; i++)
                for (int j=0; j<10; j++)
                    sprintf(a, "%d", i), sprintf(b, "%d", j), consider(a, b, abs(i-j));
        }
        else if (A.length()==2) {
            for (int i=0; i<100; i++)
                for (int j=0; j<100; j++)
                    sprintf(a, "%02d", i), sprintf(b, "%02d", j), consider(a, b, abs(i-j));
        }
        else if (A.length()==3) {
            for (int i=0; i<1000; i++)
                for (int j=0; j<1000; j++)
                    sprintf(a, "%03d", i), sprintf(b, "%03d", j), consider(a, b, abs(i-j));
        }
        else assert(false);
        
        printf("Case #%d: %s %s\n", t, bestA.c_str(), bestB.c_str());
    }
    return 0;
}

