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
#define NG (-1)

static char str[2000000];

int main()
{
    freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		int n;
		scanf("%s %d ",str,&n);

/*
		int NUM = 100;
		for (int i = 0; i < NUM; i++)
		{
			str[i]=rand()%26+'a';
		}
		str[NUM]='\0';
		n = rand()%10;

		fprintf(stderr,"%s %d\n",str,n);
*/

		string s(str);
		const int L = SZ(s);
		ll count = 0;
		ll sum = 0;

		{
			vector <ll> conc(L+1);
			conc[L]=0;
			for (int i = L-1; i >= 0; i--)
			{
				if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o')
				{
					conc[i] = 0;
				}
				else
				{
					conc[i] = conc[i+1]+1;
				}
			}

			int k = 0;
			vector <int> next_n(L+1,NG);
			for (int i = 0; i <= L; i++)
			{
				if(conc[i]>=n)
				{
					for(;k<=i;k++)
					{
						next_n[k]=i;
					}
				}
			}

			for (int i = 0; i <= L; i++)
			{
				if(next_n[i]!=NG)
				{
					sum += (ll)L-next_n[i]-n+1;
				}
			}
		}

	/*
		{
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
		}
	*/
		fprintf(stderr, "Case #%d: %lld\n",t+1,sum);
//		fprintf(stderr, "Case #%d: %lld %lld\n",t+1,sum,count);
		printf("Case #%d: %lld\n",t+1,sum);
	 }

	return 0;
}