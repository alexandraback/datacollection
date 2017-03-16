#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<map>
using namespace std;

bool m[1010][1010];
bool have_path[1010][1010];

int n,N;
bool ans;

void dfs(int s,int p)
{
    if(ans)
        return;
    
    for(int i=1;i<=n;i++)
    {
        if(p==i || m[p][i]==false)
            continue;
       // printf("\n%d    %d %d",s,p,i);
        if(m[p][i]==true && have_path[s][i]!=false)
            ans = true;
        else if(m[p][i]==true && have_path[s][i]==false)
        {
            
            have_path[s][i]=true;
            dfs(s,i);
        }
    }   
    return;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A_out.txt", "w", stdout);

    scanf("%d\n",&N);

    for(int Case=1; Case<=N; Case++){

        printf("Case #%d:",Case);

        scanf("%d",&n);
        
        memset(have_path,false,sizeof(have_path));
        memset(m,false,sizeof(m));
        
        ans = false;
        
        for(int i=1;i<=n;i++)
        {
            int x,temp;
            scanf("%d",&x);
            
            for(int j=0;j<x;j++)
            {
                scanf("%d",&temp);
                m[i][temp] = true;
            }
        }
        
        for(int i=1;i<=n;i++)
            dfs(i,i);
            
        if(ans)
            printf(" Yes");
        else
            printf(" No");
        printf("\n");
    }

    return 0;
}

