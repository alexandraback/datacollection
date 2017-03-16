#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		char s[110];
		int n;
		scanf("%s%d", s, &n);
		int l = strlen(s), ans = 0;
		for(int i=0; i<l; i++) for(int j=i; j<l; j++)
		{
			int cnt = 0;
			bool find = false;
			for(int k=i; k<=j; k++)
			{
				if(s[k]!='a'&&s[k]!='e'&&s[k]!='i'&&s[k]!='o'&&s[k]!='u')
					cnt++;
				else cnt = 0;
				if(cnt>=n) find = true;
			}
			if(find) ans++;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
