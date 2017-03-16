#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
using namespace std;

int n;
char  a[5][5];

bool ver(char a1, char a2, char a3, char a4) {
	int nr1 = 0, nr2 = 0, nr3 = 0;
	if(a1 == 'X')
		++nr1;
	if(a1 == 'O')
		++nr2;
	if(a1 == 'T')
		++nr3;
	
	if(a2 == 'X')
		++nr1;
	if(a2 == 'O')
		++nr2;
	if(a2 == 'T')
		++nr3;
	
	if(a3 == 'X')
		++nr1;
	if(a3 == 'O')
		++nr2;
	if(a3 == 'T')
		++nr3;
	
	if(a4 == 'X')
		++nr1;
	if(a4 == 'O')
		++nr2;
	if(a4 == 'T')
		++nr3;
	
	if(nr1 == 4 || (nr1 == 3 && nr3 == 1)) {
		cout << "X won";
		return 1;
	}
	if(nr2 == 4 || (nr2 == 3 && nr3 == 1)) {
		cout << "O won";
		return 1;
	}
	return 0;
}

void sol(int pas) {
	int i, j;
	
	cout << "Case #"<< pas << ": ";
	
	cin.get();
	cin.getline(a[1] + 1, 5);
	cin.getline(a[2] + 1, 5);
	cin.getline(a[3] + 1, 5);
	cin.getline(a[4] + 1, 5);
	int vv = 1, nr1 = 0;
	for(i = 1; i <= 4; ++i)
		for(j = 1; j <= 4; ++j)
			if(a[i][j] ==  '.')
				nr1 = 1;
	for(i = 1; i <= 4; ++i) {
		if(ver(a[i][1], a[i][2], a[i][3], a[i][4])) {
			vv = 0;break;
		}
		
		if(ver(a[1][i], a[2][i], a[3][i], a[4][i])) {
			vv = 0;break;
	}
	}
	if(vv && ver(a[1][1], a[2][2], a[3][3], a[4][4]))
		vv = 0;
	if(vv && ver(a[1][4], a[2][3], a[3][2] , a[4][1]))
		vv = 0;
	
	if(vv) {
		if(nr1)
			cout << "Game has not completed";
		else
			cout << "Draw";
	}
	
	cout << "\n";
}

int main() {
	
	freopen("ttt", "r", stdin);
	freopen("tttt", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
		sol(i);
	return 0;
}
