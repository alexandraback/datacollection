#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

char s[5][5];

bool win(char c) {
	for(int i=0;i<4;++i)
		if (s[i][0]!=c&&s[i][1]!=c&&s[i][2]!=c&&s[i][3]!=c&&
			s[i][0]!='.'&&s[i][1]!='.'&&s[i][2]!='.'&&s[i][3]!='.'||
			s[0][i]!=c&&s[1][i]!=c&&s[2][i]!=c&&s[3][i]!=c&&
			s[0][i]!='.'&&s[1][i]!='.'&&s[2][i]!='.'&&s[3][i]!='.') return true;
	return (s[0][0]!=c&&s[1][1]!=c&&s[2][2]!=c&&s[3][3]!=c&&
			s[0][0]!='.'&&s[1][1]!='.'&&s[2][2]!='.'&&s[3][3]!='.'||
			s[0][3]!=c&&s[1][2]!=c&&s[2][1]!=c&&s[3][0]!=c&&
			s[0][3]!='.'&&s[1][2]!='.'&&s[2][1]!='.'&&s[3][0]!='.');
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T; scanf("%d",&T);
	for(int test=1;test<=T;++test) {
		printf("Case #%d: ",test);
		for(int i=0;i<4;++i)
			scanf("%s",s[i]);
		bool free=false;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				free=free||s[i][j]=='.';
		if (win('O')) puts("X won");
		else if (win('X')) puts("O won");
		else if (free) puts("Game has not completed");
		else puts("Draw");
	}
	return 0;
}