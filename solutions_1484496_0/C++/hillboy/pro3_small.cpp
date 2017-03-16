#include<stdio.h>
#include<map>
using namespace std;
int h[30];

map<int,int> p;

int i,j,n,m;

int q[30];

int ansa,ansb;

bool dfs(int a,int sum,int now){
        if(a==n){
        if(sum){
                if(p.find(sum)!=p.end()){
                        ansa=p[sum];
                        ansb=now;
                        return 1;
                }
                p[sum]=now;

        }
        return 0;
        }
        if(dfs(a+1,sum,now))
                return 1;
        if(dfs(a+1,sum+q[a],now|h[a]))
                return 1;
        return 0;
}

int main(){
        int nn,ii;
        scanf("%d",&nn);
        h[0]=1;
        for(i=1;i<30;i++)
                h[i]=h[i-1]*2;
        
        for(ii=1;ii<=nn;ii++){
                printf("Case #%d:\n",ii);
                scanf("%d",&n);
                for(i=0;i<n;i++)
                        scanf("%d",&q[i]);
                p.clear();
                if(!dfs(0,0,0))
                        printf("Impossible\n");
                else{
                        // printf("%d %d\n",ansa,ansb);
                        for(i=0;i<n;i++){
                                if(h[i]&ansa)
                                        if(!(h[i]&ansb)){
                                                printf("%d ",q[i]);
                                        }
                        }
                        printf("\n");
                        for(i=0;i<n;i++){
                                if(h[i]&ansb)
                                        if(!(h[i]&ansa)){
                                                printf("%d ",q[i]);
                                        }
                        }
                        printf("\n");
                }
        }
        return 0;
}
