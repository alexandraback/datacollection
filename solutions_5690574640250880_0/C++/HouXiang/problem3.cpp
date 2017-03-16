// problem3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <queue>

using namespace std; 

int r, c, m; 
const int R = 52; 
char map[R][R]; 
int imap[R][R]; 
int imap_bak[R][R]; 

bool isOk() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<R; j++) {
            imap[i][j] = 0; 
            imap_bak[i][j] = 0; 
        }
    }

    int non_mine = 0; 
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (map[i][j] == '.') {
                int n = 0; 
                for (int ii=i-1; ii<=i+1; ii++) 
                    for (int jj=j-1; jj<=j+1; jj++) {
                        if (map[ii][jj] == '*') n++; 
                    }
                imap[i][j] = n; 
                imap_bak[i][j] = n; 
                non_mine++; 
            }
            else {
                imap[i][j] = -1; 
                imap_bak[i][j] = -1; 
            }
        }
    }

    if (non_mine == 1) {
        for (int ii=1; ii<=r; ii++) {
            for (int jj=1;jj<=c; jj++) {
                if (map[ii][jj] == '.') cout << 'c';
                else cout << '*';
            }
            cout << endl;
        }
        return true;
    }
    
    {
        queue<pair<int, int>> q; 
        int x, y; 
        for (int i=1; i<=r; i++) {
            for (int j=1; j<=c; j++) {


                if (imap[i][j] == 0) {
                    x = i; y = j;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();

                        if (p.first == 0 || p.first > r || p.second == 0 || p.second > c)
                            continue;

                        for (int ii=p.first-1; ii<=p.first+1; ii++)
                            for (int jj=p.second-1; jj<=p.second+1; jj++) {
                                if (imap[ii][jj] == 0) {
                                    q.push(make_pair(ii, jj));
                                }
                                imap[ii][jj] = 1000;
                            }
                    }

                    bool ok = true;
                    for (int ii=1;ii<=r;ii++) {
                        for (int jj=1; jj<=c; jj++) {
                            if (imap[ii][jj] != -1 && imap[ii][jj] != 1000) {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok) break;
                    }

                    if (ok) {
                        for (int ii=1; ii<=r; ii++) {
                            for (int jj=1;jj<=c; jj++) {
                                if (ii==x && jj == y) cout << 'c';
                                else if (imap[ii][jj] == 1000) cout << '.';
                                else cout << '*';
                            }
                            cout << endl; 
                        }
                        return true;
                    }

                    for (int ii=1; ii<=r; ii++) {
                        for (int jj=1; jj<=c; jj++) {
                            imap[ii][jj] = imap_bak[ii][jj];
                        }
                    }
                }
            }
        }
    } 
    return false;
}

bool ans(int mn, int p) {
    if (mn > m) {
        // check whether possible
        if (isOk()) 
            return true;
        else 
            return false;
    }

    if (p > r * c) {
        return false;
    }
    else {
        int pp = p; 

        while (pp <= r * c) {
            int rr = (pp-1) / c; 
            int cc = (pp-1) % c; 

            map[rr+1][cc+1] = '*'; 
            if (ans(mn+1, pp+1)) {
                return true;
            }
            map[rr+1][cc+1] = '.';
            pp++;
        }  
        return false;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream inf(argv[1]);
    // ifstream inf("D:\\codejam\\problem3\\Debug\\test.txt"); 

    int t = 0; 
    inf >> t; 
    for (int ca = 1; ca <= t; ca ++) {
        
        inf >> r >> c >> m; 
        for (int i=0; i<R; i++)
            for (int j=0; j<R; j++)
                map[i][j] = '.'; 

        printf ("Case #%d:\n", ca); 
        if (!ans(1, 1)) 
            printf ("Impossible\n"); 
    }

	return 0;
}

