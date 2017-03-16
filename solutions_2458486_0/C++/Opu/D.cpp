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

char can_unlock[(1<<20)];
int key_map[22], key_inside[22][22], total_key, key_in_hand[22], N, adj[(1<<20)];

char calc(int mask)
{
    if( mask == (1<<N)-1 ) return 1;
    char &ret = can_unlock[mask];

    if( ret != -1 )
    {
        return ret;
    }
    ret = 0;

    int cur_keys[22] = {0};
    for(int i = 0;i<N;++i) if(mask&(1<<i))
    {
        cur_keys[ key_map[i] ]--;

        for(int j = 0;j<total_key;++j) cur_keys[j] += key_inside[i][j];
    }

    for(int i = 0;i<N && ret < 1;++i) if( !(mask&(1<<i)) && (cur_keys[ key_map[i] ] + key_in_hand[ key_map[i] ]) )
    {
        ret = max( ret , calc(mask|(1<<i)) );
        if( ret ) adj[mask] = mask|(1<<i);
    }
    return ret;
}

void print_res(int mask)
{
    for(int i = 0;i<N;++i) if( (adj[mask]&(1<<i)) && !(mask&(1<<i)) )
    {
        printf(" %d",i+1);
        print_res(adj[mask]);
    }
}

int main()
{
    freopen("D-small-attempt1.in","r",stdin);
    freopen("D-small.out","w",stdout);

    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        int K = INPT_INT; N = INPT_INT;

        int init_key[50];
        for(int i = 0;i<K;++i) init_key[i] = INPT_INT;

        total_key = 0;
        vector<int> key_list[22];
        map<int,int> useful_keys;

        for(int i = 0;i<N;++i)
        {
            key_map[i] = INPT_INT;

            if( useful_keys.find( key_map[i] ) == useful_keys.end() )
            {
                useful_keys[ key_map[i] ] = total_key++;
            }

            int ki = INPT_INT;
            for(int j = 0;j<ki;++j) key_list[i].push_back(INPT_INT);
        }

        for(int i = 0;i<N;++i)
        {
            key_map[i] = useful_keys[ key_map[i] ];

            memset(key_inside[i],0,sizeof(key_inside[i]));
            for(int j = 0;j<key_list[i].size();++j) if( useful_keys.find( key_list[i][j] ) != useful_keys.end() )
            {
                key_inside[i][useful_keys[ key_list[i][j] ]]++;
            }
        }

        memset(adj,0,sizeof(adj));
        memset(can_unlock,-1,sizeof(can_unlock));
        memset(key_in_hand,0,sizeof(key_in_hand));

        for(int i = 0;i<K;++i) if( useful_keys.find( init_key[i] ) != useful_keys.end() )
        {
            key_in_hand[ useful_keys[init_key[i]] ]++;
        }

        printf("Case #%d:",ca);
        bool res = calc(0);
        if(res)print_res(0);
        else printf(" IMPOSSIBLE");
        puts("");
    }
    return 0;
}
