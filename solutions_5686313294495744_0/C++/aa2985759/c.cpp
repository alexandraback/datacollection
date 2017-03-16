#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int maxn=1024;

int match[maxn];
int vis[maxn];

vector<int> edges[maxn];

int dfs(int n)
{
    int i,t;
    for(i=0;i<edges[n].size();i++)if(!vis[edges[n][i]])
    {
        int v=edges[n][i];
        vis[v]=1;
        t=match[v];
        match[v]=n;

        if(!t||dfs(t))
            return 1;
        match[v]=n;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);


    for (int ii=1;ii<=t;ii++)
    {
        for (int i=0;i<maxn;i++)
            edges[i].clear();
        memset(match, 0, sizeof(match));

        int E;
        scanf("%d",&E);

        map<string, int> m1;
        map<string, int> m2;
        
        int indx1=0,indx2=0;
        for (int i=0;i<E;i++)
        {
            char str1[100];
            char str2[100];

            scanf("%s%s", str1, str2);

            string s1=str1;
            string s2=str2;

            if (m1.find(s1)==m1.end())
                m1[s1]=++indx1;
            if (m2.find(s2)==m2.end())
                m2[s2]=++indx2;
            int i1=m1[s1];
            int i2=m2[s2];

            edges[i1].push_back(i2);
        }

        int ans=E-indx1-indx2;
        for (int i=1;i<=indx1;i++)
        {
            memset(vis,0,sizeof(vis));
            if (dfs(i))
                ans++;
        }
        printf("Case #%d: %d\n", ii, ans);
    }
}
