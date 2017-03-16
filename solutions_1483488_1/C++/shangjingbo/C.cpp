#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a[2000005];

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	
	for (int x=1;x<=2000000;++x){
		a[x].clear();
		char s[10];
		sprintf(s,"%d",x);
		int len=strlen(s),pw=1;
		for (int i=1;i<len;++i) pw*=10;
		int cur=x;
		for (int i=0;i<len;++i){
			cur=(cur-(s[i]-'0')*pw)*10+s[i]-'0';
			if (cur>=pw && cur<x){
				a[x].push_back(cur);
			}
		}
		sort(a[x].begin(),a[x].end());
		a[x].erase(unique(a[x].begin(),a[x].end()),a[x].end());
		/*if (10<=x && x<=20){
			printf("x=	%d	len=	%d:	",x,len);
			for (int i=0;i<a[x].size();++i)
				printf(" %d",a[x][i]);
			puts("");
		}*/
	}
	
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test){
		int A,B;
		scanf("%d%d",&A,&B);
		int ans=0;
		for (int i=A;i<=B;++i){
			ans+=upper_bound(a[i].begin(),a[i].end(),B)-lower_bound(a[i].begin(),a[i].end(),A);
		}
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
