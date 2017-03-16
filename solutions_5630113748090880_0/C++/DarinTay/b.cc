#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <algorithm>


using namespace std;
#define ll long long

// 1 2  7  8
// 7 8  9  10
// 9 10 11 12
// A 11 12 13
//


int G[100][50];

int N;


int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cin>>N;

        int sm = 1<<20;
        int lg = -1;
        int sm1, sm2;
        int lg1, lg2;
        int M=2*N-1;
        for (int i=0;i<2*N - 1;++i) {
            for (int j=0;j<N;++j) {
                cin>>G[i][j];
            }
            if (G[i][0] < sm) {
                sm = G[i][0];
                sm1 = i;
                sm2 = -1;
            } else if (G[i][0] == sm) {
                sm2 = i;
            }

            if (G[i][N-1] > lg) {
                lg = G[i][N-1];
                lg1 = i;
                lg2 = -1;
            } else if (G[i][N-1] == lg) {
                lg2 = i;
            }
        }

        vector<int> sln;

        for (int i=0;i<(1<<M)-1;++i) {
            vector<int> cols;
            vector<int> rows;
            for (int j=0;j<M;++j) {
                if (i & (1<<j)) {
                    cols.push_back(j);
                } else {
                    rows.push_back(j);
                }
            }
            if (cols.size() != N) continue;
            vector<vector<int>> colvals;
            for (int j=0;j<cols.size();++j) {
                vector<int> cur;
                for (int k=0;k<N;++k) {
                    cur.push_back(G[cols[j]][k]);
                }
                colvals.push_back(cur);
            }
            sort(colvals.begin(), colvals.end());

            map<vector<int>, int> rowcnts;
            for (int j=0;j<rows.size();++j) {
                vector<int> cur;
                for (int k=0;k<N;++k) {
                    cur.push_back(G[rows[j]][k]);
                }
                rowcnts[cur]++;
            }

            vector<vector<int>> missing;
            for (int j=0;j<N;++j) {
                vector<int> row;
                for (int k=0;k<N;++k) {
                    row.push_back(colvals[k][j]);
                }
                if (rowcnts[row] > 0) {
                    rowcnts[row]--;
                } else {
                    missing.push_back(row);
                    if (missing.size() > 1) break;
                }
            }
            
            if (missing.size() == 1) {
                sln = missing[0];
                break;
            }

        }

        printf("Case #%d:", t);
        for (int i=0;i<sln.size();++i) {
            printf(" %d", sln[i]);
        }
        printf("\n");
    }

}
