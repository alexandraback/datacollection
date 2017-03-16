// I may use the MPIR library. Its website is this,
// http://www.mpir.org/

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-6;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())


int main()
{
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		int x,y;
		scanf("%d %d ",&x,&y);

		int turn=1;
		int sum = 0;
		for(turn=1;;turn++)
		{
			sum += turn;
			if(sum>=abs(x)+abs(y) && (sum%2==(abs(x)+abs(y))%2))
			{
				break;
			}
		}

		int nx=x,ny=y;
		string s;
		for (int k = turn; k >= 1; k--)
		{
			if(abs(x)>abs(y))
			{
				if(x>0)
				{
					x -= k;
					s += "E";
				}
				else
				{
					x += k;
					s += "W";
				}
			}
			else
			{
				if(y>0)
				{
					y -= k;
					s += "N";
				}
				else
				{
					y += k;
					s += "S";
				}
			}
		}
		
		reverse(s.begin(),s.end());

		fprintf(stderr, "Case #%d: %s\n",t+1,s.c_str());
		printf("Case #%d: %s\n",t+1,s.c_str());
	}

	return 0;
}