#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <vector>
#include <stack>
#include <string>
#include <queue>
  
using namespace std;
  
#define ABS(a) (((a) > 0)? (a): -(a))
#define MIN(a, b) (((a) < (b))? (a): (b))
#define MAX(a, b) (((a) < (b))? (b): (a))
#define MFOR(i, a, n) for (int i = (a); i < (n); i++)
#define FOR(i, a, n) for (int i = (a); i <= (n); i++)
#define DFOR(i, a, n) for (int i = (a); i >= (n); i--)
#define SQR(a) (a) * (a)
#define All(a) (a).begin(), (a).end()
#define PI 3.1415926535897932384626433832795
#define MEMS(a, b) memset((a), (b), sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'
#define LL long long
#define UN unsigned
#define Or ||
#define And &&
/////////////////////////////////////////////

pair <string, string> KKK[1024];
map <string, int> F, S;

void solution()
{
	int T;
	cin >> T;
	FOR(test, 1, T)
	{
		printf("Case #%d: ", test);
		int n;
		cin >> n;
		FOR(i, 1, n)
		{
			string a, b;
			cin >> a >> b;
			KKK[i] = MP(a, b);
		}

		F.clear();
		S.clear();
		int ans = 0;
		int used = 0;
		int q = 0;
		while (used < n)
		{
			q++;
			FOR(i, 1, n)
			{
				if (KKK[i].first.size() == 0)
					continue;
				if (F[KKK[i].first] == 0 And S[KKK[i].second] == 0)
				{
					F[KKK[i].first]++;
					S[KKK[i].second]++;
					used++;
					KKK[i].first = "";
				}
			}

			FOR(i, 1, n)
			{
				if (KKK[i].first.size() == 0)
					continue;
				if (F[KKK[i].first] > 0 And S[KKK[i].second] > 0)
				{
					ans++;
					used++;
					KKK[i].first = "";
				}
			}

			FOR(i, 1, n)
			{
				if (KKK[i].first.size() == 0)
					continue;
				if (F[KKK[i].first] == 0 And (q & 1))
				{
					F[KKK[i].first]++;
					used++;
					KKK[i].first = "";
					break;
				}
				else if (S[KKK[i].second] == 0 And ((q + 1) & 1))
				{
					S[KKK[i].second]++;
					used++;
					KKK[i].first = "";
					break;
				}
			}
		}
		cout << ans << endl;
	}
}

/*-------------------*/
  
int main()
{
#ifdef Files
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
/*Test*/
//freopen("input.txt", "w", stdout);
long double OcZ2X = clock();
#else
//freopen("laboratory.in", "r", stdin);
//freopen("laboratory.out", "w", stdout);
#endif
/*
 　　　　　　　　　　　 　∧__∧
　　　　　　　　　　　 　( ° ͜ʖ°)
　　　　　　　　　　　 　⊂　　 つ
　　　　　　　　　　　　　(つ ﾉ
　　　　　　　　　　　　　 (ノ
　　　　　＼　　　　　　☆
　　　　　　　　　　　　　|　　　　　☆
　　　　　　　　　　(⌒ ⌒ヽ　　　/
　　　　＼　　（´⌒　　⌒　　⌒ヾ　　　／
　　　　　 （’⌒　;　⌒　　　::⌒　　）
　　　　　（´*/    solution();   /*:::　）　／
　　☆─　（´⌒;:　　　　::⌒`）　:;　　）
　　　　　（⌒::　　　::　　　　　::⌒　）
　　 　／　（　　　　ゝ　　ヾ　丶　　ソ　─
*/
#ifdef Time
long double P2HxQ = clock();
printf("\n*** Total time = %.3f sec ***\n", (P2HxQ - OcZ2X) / CLOCKS_PER_SEC);
#endif
}