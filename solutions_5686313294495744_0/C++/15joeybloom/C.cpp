#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define MEMSET(x,v) memset(x,v,sizeof(x))
template<class A, class B> inline bool mina(A &x, B y) {return (x > y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return (x < y)?(x=y,1):0;}
typedef long long int LL;

int dj[2010];
vector<int> adj[2010];
int djcounter = 0;
void visit(int i)
{
    if(dj[i] >= 0)
        return;

    dj[i] = djcounter;
    for(int j = 0; j < adj[i].size(); j++)
        visit(adj[i][j]);
}
map<string, int> a, b;
bool aorb[2010];
int main()
{
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++)
    {
        djcounter = 0;
        MEMSET(dj, -1);
        for(int i = 0; i < 2010; i++)
            adj[i].clear();
        
        a.clear();
        b.clear();
        int N;
        cin >> N;

        int nodecounter = 0;
        for(int i = 0; i < N; i++)
        {
            string aword, bword;
            cin >> aword >> bword;

            if(a.count(aword) == 0)
            {
                aorb[nodecounter] = true;
                a[aword] = nodecounter++;
            }
            if(b.count(bword) == 0)
            {
                aorb[nodecounter] = false;
                b[bword] = nodecounter++;
            }

            adj[a[aword]].push_back(b[bword]);
            adj[b[bword]].push_back(a[aword]);
        }

        for(int i = 0; i < nodecounter; i++)
        {
            if(dj[i] < 0)
            {
                visit(i);
                djcounter++;
            }
        }

        int freq[2][2010];
        MEMSET(freq,0);
        for(int i = 0; i < nodecounter; i++)
        {
            if(aorb[i])
            {
                freq[0][dj[i]]++;
            }
            else
            {
                freq[1][dj[i]]++;
            }
        }

        int res = 0;
        for(int i = 0; i < djcounter; i++)
        {
            res += max(freq[0][i], freq[1][i]);
        }

        printf("Case #%d: %d\n", t, N-res);
    }
}
