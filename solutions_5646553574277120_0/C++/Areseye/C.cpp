#include"cstdio"
#include"iostream"
#include"map"
#include"string"
#include"cstring"
#include"vector"
#include"utility"
#include"algorithm"
#include"cmath"
#include"queue"
#include"stack"
#include"set"

using namespace std;

int can_reach[200];
int has_c[35];

int C,D,V;
int coins[200];


int dfs(int depth,int cur_val){
    if(depth==D){
        can_reach[cur_val]=1;
        return 1;
    }
    dfs(depth+1,cur_val+coins[depth]);
    dfs(depth+1,cur_val);
}
int main(){
    freopen("d:C-small-attempt1.in","r",stdin);
    freopen("d:C.out","w",stdout);
	int T;
	int casenum=0;
	cin>>T;
	while(casenum++<T){
        memset(has_c,0,sizeof(has_c));
        memset(can_reach,0,sizeof(can_reach));

        cin>>C>>D>>V;
        for(int i=0;i<D;i++){
            scanf("%d",&coins[i]);
            has_c[coins[i]]=1;
            //cout<<coins[i]<<endl;
        }


        can_reach[0]=1;
        dfs(0,0);

        bool ok=true;
        int ans=0;
        for(int i=0;i<=V;i++){
            if(can_reach[i]!=1){
                //find min Di value
                //for(int ci=1;ci<=V;ci++){
                int ci=i;
                    if(has_c[ci]==0){
                        if(i-ci>=0&&can_reach[i-ci]==1){
                            has_c[ci]=1;
                            for(int j=V;j>=0;j--){
                                if(can_reach[j]!=1){
                                    if(j-ci>=0&&can_reach[j-ci]==1){
                                        can_reach[j]=1;
                                    }
                                }
                            }
                            //printf("ci=%d\n",ci);
                            ans++;
                            //break;
                        }
                    }
                //}
            }
        }
        printf("Case #%d: %d\n",casenum,ans);
	}


return 0;}
