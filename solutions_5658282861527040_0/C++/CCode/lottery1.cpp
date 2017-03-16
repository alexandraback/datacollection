#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int t,i,j,n,l,ans,minlen,ch,a,b,k,lasta,lastb,lastk;
	vector<int> a1;
	vector<int> b1;
	vector<int> k1;
	long long cnt;
	scanf("%d",&t);
	for(l=1;l<=t;l++)
	{
		cnt=0;
		scanf("%d%d%d",&a,&b,&k);
		for(i=0;i<a;i++)
		for(j=0;j<b;j++)		
		{
			if((i&j)<k)
				cnt++;
		}
		printf("Case #%d: %lld\n",l,cnt);
	}
}
