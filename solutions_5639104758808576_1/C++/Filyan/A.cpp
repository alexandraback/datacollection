#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string const name = "A";

int test, n, ans, cnt, curTest;
string s;

void print(int v)
{
	printf("Case #%d: %d\n",++curTest,v);
}

int main()
{
#ifdef _DEBUG
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#else
	freopen((name + ".in").c_str(),"r",stdin);
	freopen((name + ".out").c_str(),"w",stdout);
#endif

	cin >> test;
	while(test--)
	{
		cin >> n >> s;
		
		ans = 0;
		cnt = 0;
		for(int i=0;i<=n;++i)
		{
			if(cnt < i)
			{
				ans += (i - cnt);
				cnt += (i - cnt);
			}
			int cur = (int)(s[i] - 48);
			cnt += cur;
		}
		print(ans);
	}

	return 0;
}
