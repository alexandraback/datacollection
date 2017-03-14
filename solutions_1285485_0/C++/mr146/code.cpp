#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;


char s[146][146];
int h, w;
set<pair<int, int> > st;


int getx(int x, int n)
{
	return x + (n / 2) * 2 * h + (n % 2) * 2 * (h - x);
}


int gety(int y, int n)
{
	return y + (n / 2) * 2 * w + (n % 2) * 2 * (w - y);
}


int getDist(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}


int gcd(int a, int b)
{
	while(a * b != 0)
		if(a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}


void solve(int test)
{
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);
	int x = 0;
	int y = 0;
	d *= 2;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'X')
			{
				x = 2 * i - 1;
				y = 2 * j - 1;
			}
	h = 2 * n - 4;
	w = 2 * m - 4;
	//printf("%d %d %d %d\n", x, y, h, w);
	int initx = getx(x, 500);
	int inity = gety(y, 500);
	while(!st.empty())
		st.erase(st.begin());
	int ans = 0;
	for(int i = 0; i < 1000; i++)
		for(int j = 0; j < 1000; j++)
		{
			int dx = initx - getx(x, i);
			int dy = inity - gety(y, j);
			int qxx = gcd(abs(dx), abs(dy));
			if(dx * dx + dy * dy <= d * d && (dx != 0 || dy != 0))
				st.insert(make_pair(dx / qxx, dy / qxx));  
		}
	printf("Case #%d: %d\n", test + 1, st.size());
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i);
}