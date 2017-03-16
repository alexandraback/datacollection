#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

const int MAX = 100009;

char mp[5][5];

int check(char ch)
{
	int k1, k2;
	for(int i = 0; i < 4; i ++)
	{
		k1 = 0, k2 = 0;
		while((mp[i][k1] == ch || mp[i][k1] == 'T') && k1 < 4) k1 ++;
		while((mp[k2][i] == ch || mp[k2][i] == 'T') && k2 < 4) k2 ++;
		if(k1 == 4 || k2 == 4) return 1;	
	}	
	k1 = 0, k2 = 0;
	while(mp[k1][k1] == ch || mp[k1][k1] == 'T')  k1 ++;
	while(mp[k2][3-k2] == ch || mp[k2][3-k2] == 'T') k2 ++;
	
	if(k1 == 4 || k2 == 4)  return 1;
	
	return 0;
}

int check_dot()
{
	for(int i = 0; i < 4; i ++)
	for(int j = 0; j < 4; j ++)  if(mp[i][j] == '.') return 1;
	
	return 0;		
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;    cin >> T;
	for(int cas = 1; cas <= T; cas ++)
	{
		for(int i = 0; i < 4; i ++)     scanf("%s", mp[i]);	
		
		int a = check('X');
		int b = check('O');
		int c = check_dot();
		
		string ans = "Draw";
		if(a)    ans = "X won";
		if(b)    ans = "O won";
		if(c && !a && !b)    ans = "Game has not completed";
		
		cout << "Case #" << cas << ": " << ans << endl;
	}

	
	return 0;	
}
