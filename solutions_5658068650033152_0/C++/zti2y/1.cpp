#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;

int main()  
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int T;
	int n,m,k,index;
	scanf("%d",&T);
	for(int rr=1;rr<=T;rr++)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(n>m)
		{
			index=n;
			n=m;
			m=index;
		}
		if(n<=2)
			printf("Case #%d: %d\n",rr,k);
		else if(n==3)
			if(k<5)
				printf("Case #%d: %d\n",rr,k);
			else if(k<8||m==3)
				printf("Case #%d: %d\n",rr,k-1);
			else if(k<11||m==4)
				printf("Case #%d: %d\n",rr,k-2);
			else if(k<14||m==5)
				printf("Case #%d: %d\n",rr,k-3);
			else
				printf("Case #%d: %d\n",rr,k-4);
		else
			if(k<5)
				printf("Case #%d: %d\n",rr,k);
			else if(k<8)
				printf("Case #%d: %d\n",rr,k-1);
			else if(k<10)
				printf("Case #%d: %d\n",rr,k-2);
			else if(k<12)
				printf("Case #%d: %d\n",rr,k-3);
			else if(k<14||m==4)
				printf("Case #%d: %d\n",rr,k-4);
			else if(k<16)
				printf("Case #%d: %d\n",rr,k-5);
			else
				printf("Case #%d: %d\n",rr,k-6);
	}
	return 0;
}