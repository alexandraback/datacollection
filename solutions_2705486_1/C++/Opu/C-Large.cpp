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

char str[15];
const int mxsize = 1200000, inf = (1<<30);

struct trie
{
    bool f;
    int childs[27];
};

char S[4004];
int dp[4004][6];
trie T[mxsize]; int cur_id;

void clear( trie *param )
{
    param->f = false;
    memset( param->childs,-1,sizeof(param->childs) );
}

void init()
{
    cur_id = 1;
    for(int i = 0;i<mxsize;++i) clear(&T[i]);
}

void insert(int i,int node)
{
    if( !str[i] )
    {
        T[node].f = true; return;
    }

    int id = str[i]-'a';

    if( T[node].childs[id] == -1 )
    {
        T[node].childs[id] = cur_id++;
    }
    insert( i+1, T[node].childs[id] );
}

bool query(int s, int e, int node)
{
    if( s == e ) return T[node].f;

    int id = S[s]-'a';
    if( T[node].childs[id] == -1 ) return false;

    return query( s+1, e, T[node].childs[id] );
}

int calc(int pos, int dist)
{
    if( !S[pos] ) return 0;

    int &ret = dp[pos][dist];

    if( ret != -1 )
    {
        return ret;
    }
    ret = inf;

    for(int k = 1;k<=10;++k)
    {
        if( query( pos, pos+k, 0 ) ) ret = min( ret , calc(pos+k,min(5,dist+k)) );

        char tmp, tmp1;
        int offset = 5-dist;

        for(int i = offset;i<k;++i)
        {
            tmp = S[pos+i];
            for(char j = 'a';j<='z';++j)
            {
                S[pos+i] = j;

                //changed 1 char.
                if( query( pos,pos+k,0 ) ) ret = min( ret , calc(pos+k,min(5,k-i))+1 );

                for(int l = i+5;l<k;++l)
                {
                    tmp1 = S[pos+l];
                    for(char c = 'a';c<='z';++c)
                    {
                        S[pos+l] = c;

                        if( query(pos,pos+k,0) ) ret = min( ret , calc(pos+k,min(5,k-l))+2 );
                    }
                    S[pos+l] = tmp1;
                }
            }
            S[pos+i] = tmp;
        }

        if( !S[pos+k] ) break;
    }
    return ret;
}

int main()
{
    freopen("dictonary.txt","r",stdin);

    init();
    while( gets(str) )
    {
        insert(0,0);
    }

    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);

    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        scanf("%s",S);

        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",ca,calc(0,5));
    }
    return 0;
}
