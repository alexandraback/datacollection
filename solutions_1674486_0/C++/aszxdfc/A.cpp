#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<cmath>
using namespace std;
bool graph[1010][1010],ans[1010][1010];

int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("in.txt","w",stdout);
	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    
    int i,j,iii,k,T,n,m,len;
    scanf("%d",&T);
    for(iii=1;iii<=T;iii++) {
        scanf("%d",&n);
        printf
        printf("Case #%d: ",iii);
        memset(graph,0,sizeof(graph[0]));
        memset(ans,0,sizeof(ans[0]));
        for(i=1;i<=n;i++) {
            scanf("%d",&m);
            for(j=0;j<m;j++) {
                scanf("%d",&k);
                graph[i][k]=ans[i][k]=true;
            }
        }
        for(len=2;len<=n;len++) {
            for(i=1;i<=n;i++) {
                for(j=1;j<=n;j++) {
                    if(i==j) continue;
                    for(k=1;k<=n;k++) {
                        if(k==i||k==j) continue;
                        if(ans[i][j]==true&&graph[j][k]==true) ans[i][k]=true;
                    }
                }
            }
        }
    /*    for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(ans[i][j]) putchar('a');
                else putchar('b');
            }
            putchar('\n');
        }*/
        
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(i==j) continue;
                int ct=0;
                if(graph[i][j]) ct++;
                for(k=1;k<=n;k++) {
                    if(k==i||k==j) continue;
                    if(ans[i][k]==true&&ans[k][j]==true) ct++;
                }
                if(ct>=2) break;
            }
            if(j<=n) break;
        }
        if(i<=n) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}
