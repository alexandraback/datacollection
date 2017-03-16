#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 110
int a[MAXN];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,n,s,p,t;
	int cas = 1,i,k;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&s,&p);
		t = 0;
		for(i=k=0;i < n;i++){
			scanf("%d",&a[i]);
			switch (a[i]%3)
			{
			case 0:
				if(a[i]/3 >= p)
					t++;
				else if(a[i]/3 > 0)
					a[k++] = a[i]/3+1;
				else
					a[k++] = a[i]/3;
				break;
			case 1:
				if(a[i]/3+1 >= p)
					t++;
				else
					a[k++] = a[i]/3+1;
				break;
			case 2:
				if(a[i]/3+1 >= p)
					t++;
				else
					a[k++] = a[i]/3+2;
				break;
			}
		}
		sort(a,a+k);
		while (k-- && s--)
			if(a[k] >= p)t++;
		printf("Case #%d: %d\n",cas++,t);
	}
	return 0;
}