#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#include<time.h>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int c,d,v;
int cover[1000];
//vector<int>coins;
void insert(int x)
{
    for (int i=1; i<=v; i++)
    {
        if (cover[i] == 1)
        {
            for (int j=1; j<=c; j++)
            {
                cover[j*x+i] = 1;
            }
        }
    }
    for (int i=1; i<=c; i++)
    {
        cover[x*i] = 1;
    }
    //coins.push_back(x);
    for (int i=1; i<=v; i++)
    {
        if (cover[i]==1)
        {
            cout<<i<<" ";
        }
    }cout<<endl<<endl;
}
int main()
{
    int i,j,k;
    int n,m,t;
    //srand((unsigned)time(NULL));//int data=rand()%10000+1;
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
    //while(scanf("%d",&n)!=EOF)
    {
        memset(cover,0,sizeof(cover));
        //coins.clear();
        scanf("%d%d%d", &c,&d,&v);
        for (i=0; i<d; i++)
        {
            int x;
            scanf("%d",&x);
            insert(x);
        }
        int ans = 0;
        for (i=1; i<=v; i++)
        {
            if (cover[i]==0)
            {
                ans++;
                insert(i);
            }
        }
        printf("Case #%d: %d\n",tcase, ans);
    }
}
