#include <string>
#include <set>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		char buffer[100];
		int ret = 0;
		for (int n=A;n<=B;++n)
		{
			string u = itoa(n, buffer, 10);
			set<int> tmp;
			for (int q=1;q<u.length();++q)
			{
				string v = u.substr( u.length() - q , q ) + u.substr( 0, u.length() - q );
				if (v[0]=='0') continue;
				int m = atoi(v.c_str());
				if (n<m && m<=B && tmp.find(m) == tmp.end()) 
				{
					tmp.insert(m);
					ret++;
				}
			}
		}
		printf("Case #%d: %d\n",kase,ret);
	}	
	return 0;
}