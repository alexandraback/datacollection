#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<iostream>
using namespace std;
#define eps 1e-9
int a[210],n;
double b[210];
bool solve(double mid,double sum,int k)
{
	double ans=a[k]+sum*mid/100;
	//printf("%lf %lf\n",ans,mid);
	double last=100-mid;
	for(int i=0;i<n;i++){
		//printf("%d %d\n",i,k);
		if(i==k)
			continue;
		if(a[i]<ans){
			if(last>((ans-a[i])*100/sum)){
				//printf("%lf\n",(ans-a[i])*100/sum);
				last-=(ans-a[i])*100/sum;
			}
			else
				return true;
		}
	}
	return false;
}
int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	int ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		//printf("%d\n",a[1]);
		for(int i=0;i<n;i++){
			double left=0,right=100,mid;
			while(right-left>eps){
				mid=(left+right)/2;
				if(solve(mid,sum,i))
					right=mid;
				else
					left=mid;
			}
			b[i]=(left+right)/2;
		}
		printf("Case #%d:",ri++);
		for(int i=0;i<n;i++)
			printf(" %.8lf",b[i]);
		printf("\n");
	}
	return 0;
}
