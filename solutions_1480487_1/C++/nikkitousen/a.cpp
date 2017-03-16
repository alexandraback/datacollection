#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define X first
#define Y second

int aabs(int a) { return (a<0)?-a:a; }
int n;
double tot;
double p[220];

int main()
{
    int T;
    cin >> T;
    
    REP(caso, T) {
        cin >> n;
        tot = 0.0;
        REP(i, n) cin >> p[i], tot += p[i];
        
        printf("Case #%d: ", caso+1);
        REP(i, n) {
            double a=0.0, b=1.0;
            while(b-a > 1e-9) {
                double x = (a+b)/2.0;
                
                double acum=0.0;
                REP(j, n) {
                    if(p[j] > p[i]+tot*x) continue;
                    acum += (p[i]+tot*x-p[j])/tot;
                }
                
                //cout << "acum: " << acum << endl;
                if(acum < 1.0) a = x;
                else b = x;
            }
            
            //cout << "res " << i << "   " << a << endl;
            printf(" %.6lf", a*100.0);
        }
        printf("\n");
    }
}
