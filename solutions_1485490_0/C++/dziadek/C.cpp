#include<cstdio>
#include<algorithm>
#define MAX 105
using namespace std;

int typA[MAX],typB[MAX],posA[MAX],posB[MAX],t,n,m,i,j,k,l;
long long ileA[MAX],ileB[MAX];

int main(){
    scanf("%d",&t);
    for(i=0; i<t; ++i){
	scanf("%d%d",&n,&m);
	printf("Case #%d: ",i+1);
	
	for(j=0; j<n; ++j){
	    scanf("%lld%d",&ileA[j],&typA[j]);
	    posA[typA[j]]=j;
	}
	for(j=0; j<m; ++j){
	    scanf("%lld%d",&ileB[j],&typB[j]);
	    posB[typB[j]]=j;
	}
	
	long long out=0;
	long long c;
	
	for(j=0; j<m; ++j)
	    for(k=j; k<m; ++k){
		long long t0 = ileA[0];
		long long t1 = ileA[1];
		long long t2 = ileA[2];
		long long res=0;
		
		for(l=0; l<=j; ++l)
		    if(typB[l]==typA[0]){
			res+=min(ileB[l],t0);
			c=min(ileB[l],t0);
			ileB[l]-=c;
			t0-=c;
		    }
		    if(n>1){
		for(l=j; l<=k; ++l)
		    if(typB[l]==typA[1]){
			res+=min(ileB[l],t1);
			c=min(ileB[l],t1);
			ileB[l]-=c;
			t1-=c;
		    }
}
if(n>2){		    
		for(l=k; l<m; ++l)
		    if(typB[l]==typA[2]){
			res+=min(ileB[l],t2);
			c=min(ileB[l],t2);
			ileB[l]-=c;
			t2-=c;
		    }
	}	    
		out=max(res,out);
	    }
	
	printf("%lld\n",out);
	}
    return 0;
}
