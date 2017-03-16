// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

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
static const double EPS = 1e-9;
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
#define PI	(3.14159265358979323846)
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG (987654321)
#define SZ(a) ((int)a.size())
typedef long long ll;

#define FOR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
// BEGIN CUT HERE
#undef FOR
#define FOR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
// END CUT HERE


#if 1
int main(){

    freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++)
	{
		int N;
		cin >> N;
		
		vector <int> a(N);
		vector <int> b(N);
		
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d",&a[i],&b[i]);
		}

		vector <int> clear(N);

		int star = 0;
		int turn = 0;
		while(1)
		{
			turn++;

			// 0 -> 2
			bool ok = false;
			for (int i = 0; i < N; i++)
			{
				if(clear[i]==0 && star>=b[i])
				{
					star += 2;
					clear[i] = 2;
					ok = true;
					break;
				}
			}

			if(!ok)
			{
				// 1 -> 2
				for (int i = 0; i < N; i++)
				{
					if(clear[i]==1 && star>=b[i])
					{
						star += 1;
						clear[i] = 2;
						ok = true;
						break;
					}
				}
			}

			if(!ok)
			{
				int max_b = NG;
				int max_i = NG;
				// 0 -> 1
				for (int i = 0; i < N; i++)
				{
					if(clear[i]==0 && star>=a[i])
					{
						if(b[i]>max_b)
						{
							max_b = b[i];
							max_i = i;
					
						}
					}
				}
				if(max_i!=NG)
				{
					star += 1;
					clear[max_i]=1;
					ok = true;
				}
			}


			if(!ok)
			{
				fprintf(stderr,"Case #%d: Too Bad\n",testcase+1);
				printf("Case #%d: Too Bad\n",testcase+1);
				break;
			}
			else if (count(clear.begin(),clear.end(),2)==N)
			{
				fprintf(stderr,"Case #%d: %d\n",testcase+1,turn);
				printf("Case #%d: %d\n",testcase+1,turn);
				break;
			}
		}
	}
}



#else
int main(){

    freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		vector <double> vd(A);
		double ret = B+2;
		for (int i = 0; i < A; i++)
		{
			scanf("%lf",&vd[i]);
			if(i>=1)
			{
				vd[i] *= vd[i-1];
			}

			int seikou  = (A+B-2*i-1);
			int shippai = seikou + (B+1);

			double prob = vd[i]*seikou + (1.0-vd[i])*shippai;
			ret = min(ret,prob);
//			fprintf(stderr,"%d %f %f %f\n",i,vd[i],prob,ret);
		}

		fprintf(stderr,"Case #%d: %.15f\n",testcase+1,ret);
		printf("Case #%d: %.15f\n",testcase+1,ret);
	}
}
#endif
