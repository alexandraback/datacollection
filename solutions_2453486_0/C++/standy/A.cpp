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

const int MAXN = 10;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

char G[MAXN][MAXN];

bool check(char ch)
{
	int cd1 = 0, cd2 = 0;
	for(int i = 0; i < 4; ++ i)
	{
		int cr = 0, cc = 0;
		for(int j = 0; j < 4; ++ j)	
		{
			cr += G[i][j] == ch || G[i][j] == 'T';
			cc += G[j][i] == ch || G[j][i] == 'T';
		}
		if(cr == 4 || cc == 4)	return 1;
		
		cd1 += G[i][i] == ch || G[i][i] == 'T';
		cd2 += G[i][3 - i] == ch || G[i][3 - i] == 'T';
	}	
	return cd1 == 4 || cd2 == 4;
}

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int T;	cin >> T;
	
	for(int cas = 1; cas <= T; ++ cas)
	{
		bool flag = 0;
		for(int i = 0; i < 4; ++ i)
		{
			scanf("%s", G[i]);	
			for(int j = 0; j < 4; ++ j)
				if(G[i][j] == '.')
					flag = 1;
		}
		
		printf("Case #%d: ", cas);
		
		if(check('X'))	puts("X won");
		else if(check('O'))	puts("O won");
		else if(flag)	puts("Game has not completed");
		else	puts("Draw");
		
		
//		cout << "Case #" << cas << ": " << (flag ? "YES" : "NO") << endl; 
	}
	
	
	return 0;	
}
