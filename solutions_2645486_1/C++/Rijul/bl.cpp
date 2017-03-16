#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define inf (1<<29)
#define maxm 101000
#define ii __int64

int on(int n,int k){
    return (n|(1<<k));
}
int off(int n,int k){
    return (n-(n&(1<<k)));
}
bool chck(int n,int k){
    return (n&(1<<k));
}

struct node{
    int ind;
    ii rem;
};


ii mini(ii a,ii b){ if(a<b) return a; return b; }
ii maxi(ii a,ii b){ if(a>b) return a; return b; }

node nodes[maxm];
ii e,r,n,lo[maxm],hi[maxm];

bool comp(node a,node b){
    return a.rem>b.rem;
}

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%I64d %I64d %I64d",&e,&r,&n);

        for(i=1;i<=n;i++){
            lo[i]=0; hi[i]=e;
            scanf("%I64d",&nodes[i].rem);
            nodes[i].ind=i;
        }
        sort(nodes+1,nodes+n+1,comp);

        ii ans=0;
        for(i=1;i<=n;i++){
            node now=nodes[i];
            j=nodes[i].ind;
			k=j;
			ii v=hi[j]-lo[j];
            ans+=(v*now.rem);
            ii curr=lo[j],curr1=hi[j];
            while(curr<e){
                hi[j]=mini(curr,hi[j]);
                j++;
                curr+=r;
				if(j>n) break;
            }

			while(curr1>=0){
				lo[k]=maxi(curr1,lo[k]);
				k--;
				curr1-=r;
				if(k<=0) break;
			}
        }

        printf("Case #%d: %I64d\n",t++,ans);


    }

    return 0;
}

