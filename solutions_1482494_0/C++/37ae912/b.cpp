
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=1<<29;

struct Node{
    int index,val;
    bool operator < (const Node& nd)const{
        return val<nd.val;
    }
};

Node B[1010];
Node A[1010];
int n;


int test()
{
        int i,j;
        i=j=0;
        int res=0;
        int cnt=0;
        bool ok=true;

        while(j<n){
            if(res>= B[j].val){
                bool vis=false;
                for(int k=0;k<i;++k){
                    if(A[k].index==B[j].index){
                        vis=true;
                        break;
                    }
                }

                if(!vis)
                    res+=2;
                else
                    res++;

//                printf("j=%d val=%d res=%d cnt=%d\n",j,B[j].val,res,cnt);
                cnt++;
                j++;
            }
            else if(res>=A[i].val){
  //              printf("i=%d val=%d res=%d cnt=%d\n",i,A[i].val,res,cnt);
                res++;
                cnt++;
                i++;
            }
            else{
                ok=false;
                break;
            }
        }
    
    return ok? cnt : INF;    
}

int main()
{
    int cs=0,t;
    scanf("%d",&t);
    while(cs++<t){
        printf("Case #%d: ",cs);

        scanf("%d",&n);

        //A[0]=0; B[0]=0;
        for(int i=0;i<n;++i){
            scanf("%d%d",&(A[i].val),&(B[i].val) );
            A[i].index=i;
            B[i].index=i;
        }
        //sort(A,A+n);
        sort(B,B+n);
        
        int ans=INF;
        int res=1;
        for(int i=1;i<=n;++i)res*=i;
        while(res--){
            next_permutation(A,A+n); 
            int r = test();
            
            if(ans>r)ans=r;
        }
        

        if(ans!=INF)
            printf("%d\n",ans);
        else
            puts("Too Bad");
        
    }

    return 0;
}
