#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

double me[1001];
double you[1001];

int calc(vector <double> A, vector <double> B)
{
	int p = 0;
	for(int i = 0; i < A.size(); i++)
	{
		while(p < B.size() && A[i] > B[p]) p ++;
		if(p >= B.size()) return A.size() - i;
		p ++;
	}
	return 0;
}

int calc2(vector <double> A, vector <double> B)
{
	int p = 0;
	int score = 0;
	for(int i = 0; i < B.size(); i++)
	{
		while(p < A.size() && A[p] < B[i]) p ++;
		if(p >= A.size()) break;
		score ++;
		p ++;
	}
	return score;
}

int solve()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> me[i];
	for(int i = 1; i <= n; i++)
		cin >> you[i];
	sort(me + 1, me + 1 + n);
	sort(you + 1, you + 1 + n);
	int score1 = 0, score2 = 0;
	for(int i = 1; i <= n; i++)
	{
		vector <double> x1, x2;
		for(int j = i; j <= n; j++)
			x1.push_back(me[j]);
		for(int j = 1; j <= n+1-i; j++)
			x2.push_back(you[j]);
		int v = calc(x1, x2);
		if(i == 1)
			score2 = v;
		score1 = max(score1, v);
		score1 = max(score1, calc2(x1, x2));
	}
	cout << score1 << " " << score2 << endl;
	return 0;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
