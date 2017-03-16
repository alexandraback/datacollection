#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
long long int e;
long long int r;
long long int v[111111];
long long int calc(int st,long long int now,int en,long long int last){
	if(st>en)return 0;

	int p=-1;
	for(int i=st; i<=en; i++)
		if(p==-1 || v[i]>v[p])
			p=i;

	long long int lef=max(last-(en-p)*r,0LL);
	long long int up=min((p-st)*r+now,e+0LL);
	return calc(st,now,p-1,max(up-r,0LL))+(up-lef)*v[p]+calc(p+1,min(lef+r,e+0LL),en,last);
}
int main(){
	int _,t;
	scanf("%d",&_);
	for(t=1; t<=_; t++){
		scanf("%I64d%I64d%d",&e,&r,&n);
		for(int i=0; i<n; i++)
			scanf("%I64d",&v[i]);
		printf("Case #%d: %I64d\n",t,calc(0,e,n-1,0));
		fprintf(stderr,"%d\n",t);
	}
	return 0;
}