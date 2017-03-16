#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define N 1000050
int w[N];
int add[N];
int main()
{
	int T,n,a;
	int cse=0;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
	scanf("%d%d",&a,&n);
for(int i=0;i<n;i++)	scanf("%d",&w[i]);
sort(w,w+n);
memset(add,0,sizeof(add));
int tp;
//add
tp=a;
for(int i=0;i<n;i++)
	if(tp>w[i]){
		tp+=w[i];
		continue;
	}
	else
	{
		if(tp==1){
		add[i]=1;
		continue;
		}
		tp+=tp-1;
		add[i]++;
		i--;
	}
	for(int i=1;i<n;i++)
		add[i]+=add[i-1];
	int minx;
	minx=add[n-1];
	for(int i=n-1;i>=1;i--)
	{
		if(add[i-1]+n-i<minx)minx=add[i-1]+n-i;
	}
		if(n<minx)minx=n;
	printf("Case #%d: ",++cse);	
	printf("%d\n",minx);

	}

	return 0;
}
/*
100
2 3
4 5 6
2 1
4

4
2 2
2 1
2 4
2 1 1 6
10 4
25 20 9 100
1 4
1 1 1 1

*/