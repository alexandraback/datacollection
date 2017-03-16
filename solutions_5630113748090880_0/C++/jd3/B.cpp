#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>

#define ll long long
#define endl '\n'
#define INF 1000000000

using namespace std;

int cnt[3000];

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	int T;
	cin >> T;
	for(int t = 1 ; t <= T ; t++)
	{
		memset(cnt,0,sizeof(cnt));
		
		int a;
		int n;
		cin >> n;
		for(int i = 1 ; i < n*2 ; i++)
			for(int i = 0 ; i < n ; i++)
			{
				cin >> a;
				cnt[a]++;
			}
		
		cout << "Case #" << t << ": ";
		for(int i = 1 ; i < 2550 ; i++)
			if(cnt[i]&1)
				cout << i << " ";
		cout << endl;
	}
	
	return 0;
}


