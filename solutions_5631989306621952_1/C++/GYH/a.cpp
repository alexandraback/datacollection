#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
char s[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("ansA.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%s",s);
		int n = strlen(s);
		string ss = "";
		stringstream str;
		str << s[0];
		ss += str.str();
		for(int i=1;i<n;++i)
		{
			stringstream str;
			str << s[i];
			if(s[i] >= ss[0])
			{
				ss = str.str() + ss;
			}
			else
				ss = ss + str.str();
		}
		printf("Case #%d: %s\n",z,ss.c_str());
	}
	return 0;
}
