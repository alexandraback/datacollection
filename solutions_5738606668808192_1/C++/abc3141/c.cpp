#include<iostream>
#include<cstdio>
using namespace std;
int N=32;int J=500;
int ans[50];
int main()
{
	printf("Case #%d:\n",1);
	for(int i=0;i<J;i++){
		ans[0]=1;ans[N-1]=1;
		int I=i;
		int n=(N-2)>>1;
		for(int j=0;j<n;j++){
			ans[2*j+1]=(i>>j)&1;
			ans[2*j+2]=ans[2*j+1];
		}
		for(int j=N-1;j>=0;j--)printf("%d",ans[j]);
		for(int j=2;j<=10;j++)printf(" %d",j+1);
		printf("\n");
	}
	return 0;
}
