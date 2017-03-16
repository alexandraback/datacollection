#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#define MAX 110

using namespace std;
typedef long long LL;
typedef pair<LL,LL> para;
typedef map<para,LL> MPL;

LL ILEA[MAX],ILEB[MAX];
int A[MAX],B[MAX];

int N,M;
MPL Mapa[MAX][MAX];

LL W(int na, LL da, int nb, LL db)
{
	if (na>N || nb>M) return 0;
	para PR(da,db);
	MPL& MP=Mapa[na][nb];
	MPL::iterator I=MP.find(PR);
	if (I!=MP.end()) return I->second;

	LL za=ILEA[na]-da,zb=ILEB[nb]-db;
	LL mx=min(za,zb);

	LL wynik;

	if (A[na]==B[nb])
	{
		if (za==zb) wynik=mx+W(na+1,0,nb+1,0);
		else if (za<zb) wynik=mx+W(na+1,0,nb,db+mx);
		else wynik=mx+W(na,da+mx,nb+1,0);
	}
	else wynik=max(W(na+1,0,nb,db),W(na,da,nb+1,0));
	MP[PR]=wynik;
	return wynik;
}

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int test=1; test<=Testow; ++test)
	{
		cin>>N>>M;

		for (int i=1; i<=N; ++i) cin>>ILEA[i]>>A[i];
		for (int i=1; i<=M; ++i) cin>>ILEB[i]>>B[i];

		for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j) Mapa[i][j].clear();

		LL wynik=W(1,0,1,0);

		cout<<"Case #"<<test<<": ";
		cout<<wynik;
		cout<<endl;
	}
	
	return 0;
}