#include <stdio.h>
#include <set>
using namespace std;
#define N 35
char m[N][N];
int ab(int x) { return x<0?-x:x; }
int gcd(int x, int y) { return !y?x:gcd(y, x%y); }
set <int> s;
void ins(int x, int y)
{
	int g=gcd(ab(x), ab(y));
	if(g) s.insert((x/g+10000)*10000+y/g+10000);
}
int main()
{
	int r, c, i, j, k, l, t, ts, d, i1, j1;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		for(scanf("%d%d%d", &r, &c, &d), i=0; i<r; scanf("%s", m[i]), i++);
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
				if(m[i][j]=='X') break;
			if(j<c) break;
		}
		i--; j--; r-=2; c-=2;
		s.clear();
		for(k=-d/r-1; k<=d/r+1; k++)
			for(l=-d/c-1; l<=d/c+1; l++)
			{
				i1=(k-k%2)*r;
				if(k%2) i1+=k<0?-2*i-1:2*(r-i)-1;
				j1=(l-l%2)*c;
				if(l%2) j1+=l<0?-2*j-1:2*(c-j)-1;
				if(i1*i1+j1*j1<=d*d) ins(i1, j1);
			}
		printf("Case #%d: %d\n", t, s.size());
	}
	return 0;
}