#include<bits/stdc++.h>
using namespace std;

bool f[12];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("0.out","w",stdout);
	int T,_,n,x,y,z,c;
	for(scanf("%d",&T),_=1;_<=T;_++)
	{
		scanf("%d",&n);
		printf("Case #%d: ",_);
		if(!n)
		{
			puts("INSOMNIA");
			continue;
		}
		for(memset(f,0,sizeof(f)),c=0,x=n;c<10;x+=n)
			for(y=x;y;y/=10)
				if(!f[z=y%10])
					f[z]=1,c++;
		printf("%d\n",x-n);
	}
	return 0;
}