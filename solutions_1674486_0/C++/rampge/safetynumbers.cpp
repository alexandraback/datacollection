#include<cstdio>
#include<algorithm>

using namespace std;

int inherits[2001][10];
int m[2001];
bool poss[50][51][51];
int path_yet[2001][2001];

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);   
    
    int t,tests,i,j,n,k,base;
    scanf("%d",&tests);
    
    for(t=1;t<=tests;t++){
        memset(inherits,0,sizeof(inherits));
        memset(poss,0,sizeof(poss));
        memset(path_yet,0,sizeof(path_yet));
        
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&m[i]);
            for(j=0;j<m[i];j++){
                scanf("%d",&base);
                inherits[i][j]=base;
                poss[1][i][base]=1;
                path_yet[i][base]=1;    
            }    
        }   
        printf("Case #%d: ",t);
        for(int step=2;step<n;step++){
            for(i=1;i<=n;i++){
                for(j=0;j<m[i];j++){
                    for(k=1;k<=n;k++){
                        if( poss[step-1][inherits[i][j]][k] ){
                            poss[step][i][k]=1;
                            if(path_yet[i][k]){ 
                                printf("Yes\n");
                                goto DONE;
                            }
                            else
                                path_yet[i][k]=true;    
                        }    
                    }            
                }    
            }        
        }     
        printf("No\n");
        DONE: continue;
    }
    
    return 0;
}
