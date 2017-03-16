#include <utility>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define NMAX 111
#define REPT(n) for(int t=1; t<=(n); ++t)
#define REPI(n) for(int i=1; i<=(n); ++i)

typedef long long LL;
typedef pair<LL,LL> PLL;

int N, M;
int A[NMAX],    B[NMAX];
LL  ALEN[NMAX], BLEN[NMAX];
map<PLL,LL> MEM[NMAX][NMAX];

LL LCS(int a_num, LL a_delta, int b_num, LL b_delta)
{
	// border case
	if (a_num>N || b_num>M) return 0;

	// memory
	PLL delty(a_delta,b_delta);
	map<PLL,LL>& MP=MEM[a_num][b_num];
	map<PLL,LL>::iterator I=MP.find(delty);
	if (I!=MP.end()) 
		return I->second;

	// common
	LL a_rest=ALEN[a_num]-a_delta,b_rest=BLEN[b_num]-b_delta;
	LL common_segment=min(a_rest,b_rest);

	// same
	LL ret = 0;
	if (A[a_num]==B[b_num])
	{
		if (a_rest==b_rest) 
			ret=common_segment+LCS(a_num+1,0, b_num+1,0);
		else if (a_rest>b_rest) 
			ret=common_segment+LCS(a_num,a_delta+common_segment, b_num+1,0);
		else 
			ret=common_segment+LCS(a_num+1,0,b_num, b_delta+common_segment);
	}
	else // standard LCS
		ret=max(LCS(a_num+1,0,b_num,b_delta), LCS(a_num,a_delta,b_num+1,0));

	MP[delty]=ret;
	return ret;
}

LL solve()
{
	// init
	for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j) MEM[i][j].clear();

	// in
	cin>>N>>M;
	REPI(N) cin>>ALEN[i]>>A[i];
	REPI(M) cin>>BLEN[i]>>B[i];

	// solve
	return LCS(1,0, 1,0);
}

int main()
{
	ios_base::sync_with_stdio(0);

	int nCases; cin>>nCases;
	REPT(nCases)
	{
		cout<<"Case #"<<t<<": "<<solve()<<endl;
	}
	
	return 0;
}