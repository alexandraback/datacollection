#include<stdio.h>
#include<string.h>

#define maxm 1<<11
#define inf 1<<25
#define ii int

int on(int n,int k){
    return n|(1<<k);
}
bool chck(int n,int k){
    return ((1<<k)==(n&(1<<k)));
}
int dp[maxm][maxm],a[1200],b[1200],n;
int cal(int mask1,int mask2,int star);
int mini(int a,int b){
    if(a<b) return a;
    return b;
}

int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&test);


	while(test--){

	    scanf("%d",&n);

	    for(i=0;i<n;i++){
	        scanf("%d %d",&a[i],&b[i]);
	    }
	    memset(dp,-1,sizeof(dp));
	    int ans=cal(0,0,0);
	    if(ans>=inf){
	        printf("Case #%d: Too Bad\n",t++);
	    }
	    else printf("Case #%d: %d\n",t++,ans);

	}

	return 0;
}

int cal(int mask1,int mask2,int star){

    if(mask2==(1<<n)-1){
        return 0;
    }
    if(dp[mask1][mask2]!=-1) return dp[mask1][mask2];

    int ret=inf,i,j,k,l;

    for(i=0;i<n;i++){
        if(chck(mask2,i)||chck(mask1,i)||a[i]>star) continue;
        k=on(mask1,i);
        ret=mini(ret,cal(k,mask2,star+1)+1);
    }

    for(i=0;i<n;i++){
        if(chck(mask2,i)||b[i]>star) continue;
        k=on(mask2,i);
        if(chck(mask1,i)) l=1;
        else l=2;
        ret=mini(ret,cal(mask1,k,star+l)+1);
    }
    return dp[mask1][mask2]=ret;

}
