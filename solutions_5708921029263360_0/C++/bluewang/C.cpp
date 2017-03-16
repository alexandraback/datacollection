#include <bits/stdc++.h>
using namespace std;
int a[10],b[10],c[10];
int main()
{
	int J,p,s,kk;
	int T,ca=0;
	freopen("inc.txt","r",stdin);
	freopen("outc.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&J,&p,&s,&kk);
		printf("Case #%d: ", ++ca);
		if (kk>=s){
			printf("%d\n", J*p*s);
			for (int i=1;i<=J;i++)
			for (int j=1;j<=p;j++)
			for (int k=1;k<=s;k++)
				printf("%d %d %d\n", i,j,k);
		}
		else{
			int aa;
			int ans=0;
			for (int i=1;i<(1<<(J*p*s));i++){
				memset(a,0,sizeof a);
				memset(b,0,sizeof b);
				memset(c,0,sizeof c);
				int flag=0;
					for (int j=0;j<J*p*s;j++)
						if (i&(1<<j)) flag++;
				if (ans==J*p*kk) break;
				if (flag<J*p*kk) continue;
				flag=1;
				for (int je=0;je<J;je++)
					for (int pa=0;pa<p;pa++)
						for (int sh=0;sh<s;sh++)
							if (i&(1<<(je*p*s+pa*s+sh))){
								a[je*s+sh]++;
								b[je*p+pa]++;
								c[pa*s+sh]++;
							}
				for (int j=0;j<10;j++)
					if (a[j]>kk||b[j]>kk||c[j]>kk)
						flag=0;
				if (flag){
					flag=0;
					for (int j=0;j<J*p*s;j++)
						if (i&(1<<j)) flag++;
					if (flag>ans) {ans=flag;aa=i;}			
				}
			}

			printf("%d\n",ans );
			for (int j=0;j<J*p*s;j++)
				if (aa&1<<j)	printf("%d %d %d\n", j/s/p+1,j/s%p+1,j%s+1);
		}
	}
}