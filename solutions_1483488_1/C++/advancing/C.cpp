#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2000009;

int A, B;
set <int> S;

int deal(int x)
{
	S.clear();
	int y = x, cnt = 0, a = 1, e = 1;
	
	while(y >= 10) { y /= 10; a ++;  e *= 10; }
	
	y = x;
	for(int i = 0; i < a - 1; i ++)
	{
		if(y % 10)
		{ 
			y = (y % 10) * e + y / 10;
			if(y > x && y <= B)
			{  
				if(S.find(y) == S.end())  
				{
					cnt ++;    S.insert(y);	
				}						
			}	
		}
		else y /= 10;
	}
	
	return cnt;	
}

int main()
{
	
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	
	int T;    cin >> T; 
	for(int cas = 1; cas <= T; cas ++)
	{
		scanf("%d %d", &A, &B);
		
		int ans = 0;
		
		for(int x = A; x <= B; x ++)
		{
			ans += deal(x);
		}
		
		printf("Case #%d: %d\n", cas, ans);
	}
	
	//while(1);
	return 0;	
}
