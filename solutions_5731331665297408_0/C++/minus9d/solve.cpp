#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

int N;
int edge[51][51]; ///< エッジのリスト
int es[51]; ///< 頂点が持つエッジの数

bool can_go_next( vector<int> &perm, int i, vector< set<int> > &edges_copy ) {

    int nxt_pos = perm[i+1];

    // 現在位置
    int pos = perm[i];

    // printf("examine: %d->%d can go? \n", pos+1, nxt_pos+1);
    

    while(1){
        
        // posからnext_posに行けたらOK
        if ( edges_copy[pos].count( nxt_pos ) ){
            edges_copy[pos].erase( nxt_pos );
            // printf("%d -> %d  can go\n", pos+1, nxt_pos+1);
            return true;
        }
        // 行けない場合
        else {

            // 過去のどれかのノードに戻る
            bool can_go_back = false;
            for ( ; i > 0; --i)
            {
                int prev_pos = perm[i - 1];

                // printf("%d->%d can go back?\n", pos+1, prev_pos+1);

                // 戻れる
                if (edges_copy[pos].count( prev_pos ) ){
                    edges_copy[pos].erase( prev_pos );
                    pos = prev_pos;
                    --i;
                    can_go_back = true;
                    break;
                }

            }
            if (!can_go_back) return false;
        }
    }

    return false;
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        int N, M;
        cin >> N >> M;
        vector<string> strs(N);
        REP(n,N){
            cin >> strs[n];
        }

        REP(i, N) es[i] = 0;

        vector< set<int> > edges(N);

        REP(m,M){
            int j, k;
            cin >> j >> k;
            --j; --k;
            edge[j][es[j]++] = k;
            edge[k][es[k]++] = j;

            edges[j].insert(k);
            edges[k].insert(j);
        }
        
        vector<int> perm(N);
        REP(i, N){
            perm[i] = i;
        }

        string ret = "";
        do {
            // perm[0] = 0;
            // perm[1] = 1;
            // perm[2] = 2;
            // perm[3] = 3;
            // perm[4] = 4;
            // perm[5] = 5;


     
            vector< set<int> > edges_copy = edges;

            // 最初に戻れるかテスト
            vector<int> perm_copy = perm;
            perm_copy.pb( perm[0] );
            
            bool fail = false;
            // int pos = perm[0];
            REP(i, N-1){
                // int nxt_pos = perm[i];
                if ( can_go_next( perm_copy, i, edges_copy ) ){
                    // do nothing
                }
                else{
                    fail = true;
                    break;
                }
            }

            if (!fail){
                // チケット全部使ったか？
                REP( from, N ) {
                    FOREACH( to, edges_copy[from] ){
                        if ( !edges_copy[ *to ].count( from ) ){
                            continue;
                        }
                    }
                }

                
                string str = "";
                REP(i, N){
                    str += strs[ perm[i] ];
                }

                // cout << str <<" : OK! ";
                // REP(i, N){
                //     cout << perm[i]+1;
                // }
                // cout << endl;

                if (ret == "") ret = str;
                else {
                    ret = min( ret, str);
                }
            }
            
        } while ( next_permutation(ALL(perm)) );
        

        cout << "Case #" << (test+1) << ": " << ret << endl;
    }

    return 0;
}
