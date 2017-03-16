#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

pair <int, int> p[MAXN];
bool vst[MAXN];
int N;

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int T;	cin >> T;
	for(int cas = 1; cas <= T; ++ cas)
	{
		cin >> N;
		for(int i = 0; i < N; ++ i)
		{
			cin >> p[i].second >> p[i].first;	
		}	
		sort(p, p + N);
		memset(vst, 0, sizeof(vst));
		int ans = 0, sum = 0;
		for(int i = 0; i < N; ++ i)
		{
//			cout << "--i  " << i << " " << sum << " " << p[i].first << " " << vst[i] << endl;
			if(sum >= p[i].first)	++ ans, sum += 1 + (!vst[i]);
			else
			{
				bool flag = 0;
				for(int j = N - 1; j >= i; -- j)
					if(!vst[j] && sum >= p[j].second)
					{
						++ ans;
						++ sum;
						flag = 1;
						vst[j] = 1;
						break;
					}
				if(!flag)	
				{
					ans = -1;
					break;	
				}
				-- i;		
			}		
		}
		printf("Case #%d: ", cas);
		if(ans == -1)	cout << "Too Bad" << endl;
		else	cout << ans << endl;
	}
	
	
	return 0;	
}
