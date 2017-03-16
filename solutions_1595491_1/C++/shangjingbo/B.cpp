#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int best[35][2],f[105][105];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	
	memset(best,-1,sizeof(best));
	for (int a=0;a<=10;++a)
		for (int b=0;b<=10;++b)
			for (int c=0;c<=10;++c){
				bool sup=false;
				if (max(a,max(b,c))-min(a,min(b,c))>=2) sup=true;
				if (max(a,max(b,c))-min(a,min(b,c))>2) continue;
				best[a+b+c][sup]=max(best[a+b+c][sup],max(a,max(b,c)));
			}
	
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test){
		int a[105],n,s,p;
		scanf("%d%d%d",&n,&s,&p);
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
			//for (int j=0;j<2;++j) printf("%d ",best[a[i]][j]); puts("");
		}
		memset(f,-1,sizeof(f));
		f[0][0]=0;
		for (int i=0;i<n;++i){
			for (int sup=0;sup<=s;++sup)if (f[i][sup]!=-1){
				//printf("f[%d][%d]=	%d\n",i,sup,f[i][sup]);
				for (int j=0;j<2;++j)
				if (best[a[i]][j]!=-1 && sup+j<=s){
					int delta=(best[a[i]][j]>=p);
					//printf("	-->[%d][%d]	%d\n",i+1,sup+j,delta);
					f[i+1][sup+j]=max(f[i+1][sup+j],f[i][sup]+delta);
				}
			}
		}
		printf("Case #%d: %d\n",test,f[n][s]);
	}
	return 0;
}
