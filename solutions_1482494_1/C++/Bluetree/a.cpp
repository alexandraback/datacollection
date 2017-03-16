#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


#define oo 10005
int p,n,m,cnt,star,tot,Test;
bool flag;
int a[oo],b[oo],v[oo];

int main()
{
	freopen("input.txt","r",stdin);
	
	scanf("%d",&Test);
	for (int t=1;t<=Test;++t){
		scanf("%d",&n);
		for (int i=1;i<=n;++i){
			scanf("%d%d",&a[i],&b[i]);
			v[i]=0;
		}
		
		cnt=star=tot=0;
		for (;cnt<=n;){
			flag=0;
			for (int i=1;i<=n;++i)
			if (v[i]==0 && star>=b[i]){
				v[i]=2;
				star+=2;
				++cnt;
				++tot;
				flag=1;
				break;
			}
			if (flag) continue;
			for (int i=1;i<=n;++i)
			if (v[i]==1 && star>=b[i]){
				v[i]=3;
				++star;
				++cnt;
				++tot;
				flag=1;
				break;
			}
			if (flag) continue;
			p=0;
			for (int i=1;i<=n;++i)
			if (v[i]==0 && star>=a[i])
			if (!p || b[i]>b[p]) p=i;
			
			if (!p) break;
			else{
				++star;
				++tot;
				v[p]=1;
			}
		}
		
		if (cnt<n) printf("Case #%d: Too Bad\n",t);
		else printf("Case #%d: %d\n",t,tot);
	}
	
	return 0;
}
