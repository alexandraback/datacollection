#include <iostream>
#include <map>
#include <stdio.h>
#include <set>
#include <stack>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <list>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
/**
 * @author:	Shamir14 -- Amirhossein Shapoori
 * lordamir14@gmail.com
 * ACM team: AnotherChorMangz
 * Tehran, Iran
 * Still listening to Mark Knopfler...
 * :P
 */
const int maxn = 1000;

int board[maxn][maxn], n, m;

bool Check(int x, int y){
	int i;
	bool flag = true;
	for(i = 0; i < n; i++)
		if(board[i][y] == 2) flag = false;
	if(flag) return true;
	flag = true;
	for(i = 0; i < m; i++)
		if(board[x][i] == 2) flag = false;
	return flag;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test, t, i, j;
	bool flag;

	cin >> test;
	t = 0;
	while(test--){
		cin >> n >> m;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				cin >> board[i][j];
		flag = true;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(board[i][j] == 1 && !Check(i, j)) flag = false;
		cout << "Case #" << ++t << ": ";
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}

