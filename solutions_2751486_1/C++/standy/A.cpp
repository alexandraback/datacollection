#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

const int MAXN = 1000010;

char name[MAXN];
int L, n;

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int T;	cin >> T;
	
	for(int cas = 1; cas <= T; ++ cas)
	{
		scanf("%s %d", name, &n);
		L = strlen(name);
		
		int pre = 0;
		LL ans = 0;
		for(int i = 0; i < L; ++ i)
		{
			int j = i;
			while(j < L && name[j] != 'a' && name[j] != 'e' && name[j] != 'i' && name[j] != 'o' && name[j] != 'u')	
			{
				++ j;	
			}
			
			if(j - i >= n)
			{
				while(j - pre >= n)
				{
					ans += L - max(i + n - 1, pre + n - 1);
					++ pre;	
				}
			}
			i = j;
		}
		
		cout << "Case #" << cas << ": " << ans << endl;
	}
	
	
	return 0;	
}
