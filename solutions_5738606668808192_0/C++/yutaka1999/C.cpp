#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#define MX 505

using namespace std;
typedef long long int ll;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d:\n",t);
		int n,J;
		scanf("%d %d",&n,&J);//J<=2^(n/2-2) ‚É’ˆÓ
		vector <ll> ret;
		for(int i=2;i<=10;i++)
		{
			ll t=1;
			for(int j=0;j<n/2;j++) t*=(ll) i;
			t++;
			ret.push_back(t);
		}
		int sz=0;
		for(int j=0;j<J;j++)
		{
			int S=2*j+1;
			string s="1";
			for(int i=n/2-2;i>=0;i--)
			{
				if(S>>i&1) s+="1";
				else s+="0";
			}
			string t=s+s;
			printf("%s",t.c_str());
			for(int i=0;i<ret.size();i++) printf(" %lld",ret[i]);
			puts("");
		}
	}
	return 0;
}
