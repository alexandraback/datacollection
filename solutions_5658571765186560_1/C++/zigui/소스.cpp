#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

typedef long long ll;

char D[10005];

int DB[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2,-1, 4,-3},
	{0, 3,-4,-1, 2},
	{0, 4, 3,-2,-1}
};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		string ans;
		int X, R, C;
		scanf("%d%d%d", &X, &R, &C);
		if( R < C ) swap(R, C);
		if( X >= 7 ) ans = "RICHARD";
		else if( R*C % X != 0 ) ans = "RICHARD";
		else if( X == 1 || X == 2 ) ans = "GABRIEL";
		else if( X == 3 && C > 1 ) ans = "GABRIEL";
		else if( X == 3 ) ans = "RICHARD";
		else if( X == 4 && C <= 2 ) ans = "RICHARD";
		else if( X == 4 ) ans = "GABRIEL";
		else if( X == 5 && C <= 3 ) ans = "RICHARD";
		else if( X == 5 ) ans = "GABRIEL";
		else if( X == 6 && R < 6 ) ans = "RICHARD";
		else if( X == 6 && C <= 3 ) ans = "RICHARD";
		else if( X == 6 ) ans = "GABRIEL";
		else ans = "ERROR!!!!!!!\n";
		printf("Case #%d: %s\n", t, ans.c_str());
	}
	return 0;
}