//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<climits>
#include<iostream>
#include<algorithm>
//#include<cmath>
using namespace std;
typedef long long LL;
#include<map>
#include<queue>
#define lson l, mid
#define rson (mid+1), r
#define pb push_back

int k,l,s;
char kb[55];
char mo[55];
char exp[55];

int totapp=0,totseq=0,maxb=0;

void check()
{
    totseq++;
    int cnt=0;
    for(int i=0; i+l<=s; i++)
    {
        int flag=1;
        for(int j=0; j<l; j++)
            if(exp[j]!=mo[i+j])
                flag=0;
        cnt+=flag;
    }
    totapp+=cnt;
    maxb=max(maxb,cnt);
}

void dfs(int dp)
{
    if(dp==s)
    {
        check();
        return;
    }
    for(int i=0; i<k; i++)
    {
        mo[dp]=kb[i];
        dfs(dp+1);
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &k, &l, &s);
		scanf("%s%s", kb, exp);
		printf("Case #%d: ", ca++);
		totapp=totseq=maxb=0;
		dfs(0);
		printf("%.8f\n", (double)(maxb*totseq-totapp)/totseq);

    }
    return 0;
}
