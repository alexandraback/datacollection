/* 
 * File:   main.cpp
 * Author: NQH
 *
 * Created on May 6, 2012, 12:51 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#define MAXT 1e9
#define EPS 1e-8
#define MAXMN 102

using namespace std;

/*
 * 
 */

typedef struct {
    int i,j;
    int c,f;  
    double t;
    int tideon;
    
} Cave;

const int di[] = { -1 , 0 , 1 , 0 };
const int dj[] = { 0 , 1 , 0 , -1 };

double max (double a, double b) {
    return (a>b ? a : b);
}

int main(int argc, char** argv) {
//    freopen ("A-large-practice.in", "r", stdin);
//    freopen ("B-small-attempt0.in", "r", stdin);
    freopen ("B-large.in", "r", stdin);
//    freopen ("b.in", "r", stdin);
    freopen ("b.out", "w", stdout);
//    ifstream fin ("a.in");
//    ofstream fout ("a.out");
//    
    int test,ntest;
    cin >> ntest;
    
    for (test=1; test<=ntest; test++) {
//        fout << "Case #" << test << ": ";
        printf("Case #%d: ",test);
        int h, n, m;
        int i,j;
        Cave g[MAXMN][MAXMN];
        double t[MAXMN][MAXMN];
        Cave Q[2*MAXMN * MAXMN];
        
        cin >> h >> n >> m;
        for (i=0; i<=n+1; i++) {
            for (j=0; j<=m+1; j++) {
                g[i][j].i = i;
                g[i][j].j = j;
                g[i][j].t = MAXT;
                g[i][j].c = 0;
                g[i][j].f = 0;
            }
        }
        for (i=1; i<=n; i++) {
            for (j=1; j<=m; j++) {
                cin >> g[i][j].c;
            }
        }
        for (i=1; i<=n; i++) {
            for (j=1; j<=m; j++) {
                cin >> g[i][j].f;
            }
        }
        
        int l=0, r=0;
        int k, u, v;
        double hcurr, twait;
        
        g[1][1].t = 0;
        g[1][1].tideon = 0;
        Q[0] = g[1][1];
        while (l<=r) {            
            i = Q[l].i;
            j = Q[l].j;
            l++;
            for (k=0; k<4; k++) {
                u = i+di[k];
                v = j+dj[k];
                // pass to next cave ?  
                if (g[u][v].t < g[i][j].t) 
                    continue;
                if (g[u][v].c - g[u][v].f < 50)
                    continue;
                if (g[u][v].c - g[i][j].f < 50)
                    continue;
                if (g[i][j].c - g[u][v].f < 50)
                    continue;
                
                
                hcurr = max(g[i][j].f, h- 10*g[i][j].t);
                
                if (g[u][v].c - hcurr < 50)
                   twait = (50-(g[u][v].c-hcurr))/10;
                else twait = 0;
                
                hcurr = max(g[i][j].f, hcurr - 10*twait);
                
                if (hcurr - g[i][j].f >=20 ) { // use kayak
                    if (g[u][v].t > (g[i][j].t + twait + 1)) {
                        
                        if ((twait==0) && (!g[i][j].tideon)) {
                            g[u][v].tideon = 0;
                            g[u][v].t = 0;
                        }
                        else {
                            g[u][v].tideon = 1;
                            g[u][v].t = g[i][j].t + twait + 1;
                        }
                        r++;
                        Q[r] = g[u][v];
                    }
                   
                }
                else {
                    if (g[u][v].t > (g[i][j].t + twait + 10)) {
                        if ((twait==0) && (!g[i][j].tideon)) {
                            g[u][v].tideon = 0;
                            g[u][v].t = 0;
                        }
                        else {
                            g[u][v].tideon = 1;
                            g[u][v].t = g[i][j].t + twait + 10;
                        }
                        r++;
                        Q[r] = g[u][v];                        
                    }                    
                }
            }
        }
        printf("%6f\n",g[n][m].t);
//        printf("Case #%d: %6f\n",test,mine);
            
            
    }

    return 0;
}

