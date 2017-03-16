#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>

#define PB push_back
#define SIZE(x) (int)x.size()

using namespace std;
typedef vector<int> VI;
typedef vector<bool> VB;

ostream& operator<<(ostream& os, const VI& V)
{
	if (V.empty()) os<<"IMPOSSIBLE";
	else
	{
		os<<V[0];
		for (int i=1; i<SIZE(V); ++i) os<<' '<<V[i];
	}
	return os;
}

struct skrzynka
{
	int rodzaj;
	VI klucze;
	void czytaj()
	{
		cin>>rodzaj;
		int ile; cin>>ile;
		klucze.resize(ile);
		for (int i=0; i<ile; ++i) cin>>klucze[i];
	}
};

class problem
{
private:
	int K,N;
	int ileKluczy[201];
	vector<skrzynka> skrzynki;
	VI solution;
	VB opened;
	set<VB> vis;

	void update(const VI& klucze, int wsp) //wsp=1 -> dodajemy; wsp=-1 -> usuwamy
	{
		for (int i=0; i<SIZE(klucze); ++i)
		{
			int val=klucze[i];
			ileKluczy[val]+=wsp;
		}
	}
	void dodaj(const VI& klucze) { update(klucze,1); }
	void usun(const VI& klucze) { update(klucze,-1); }

	bool DFS()
	{
		if (count(opened.begin(),opened.end(),false)==0) return true; //Wszystkie otworzone, hurra!

		for (int i=0; i<N; ++i)
		{
			if (opened[i]) continue;
			skrzynka& sk=skrzynki[i];
			int rodzaj=sk.rodzaj;
			if (ileKluczy[rodzaj]>0)
			{
				--ileKluczy[rodzaj];
				solution.push_back(i+1);
				dodaj(sk.klucze);
				opened[i]=true;
				if (!vis.count(opened))
				{
					vis.insert(opened);
					bool wyn=DFS();
					if (wyn) return true;
				}
				opened[i]=false;
				usun(sk.klucze);
				solution.pop_back();
				++ileKluczy[rodzaj];
			}
		}
		return false;
	}
public:
	problem(int K, int N) : K(K),N(N),skrzynki(N) { fill(ileKluczy,ileKluczy+201,0); }
	void czytaj()
	{
		for (int i=0; i<K; ++i)
		{
			int val; cin>>val;
			++ileKluczy[val];
		}
		for (int i=0; i<N; ++i) skrzynki[i].czytaj();
	}
	VI solve()
	{
		solution.clear();
		opened.clear();
		opened.resize(N,0);
		vis.clear();
		DFS();
		return solution;
	}
};

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int nrTestu=1; nrTestu<=Testow; ++nrTestu)
	{
		int K,N; cin>>K>>N;
		problem P(K,N);
		P.czytaj();
		VI wynik=P.solve();		
		cout<<"Case #"<<nrTestu<<": "<<wynik<<endl;
	}

	return 0;
}