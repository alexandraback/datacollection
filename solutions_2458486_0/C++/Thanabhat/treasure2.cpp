/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

int k,n;
int cur_key[256];
int key_open[256];
int key_in_n[256];
int key_in[256][512];

int max_key_num=0;

int sollist[1<<20];
int sollist_sol[1<<20];
bool canWin[1<<20];

int solve(int cc)
{
    max_key_num=0;

    scanf("%d %d",&k,&n);
    for(int i=0;i<256;i++)
        cur_key[i]=0;
    for(int i=0;i<k;i++)
    {
        int in;
        scanf("%d",&in);
        cur_key[in-1]++;
        max_key_num=max(max_key_num,in);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&key_open[i]);
        max_key_num=max(max_key_num,key_open[i]);
        key_open[i]--;
        scanf("%d",&key_in_n[i]);
        for(int j=0;j<key_in_n[i];j++)
        {
            scanf("%d",&key_in[i][j]);
            max_key_num=max(max_key_num,key_in[i][j]);
            key_in[i][j]--;
        }
    }

    int s1n=1<<n;
    for(int i=0;i<s1n;i++)
        sollist[i]=-1;
    sollist[0]=-2;
    for(int i=0;i<s1n;i++)
        canWin[i]=false;
    canWin[0]=true;

    int perm[32];
    int key_check[64];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
            perm[j]=0;
        for(int j=0;j<i;j++)
            perm[j]=1;
        next_permutation(perm,perm+n);
        do{

//            for(int i=0;i<n;i++)
//                printf("%d ",perm[i]);
//            printf(" : ");

            for(int i=0;i<max_key_num;i++)
                key_check[i]=cur_key[i];
//            for(int i=0;i<max_key_num;i++)
//                printf("_%d",key_check[i]);
//            printf("\n");

            for(int i=0;i<n;i++)
            {
                if(!perm[i])
                {
                    for(int j=0;j<key_in_n[i];j++)
                    {
                        key_check[key_in[i][j]]++;
                    }
                    key_check[key_open[i]]--;
                }
            }
//            for(int i=0;i<max_key_num;i++)
//                printf("_%d",key_check[i]);
//            printf("\n");

            int tmp=0;
            for(int i=0;i<n;i++)
                tmp|=(perm[i]<<i);

//            printf("YYYYYYYYYY (%d) ",tmp);

            for(int i=0;i<n;i++)
            {
                if(perm[i]&&canWin[tmp&(~(1<<i))]&&key_check[key_open[i]]>0)
                {
                    canWin[tmp]=true;
                    sollist[tmp]=tmp&(~(1<<i));
                    sollist_sol[tmp]=i;
                    break;
                }
            }

//            printf("YYYYYYYYY %d (%d)\n",sollist_sol[tmp],sollist[tmp]);

        }while(next_permutation(perm,perm+n));
    }


    printf("Case #%d: ",cc);
    if(canWin[s1n-1])
    {
        int pp=s1n-1;
        while(pp!=0)
        {
            printf("%d ",sollist_sol[pp]+1);
            pp=sollist[pp];
        }
        printf("\n");
    }else
    {
        printf("IMPOSSIBLE\n");
    }
    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);

	return 0;
}
