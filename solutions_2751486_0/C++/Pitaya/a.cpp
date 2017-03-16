#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1000100];
bool v[150];
bool co[1000100];
int pos[1000100];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	v['a']=true;
	v['e']=true;
	v['i']=true;
	v['o']=true;
	v['u']=true;
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ++ii)
	{
		memset(s,0,sizeof(s));
		memset(pos,0,sizeof(pos));
		memset(co,0,sizeof(co));
		int n,l=0;
		char ch=getchar();
		ch=getchar();
		while(ch!=' ')
		{
			s[l++]=ch;
			ch=getchar();
		}
		scanf("%d", &n);
		int tc=0;
		for (int i = 0; i < l; ++i)
		{
			if(v[s[i]])
			{
				tc=0;
			}
			else
			{
				tc++;
				if(tc>=n)
					co[i]=true;
			}
			//printf("%d\n", tc);
		}
		for (int i = l; i >= l-n+1; --i)
		{
			pos[i]=l;
		}
		for (int i = l-n; i >= 0; --i)
		{
			if(co[i+n-1])
				pos[i]=i+n-1;
			else
				pos[i]=pos[i+1];
		}
		long long ans=0;
		for (int i = 0; i <= l-n; ++i)
		{
			ans=ans+l-pos[i];
		}


		/*for (int i = 0; i < l; ++i)
		{
			printf("%d ", co[i]);
		}
		printf("\n");

		for (int i = 0; i < l; ++i)
		{
			printf("%d ", pos[i]);
		}
		printf("\n");
*/

		printf("Case #%d: %I64d\n", ii, ans);
	}
	return 0;
}