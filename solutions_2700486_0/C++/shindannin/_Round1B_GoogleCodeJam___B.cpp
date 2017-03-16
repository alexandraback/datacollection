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
#include "../mpir/mpir.h"
using namespace std;

typedef long long ll;

static const double EPS = 1e-6;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())
#define NG	(987654321)


int main()
{
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int C;
	scanf("%d ",&C);

	for (int c=0;c<C;c++)
	{
		int N,X,Y;
		scanf("%d %d %d ",&N,&X,&Y);

		int tomaru = 0;
		for (int i = 0; i < (1<<N); i++)
		{
			set < pair <int, int> > st;
			for (int k = 0; k < N; k++)
			{
				int x=0,y=20;
				for (int turn = 0; turn < 1000; turn++)
				{
					if(y==0) break;
					int down  = st.count(make_pair(x,y-2));
					int left  = st.count(make_pair(x-1,y-1));
					int right = st.count(make_pair(x+1,y-1));

					if( down )
					{
						if(left && right)
						{
							break;
						}
						else if (left)
						{
							x++;
							y--;
						}
						else if (right)
						{
							x--;
							y--;
						}
						else
						{
							if(i & (1<<k))
							{
								x++;
								y--;
							}
							else
							{
								x--;
								y--;
							}
						}
					}
					else
					{
						if(left && right)
						{
							break;
						}
						else if (left)
						{
							x++;
							y--;
						}
						else if (right)
						{
							x--;
							y--;
						}
						else
						{
							y-=2;
						}
					}
				}


				st.insert(make_pair(x,y));
			}

			if(st.count(make_pair(X,Y)))
			{
				tomaru++;
			}
		}

		double prob = (double)tomaru/(1<<N);


		{
			fprintf(stderr,"Case #%d: %.16f\n",c+1,prob);
			printf("Case #%d: %.16f",c+1,prob);
		}

		printf("\n");

	 }
	return 0;
}
