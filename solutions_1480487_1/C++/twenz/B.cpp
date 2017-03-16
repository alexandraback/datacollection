#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define N 202
int s[N];
double ans[N];
int main()
{
	//freopen("A-small-attempt1.in","r",stdin);
	//	freopen("B-large-practice.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,t,n,sum;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		sum = 0;
		for(j=0;j<n;j++){
			scanf("%d",&s[j]);
			sum += s[j];
		}
		for(j=0;j<n;j++)
			ans[j] = -1;
		int m = n;
		int ss = sum*2;
		while(true){
			for(j=0;j<n;j++)
				if(ans[j]<0 && s[j] >= ss*1.0/m)
				{
					ss -= s[j];
					m --;
					ans[j] = 0;
					break;
				}
			if(j >= n)break;
		}
		for(j=0;j<n;j++)
			if(ans[j] < 0){
				ans[j] = (ss*1.0/m-s[j])*100/sum;
			}
		printf("Case #%d:",i);
		for(j=0;j<n;j++){
			printf(" %.6lf",ans[j]);
		}
		printf("\n");
	}
	return 0;
}