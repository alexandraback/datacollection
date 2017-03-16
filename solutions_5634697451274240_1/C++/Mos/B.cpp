#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>

using namespace std;

#define FOR(x,N) for(int x = 0 ; x < (N) ; x++ )

int main()
{
	long long T;
	char buf[1000000];
	freopen("in2.in", "rt", stdin);
	freopen("out2", "wt", stdout);

	cin >> T;
	string s;
	set<int> num;
	FOR(i, T)
	{
		cin >> buf;
		s = buf;
		char temp;
		int cnt=0;
		FOR(j, s.length()-1)
		{
			temp = s[j];
			if (j == 0)
			{
				cnt++;
			}

			if (s[j] != s[j + 1])
			{
				cnt++;
			}
		}
		if (s[s.length() - 1] == '+')
		{
			cnt--;
		}

		if (s.length() == 1)
		{
			if (s[0] == '+')
				cnt = 0;
			else
				cnt = 1;
		}

		cout << "Case #" << i + 1 << ": " << cnt << endl;
		


	}
}