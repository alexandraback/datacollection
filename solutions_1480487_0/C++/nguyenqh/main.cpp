/* 
 * File:   main.cpp
 * Author: NQH
 *
 * Created on May 5, 2012, 11:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#define MAXAB 100000
#define EPS 1e-8
#define MAXN 202

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
//    freopen ("A-large-practice.in", "r", stdin);
    freopen ("A-small-attempt0.in", "r", stdin);    
    freopen ("a.out", "w", stdout);
//    ifstream fin ("a.in");
//    ofstream fout ("a.out");
//    
    int test,ntest;
    cin >> ntest;
    
    for (test=1; test<=ntest; test++) {
//        fout << "Case #" << test << ": ";
        printf("Case #%d: ",test);
        int n,x;
        int i,j;
        int s[MAXN];
        cin >> n;
        for (i=0; i<n; i++) 
            cin >> s[i];
        for (x=0, i=0; i<n; i++) 
            x += s[i];
        for (i=0; i<n; i++) {
            double m = 1.0, lm,rm;
            double a,b,d;
            lm = 0; rm = 1;
            while ((rm-lm)>EPS) {
                m = (lm+rm)/2;
                a = s[i] + m*x;
                b = (1-m)*x;
                
                for (d=0, j=0; j<n; j++) 
                    if (j!=i) {
                        if (s[j]<a) {
                            d += a-s[j];
                        }
                    }
                if (d>=b) {     // i not eliminated
                    rm = m;     // decrease m
                }
                else {          // i may be eliminated
                    lm = m;     // increase m;
                }
            }
            printf("%6f ",(lm+rm)*100/2);
        }
        printf("\n");
        
//        printf("Case #%d: %6f\n",test,mine);
            
            
    }
    return 0;
}

