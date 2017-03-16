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
		char str[10000];
		int n;
		scanf("%s %d ",str,&n);

		string s(str);
		const int L = SZ(s);
		ll count = 0;
		for (int st = 0; st < L; st++)
		{
			for(int end=0;end<L;end++)
			{
				int renzoku = 0;
				int max_renzoku = 0;
				for(int k=st;k<=end;k++)
				{
					if(s[k]=='a'||s[k]=='i'||s[k]=='u'||s[k]=='e'||s[k]=='o')
					{
						renzoku = 0;
					}
					else
					{
						renzoku++;
						max_renzoku = max(max_renzoku,renzoku);
					}
				}

				if(max_renzoku>=n)
				{
					count++;
				}
			}
		}

		fprintf(stderr, "Case #%d: %lld\n",t+1,count);
		printf("Case #%d: %lld\n",t+1,count);
	 }

	return 0;
}