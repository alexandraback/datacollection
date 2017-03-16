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

const int MAXN = 110;

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	
	int T;	cin >> T;
	
	for(int cas = 1; cas <= T; ++ cas)
	{
		int x, y;
		cin >> x >> y;
		
		printf("Case #%d: ", cas);
		
		char a = 'W', b = 'E';
		if(x < 0)	swap(a, b), x = -x;
		while(x --)	putchar(a), putchar(b);
		
		a = 'S', b = 'N';
		if(y < 0)	swap(a, b), y = -y;
		while(y --)	putchar(a), putchar(b);
		
		puts("");
	}
	
	
	return 0;	
}
