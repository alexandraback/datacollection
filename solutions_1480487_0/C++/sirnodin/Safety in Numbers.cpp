#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<list>
#include<stdio.h>
#include<sstream>
#include<set>
#include<deque>
#include<cmath>
#include<numeric>
#include<fstream>
#include <iomanip>

using namespace std;

typedef long long LInt;
typedef vector<int> intvec;
typedef vector<intvec> intvec2;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define DEC(i,k) for (int i=(k); i>=0; --i)
#define FORIT(i,c) for (decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())

const int MAXN = 201;
int N;

int S[MAXN];

double ans = 0;

int main()
{
	ifstream fin("A-small-attempt1.in");
	ofstream fout("A-small-attempt1.out");
	
	int T;
	fin>>T;

	REP(TEST,T)
	{
		fin>>N;
		int sum = 0;
		REP(i,N)
		{
			fin>>S[i];
			sum+=S[i];
		}
		fout<<"Case #"<<TEST+1<<":";
		REP(i,N)
		{
			ans = (2*sum-N*S[i])*100.0/N/sum;
			fout<<" "<<fixed<<setprecision(6)<<ans;
		}
		fout<<endl;
	}
	system("pause");
	return 0;
}