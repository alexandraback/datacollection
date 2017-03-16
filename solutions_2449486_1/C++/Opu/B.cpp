#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

const inline int __GET_INT(){int ret;scanf("%d",&ret);return ret;}
#define INPT_INT __GET_INT()

typedef long long LL;
const int maxn = 101;

int N, M;
bool row_cut[maxn], col_cut[maxn];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B_large.out","w",stdout);

    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        vector< pair<int,int> > h[maxn];

        N = INPT_INT; M = INPT_INT;
        for(int i = 0;i<N;++i) for(int j = 0;j<M;++j)
        {
            h[INPT_INT].push_back( make_pair(i,j) );
        }

        bool yes = true;
        memset(row_cut,0,sizeof(row_cut));
        memset(col_cut,0,sizeof(col_cut));

        for(int k = maxn-1;k>=1 && yes;--k)
        {
            set<int> blocked_row, blocked_col;

            for(int i = 0;i<h[k].size();++i)
            {
                if( !row_cut[ h[k][i].first ] || !col_cut[ h[k][i].second ] )
                {
                    blocked_row.insert( h[k][i].first );
                    blocked_col.insert( h[k][i].second );
                }
                else
                {
                    yes = false; break;
                }
            }

            for(set<int>::iterator it = blocked_row.begin();it!=blocked_row.end();++it) row_cut[*it] = true;
            for(set<int>::iterator it = blocked_col.begin();it!=blocked_col.end();++it) col_cut[*it] = true;
        }

        printf("Case #%d: %s\n",ca,yes?"YES":"NO");
    }
    return 0;
}
