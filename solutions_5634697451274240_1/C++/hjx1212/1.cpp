#include<bits/stdc++.h>
using namespace std;

char c[1000];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("0.out","w",stdout);
	int T,_,i,s;
	for(scanf("%d",&T),_=1;_<=T;_++)
	{
		scanf("%s",c);
		for(s=0,i=1;c[i];i++)
			s+=c[i]!=c[i-1];
		printf("Case #%d: %d\n",_,s+(c[i-1]=='-'));
	}
	return 0;
}