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

int kkk[200];
int ans[12];

void OUT()
{
	FOR(i, 0, 9)
	{
		FOR(j, 1, ans[i])
			printf("%d", i);
	}
	cout << endl;
}

void dec(char ch, int p)
{
	kkk[ch] -= p;
}

void solution()
{
	int T;
	cin >> T;
	FOR(test, 1, T)
	{
		printf("Case #%d: ", test);
		string s;
		cin >> s;

		MEMS(kkk, 0);
		MFOR(i, 0, s.size())
			kkk[s[i]]++;

		MEMS(ans, 0);

		int p = kkk['Z'];
		ans[0] = p;
		dec('Z', p);
		dec('E', p);
		dec('R', p);
		dec('O', p);

		p = kkk['W'];
		ans[2] = p;
		dec('T', p);
		dec('W', p);
		dec('O', p);

		p = kkk['X'];
		ans[6] = p;
		dec('S', p);
		dec('I', p);
		dec('X', p);

		p = kkk['S'];
		ans[7] = p;
		dec('S', p);
		dec('E', p);
		dec('V', p);
		dec('E', p);
		dec('N', p);

		p = kkk['V'];
		ans[5] = p;
		dec('F', p);
		dec('I', p);
		dec('V', p);
		dec('E', p);

		p = kkk['F'];
		ans[4] = p;
		dec('F', p);
		dec('O', p);
		dec('U', p);
		dec('R', p);

		p = kkk['G'];
		ans[8] = p;
		dec('E', p);
		dec('I', p);
		dec('G', p);
		dec('H', p);
		dec('T', p);

		p = kkk['T'];
		ans[3] = p;
		dec('T', p);
		dec('H', p);
		dec('R', p);
		dec('E', p);
		dec('E', p);

		p = kkk['O'];
		ans[1] = p;
		dec('O', p);
		dec('N', p);
		dec('E', p);

		p = kkk['E'];
		ans[9] = p;
		dec('N', p);
		dec('I', p);
		dec('N', p);
		dec('E', p);


		OUT();
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