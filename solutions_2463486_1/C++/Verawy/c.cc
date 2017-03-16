#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

#define LL long long

const LL ans[40]={1L,4L,9L,121L,484L,10201L,12321L,14641L,40804L,44944L,1002001L,1234321L,4008004L,100020001L,102030201L,104060401L,121242121L,123454321L,125686521L,400080004L,404090404L,10000200001L,10221412201L,12102420121L,12345654321L,40000800004L,1000002000001L,1002003002001L,1004006004001L,1020304030201L,1022325232201L,1024348434201L,1210024200121L,1212225222121L,1214428244121L,1232346432321L,1234567654321L,4000008000004L,4004009004004L};

int find(LL a){
	int l=0,r=38;
	while (l!=r){
		int mid=(l+r)/2+1;
		if (ans[mid]<=a) l=mid;
		else r=mid-1;
	}
	return l;
}

int find1(LL a){
	int l=0,r=38;
	while (l!=r){
		int mid=(l+r)/2;
		if (ans[mid]<a) l=mid+1;
		else r=mid;
	}
	return l;
}

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T;
	LL a,b;
	scanf("%d",&T);
	for (int caseT=1;caseT<=T;caseT++){
		scanf("%lld%lld",&a,&b);
		int l=find1(a),r=find(b);
//		cout<<ans[l]<<' '<<ans[r]<<endl;
		printf("Case #%d: %d\n",caseT,r-l+1);
	}
	return 0;
}
