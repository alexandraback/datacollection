#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <sstream>
#include <cstring>
#include <bitset>
#include <climits>
#include <typeinfo>

using namespace std;
#define  AS(arr)  (sizeof(arr)/sizeof(arr[0]))
#define ALL(c) (c).begin(),(c).end() 
#define SIZE(a) int((a).size())
#define EACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;


int main()
{
	int testcases;
	cin >> testcases;

	REP(testcase, testcases)
	{
		LL ret = 0;

		LL a[101];
		int A[101];
		LL b[101];
		int B[101];





		int N, M;
		cin >> N >> M;
		vector<int> v;

		REP(i, N)
		{
			cin >> a[i] >> A[i];
			v.push_back(0);
		}

		REP(i, M)
		{
			cin >> b[i] >> B[i];
			v.push_back(1);
		}

		
		do
		{
			int aidx = 0;
			int bidx = 0;

			LL nowa = 0;
			int nowA = 0;

			LL nowb = 0;
			int nowB = 0;
			LL r = 0;
			REP(i, v.size())
			{
				if(!v[i])
				{
					nowa = a[aidx];
					nowA = A[aidx];
					aidx++;
				}
				else
				{
					nowb = b[bidx];
					nowB = B[bidx];
					bidx++;
				}

				if(nowA == nowB)
				{
					LL use = min(nowa, nowb);
					r += use;
					nowa -= use;
					nowb -= use;
				}
			}
			ret = max(r, ret);
			
		} while(next_permutation(ALL(v)));



		cout << "Case #" << testcase+1 << ": " << ret << endl;
	}
	return 0;
}
