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
#include "mpir.h"
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
#if 1
	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++)
	{
		ll r,t;
		cin >> r >> t;

		ll lo = 0;
		ll hi = (ll)9e18;

		mpz_t mplo,mphi,mpt,mpr,mpmid,mpleft,mpright;
		mpz_init(mplo);
		mpz_init(mphi);
		mpz_init(mpt);
		mpz_init(mpr);
		mpz_init(mpmid);
		mpz_init(mpleft);
		mpz_init(mpright);

		mpz_set_ui(mplo,lo);
		mpz_set_ui(mphi,hi);
		mpz_set_ui(mpr,r);
		mpz_set_ui(mpt,t);

		while(mpz_cmp(mplo,mphi)<0)
		{
			// mpmid = mplo+(mphi-mplo+1)/2LL; // +1 is necessary, otherwise infinite loop when only two elements.
			mpz_sub(mpmid,mphi,mplo);
			mpz_add_ui(mpmid,mpmid,1);
			mpz_cdiv_q_ui(mpmid,mpmid,2);
			mpz_add(mpmid,mplo,mpmid);


			bool ok = false;

			//			if(2*mpmid*mpmid-mpmid<=mpt-2ll*mpmid*mpr)
			mpz_mul(mpleft,mpmid,mpmid);
			mpz_mul_ui(mpleft,mpleft,2);
			mpz_sub(mpleft,mpleft,mpmid);

			mpz_mul(mpright,mpmid,mpr);
			mpz_mul_ui(mpright,mpright,2);
			mpz_sub(mpright,mpt,mpright);

			if(mpz_cmp(mpleft,mpright)<=0)
			{
				ok = true;
			}

			if(!ok)
			{
//				mphi=mpmid-1;
				mpz_sub_ui(mphi,mpmid,1);
			}
			else
			{
//				mplo=mpmid;
				mpz_add_ui(mplo,mpmid,0);
			}

		}

		printf("Case #%d: ",testcase+1);
		mpz_out_str(stdout,10,mplo);
		printf("\n");

	}

#else

	 int TC;
	 scanf("%d ",&C);

	 for (int c=0;c<C;c++)
	 {
		int N;
		scanf("%d ",&N);

		vector <string> vs;
		for (int n=0;n<N;n++)
		{
			char str[1024];
			memset(str,0,sizeof(str));
			scanf("%s ",str);
			vs.push_back(str);
		}

		// 重複除去とソート
		sort(vs.begin(), vs.end());
		vs.resize(unique(vs.begin(),vs.end())-vs.begin());
		N = SZ(vs); // 長さも変わります

		mpz_t ls[MAX_N];
		for(int i=0;i<N;i++)
		{
			mpz_init(ls[i]);
		}

		for (int n=0;n<N;n++)
		{
			mpz_set_str(ls[n],(char*)vs[n].c_str(),10);
		}

		mpz_t zero;
		mpz_t ret;
		mpz_init(zero);
		mpz_init(ret);
		mpz_set_si(zero,0);

		if(N>=2)
		{
			mpz_t ls_diff[MAX_N];
			for(int i=0;i<N-1;i++)
			{
				mpz_init(ls_diff[i]);
			}

			// ls[N-1]との差の絶対値ls_diffを求める
			for (int n=0;n<N-1;n++)
			{
				if(mpz_cmp(ls[n],ls[N-1])==1)
				{
					mpz_sub(ls_diff[n],ls[n],ls[N-1]);
				}
				else
				{
					mpz_sub(ls_diff[n],ls[N-1],ls[n]);
				}
			}


			// それらの最大公約数gを求める
			mpz_t g;
			mpz_init(g);
			mpz_set(g,ls_diff[0]);
			for (int n=1;n<N-1;n++)
			{
				mpz_gcd(g,g,ls_diff[n]);
			}

			// いくら足せば、gの倍数になるか求める
			mpz_t mod;
			mpz_init(mod);
			mpz_mod(mod,ls[0],g);

			if(mpz_cmp(zero,mod)==0)
			{
				mpz_set(ret,zero);
			}
			else
			{
				mpz_sub(ret,g,mod);
			}
		}
		else
		{
			mpz_set(ret,zero);
		}

		// 結果を出力
		printf("Case #%d: ",c+1);

		mpz_out_str(stdout,10,ret);

		printf("\n");

	 }

#endif
	return 0;
}
