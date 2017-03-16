#include <iostream>
#include <algorithm>
using namespace std;
#define N 2000001
int a[8],de[6]={10,100,1000,10000,100000,1000000};
bool tag[N];
int weishu(int n){
	int num = 0;
	while(n){
		num ++;
		n = n/10;
	}
	return num;
}
int getNum(int x,int b,int n)
{
	int i,j,k=1;
	a[0] = x;
	int y = x;
	for(i=1;i<n;i++){
		y=y/10+y%10*de[n-2];
		if(y>x&&y<=b)a[k++]=y;
	}
	sort(a,a+k);
	for(i=1,j=0;i<k;i++)
		if(a[i]!=a[j])
			a[++j]=a[i];
	for(i=1;i<=j;i++)
		tag[a[i]]=true;
	return j*(j+1)/2;
}
int main()
{
//	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,t,ans,aa,b,m;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&aa,&b);
		for(j=aa;j<=b;j++)tag[j]=false;
		m = weishu(b);
		ans = 0;
		for(j=aa;j<b;j++){
			if(tag[j])continue;
			ans+=getNum(j,b,m);
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}