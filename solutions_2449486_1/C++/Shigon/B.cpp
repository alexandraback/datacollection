#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

class plansza
{
private:
	int N,M;
	MI tab;
public:
	plansza(int N, int M) : N(N),M(M),tab(N,VI(M)) {}
	void czytaj()
	{
		for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) cin>>tab[i][j];
	}
	string solve()
	{
		VI maksW(N,0); // maks w wierszu
		VI maksK(M,0); // maks w kolumnie
		for (int i=0; i<N; ++i)
		{
			for (int j=0; j<M; ++j)
			{
				maksW[i]=max(maksW[i],tab[i][j]);
				maksK[j]=max(maksK[j],tab[i][j]);
			}
		}

		for (int i=0; i<N; ++i)
		{
			for (int j=0; j<M; ++j)
			{
				int val=tab[i][j];
				if (val<maksW[i] && val<maksK[j]) return "NO";
			}
		}
		return "YES";
	}
};

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int nrTestu=1; nrTestu<=Testow; ++nrTestu)
	{
		int N,M;
		cin>>N>>M;
		plansza P(N,M);
		P.czytaj();
		string wynik=P.solve();
		cout<<"Case #"<<nrTestu<<": "<<wynik<<endl;
	}

	return 0;
}