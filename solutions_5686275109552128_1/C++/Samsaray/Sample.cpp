#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int d,p[1010],a;

int main()
{
	freopen("B-large.in","rb",stdin);
	freopen("test.out","wb",stdout);
	int T;scanf("%d",&T);
	for(int cas = 1; cas <= T; ++cas){
		scanf("%d",&d);
		memset(p,0,sizeof p);
		int ans = 1000, res;
		for(int i=0;i<d;++i) scanf("%d",&p[i]),res = max(res,p[i]);
		for(int i=res;i>=1;--i){
			res = 0;
			for(int j = 0;j<d;++j)
				if(p[j] > i) res += (p[j]+i-1)/i - 1;
			ans = min(ans,res + i);
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}
