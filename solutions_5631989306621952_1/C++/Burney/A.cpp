#include<cstdio>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;
char S[1001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int testcount;scanf("%d",&testcount);
	while(testcount--)
	{
		scanf("%s",S);
		string ans="";
		for(int i=0;S[i];i++)ans=max(S[i]+ans,ans+S[i]);
		static int kase=0;
		printf("Case #%d: %s\n",++kase,ans.c_str());
	}
	return 0;
}
