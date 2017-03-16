#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 309;

int N, S, P, t[MAX];

int main()
{
	
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	int T;    cin >> T; 
	for(int cas = 1; cas <= T; cas ++)
	{
		cin >> N >> S >> P;
		for(int i = 0; i < N; i++) cin >> t[i];
		
		sort(t, t + N);
		
		int ans = 0;
		for(int i = N-1; i >= 0; i --)
		{
			int a = t[i] / 3 + (t[i] % 3 == 0 && t[i] ? 1 : t[i] % 3); 
			int b = t[i] / 3 + (t[i] % 3 > 0);
			
			if(b >= P) ans ++;
				
			else if(a >= P && S > 0) ans ++, S --;
			
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	
	//while(1);
	return 0;	
}
