#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int T, Tidx = 1;
int A, B, ans;
int flag[2000005];
int ff[10] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
void solve(int num, int n)
{
	int tnum = num;
	int tsize = 0;
	bool do_insert;
	for(int i = 0; i < n; i++)
	{
		do_insert = true;
		if(tnum % 10 == 0)
			do_insert = false;
		tnum = (tnum % 10) * ff[n] + tnum / 10;
		if(do_insert && tnum <= B && tnum >= A && flag[tnum] == 0)
		{
			tsize++;
			flag[tnum] = 1;
			/*cout << tnum << " ";*/
		}
	}
	/*cout << tsize << endl;*/
	ans = ans + tsize * (tsize - 1) / 2;
}
int main()
{
	//freopen("e:\\C-large.in","r",stdin);
	//freopen("e:\\C-large.out","w",stdout);
	cin >> T;
	int n;
	while(T--)
	{
		memset(flag, 0, sizeof(flag));
		cin >> A >> B;
		ans = 0;
		n = 0;
		while(A >= ff[n])
			n++;
		n--;
		for(int i = A; i < B; i++)
		{
			if(flag[i])
				continue;
			if(i >= ff[n + 1])
				n++;
			solve(i, n);
		}
		cout << "Case #" << Tidx++ << ": " << ans << endl;
	}
	return 0;
}
