#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

#define inf (1<<29)
#define eps (1e-9)

#define flt(x,y) ((x)<(y)-eps)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<eps)

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int X, Y;

map<PII, char> dir;
map<PII, int> s;
queue<int> qx, qy;

char dd[] = {'E', 'W', 'N', 'S'};
char dx[] = {1, -1, 0, 0};
char dy[] = {0, 0, 1, -1};

vector<char> vp;
void ppath(int ss)
{
	int cx = X, cy = Y;
	vp.clear();
	while (cx != 100 || cy != 100)
	{
		char d = dir[make_pair(cx,cy)];
		vp.PB(d);
		if (d == 'E') {
			cx -= ss;
		} else 
		if (d == 'W') {
			cx += ss;
		} else 
		if (d == 'N') {
			cy -= ss;
		} else 
		if (d == 'S') {
			cy += ss;
		}
		ss--;
	}
	for (int i = vp.size()-1; i >= 0; i--)
	{
		putchar(vp[i]);
	}
}

int main()
{
	int T; scanf("%d", &T);
	int cc = 0;
	while (T--)
	{
		scanf("%d %d",&X, &Y);
		X += 100; Y += 100;
		printf ("Case #%d: ", ++cc);
		while (!qx.empty()) qx.pop();
		while (!qy.empty()) qy.pop();
		dir.clear();
		s.clear();
		qx.push(100); qy.push(100);
		s[make_pair(100,100)] = 0;
		while (!qx.empty())
		{
			int cx = qx.front(); qx.pop();
			int cy = qy.front(); qy.pop();
			int ss = s[make_pair(cx,cy)]+1;
			int flag= true;
			for (int i = 0; i < 4; i++)
			{
				int tx = cx + dx[i]*ss;
				int ty = cy + dy[i]*ss;
				PII t = make_pair(tx,ty);
				if (dir[t] == 0) {
					dir[t] = dd[i];
					s[t]=ss;
					qx.push(tx);
					qy.push(ty);
				}
				if (tx == X && ty == Y)
				{
					ppath(ss);
					flag=false;
					break;
				}
			}
			if (!flag) break;
		}
		putchar('\n');
	}
	return 0;
}
