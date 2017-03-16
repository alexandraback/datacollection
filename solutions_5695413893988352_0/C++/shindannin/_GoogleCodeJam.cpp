// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
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
#include <numeric>
#include <unordered_map>
#include "assert.h"

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x,T a,T b){return a<=x&&x<=b;}
template<class T> void amin(T &a,T v){if(a>v) a=v;}
template<class T> void amax(T &a,T v){if(a<v) a=v;}
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;

#define PRINTF(fmt,...) fprintf(stderr,fmt,__VA_ARGS__); printf(fmt,__VA_ARGS__);


#if 1

bool checkFormat(int i, const string& s)
{
	int keta = SZ(s);

	string ans;
	ans=to_string(i);


	if(keta-SZ(ans)<0)
	{
		return false;
	}
	ans = string(keta-SZ(ans), '0') + ans;

	assert(SZ(ans)==SZ(s));

	for (int i = 0; i < SZ(s); ++i)
	{
		if(s[i]!='?' && ans[i]!=s[i])
		{
			return false;
		}
	}
	return true;
}

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int testcase = 0; testcase < T; ++testcase)
	{
		string s[2];
		cin >> s[0] >> s[1];

		int keta = SZ(s[0]);
		int numMax = pow(10,keta)+EPS;


		pair <int, pair<int, int> > best;
		best.first = BIG;

		for (int i = 0; i <= numMax; ++i)
		{
			for (int k = 0; k <= numMax; ++k)
			{
				if(checkFormat(i,s[0])&&checkFormat(k,s[1]))
				{
					pair <int, pair<int, int> > tmp;
					tmp.first = abs(i-k);
					tmp.second.first = i;
					tmp.second.second = k;
					if(tmp<best)
					{
						best = tmp;
					}
				}
			}
		}

		string ans[2];
		ans[0]=to_string(best.second.first);
		ans[1]=to_string(best.second.second);
		for (int i = 0; i < 2; ++i)
		{
			ans[i] = string(keta-SZ(ans[i]), '0') + ans[i];
		}

		PRINTF("Case #%d: %s %s\n",testcase+1, ans[0].c_str(), ans[1].c_str());
	}

	return 0;
}



#else

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	const char* str[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


	for (int testcase = 0; testcase < T; ++testcase)
	{
		string s;
		int freq[256] = {};
		cin >> s;
		for (int i = 0; i < SZ(s); ++i)
		{
			freq[s[i]]++;
		}

		int chara[10] = {};

		while(1)
		{
			bool owari = true;
			for (int i = 'A'; i <='Z'; ++i)
			{
				if(freq[i]>0)
				{
					owari = false;
					break;
				}
			}

			if(owari)
			{
				break;
			}

			const int prior[10] = {0,2,8,6,7,3,5,4,9,1};
			for(int v=0;v<10;++v)
			{
				const int i = prior[v];


				bool found = true;
				int tmp[256]={};
				for (int k = 'A'; k <='Z'; ++k)
				{
					tmp[k] = freq[k];
				}

				for (int k = 0; k < strlen(str[i]); ++k)
				{

					if(tmp[str[i][k]]>0)
					{
						tmp[str[i][k]]--;
					}
					else
					{
						found = false;
						break;
					}
				}

				if(found)
				{
					chara[i]++;
					for (int k = 'A'; k <='Z'; ++k)
					{
						freq[k] = tmp[k];
					}
					break;
				}
			}
		}

		string ans;
		for (int i = 0; i < 10; ++i)
		{
			if(chara[i])
			{
				ans += (char)('0'+i);
				chara[i]--;
				i--;
			}
		}



		PRINTF("Case #%d: %s\n",testcase+1, ans.c_str());
	}

	return 0;
}

#endif