#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 30009;

int A, B;
bool vst[MAX];

int deal(int x)
{
	memset(vst, 0, sizeof(vst));
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
				if(!vst[y]) cnt ++, vst[y] = 1;						
			}	
		}
		else y /= 10;
	}
	
	return cnt;	
}

int main()
{
	
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	
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
