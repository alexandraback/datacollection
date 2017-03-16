#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long

int		A,B,a[99],mk[2000010];
LL		res;

inline void Work(int x,int L,int R){
	int t=0,s=x;
	while (s){
		a[++t]=s%10;
		s/=10;
	}
	for (int i=1,j=t;i<=j;i++,j--)
		swap(a[i],a[j]);
	for (int i=1;i<=t;i++)
		a[i+t]=a[i];
	for (int i=2;i<=t;i++)
	if (a[i]){
		int tmp=0;
		for (int j=i;j<=i+t-1;j++)
			tmp=tmp*10+a[j];
		
		if (tmp>x && tmp>=A && tmp<=B)
		if (mk[tmp]!=x){
			//printf("%d %d\n",x,tmp);
			res++;
		}
		if (tmp>=A && tmp<=B)
			mk[tmp]=x;
	}
}

int main(){
	freopen("s.in","r",stdin);
	freopen("s.out","w",stdout);
	
	int test;
	scanf("%d",&test);
	for (int t=1;t<=test;t++){
		memset(mk,0,sizeof(mk));
		printf("Case #%d: ",t);
		scanf("%d%d",&A,&B);
		res=0;
		for (int i=A;i<=B;i++)
			Work(i,A,B);
		printf("%lld\n",res);
	}
	
	
	return 0;
}
