#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define eps 1e-7
using namespace std;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
__int64 Min(__int64 a,__int64 b) { return a<b?a:b; }

//freopen("A-small-attempt0.in","r",stdin);
//freopen("A-small-attempt0.out","w",stdout);



int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int cas,ccass=1;
	int r,c,w,t,res;
	cin>>cas;
	while(cas--)
	{
		cin>>r>>c>>w;
		t=c/w;
		if(c%w==0) ;
		else t++;
		res=t*r+w-1;
		printf("Case #%d: %d\n",ccass++,res);
	}
}
