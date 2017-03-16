#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <valarray>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>

#define PB push_back
#define SIZE(x) (int)x.size()
#define st first
#define nd second

using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef pair<int,int> para;
typedef vector<para> VP;
typedef vector<signed char> VC;
typedef long double LD;

const int STALA=100;

class plansza
{
private:
	int X,Y;
	VC wysokosci;
	bool found;
public:
	plansza() : found(false),X(-1),Y(-1),wysokosci(200,-1) {}
	void reset(int X, int Y)
	{
		this->X=X+STALA;
		this->Y=Y;
		wysokosci.clear();
		wysokosci.resize(201,-1);
	}
	bool jestDiament() { return found; }
	vector<plansza> upuscDiament(int iksPocz=STALA) //STALA odpowiada zeru
	{
		vector<plansza> V;

		int iks=iksPocz;
		while (true)
		{
			int igrek=wysokosci[iks];
			bool poLewej=(wysokosci[iks-1]>=igrek+1);
			bool poPrawej=(wysokosci[iks+1]>=igrek+1);
			bool obokLewo=(wysokosci[iks-2]==wysokosci[iks]);
			bool obokPrawo=(wysokosci[iks+2]==wysokosci[iks]);

			if (poLewej && poPrawej)
			{
				plansza P=*this;
				P.wysokosci[iks]+=2;
				if (iks==X && P.wysokosci[iks]==Y) P.found=true;
				V.PB(P);
				break;
			}
			else if (igrek==-1)
			{
				plansza P=*this;
				P.wysokosci[iks]=0;
				if (iks==X && P.wysokosci[iks]==Y) P.found=true;
				V.PB(P);
				break;
			}
			else if (poLewej) //ale nie ma po prawej
			{
				if (obokPrawo) iks+=1;
				else iks+=2; 
			}
			else if (poPrawej) //ale nie ma po lewej
			{
				if (obokLewo) iks-=1;
				else iks-=2; 
			}
			else //droga wolna po obu stronach
			{
				vector<plansza> VL; //spada po lewej
				vector<plansza> VR; //spada po prawej
				if (obokLewo) VL=upuscDiament(iks-1); 
				else VL=upuscDiament(iks-2);
				if (obokPrawo) VR=upuscDiament(iks+1); 
				else VR=upuscDiament(iks+2);

				V.insert(V.end(),VL.begin(),VL.end());
				V.insert(V.end(),VR.begin(),VR.end());
				if (SIZE(V)>2) cerr<<"!!!"; //Wg moich przypuszczen to nie powinno wystapic
				break;
			}
		}
		return V;
	}
};

class problem
{
private:
	int N,X,Y;
	plansza P;

	LD DFS(int nr=1)
	{
		if (P.jestDiament()) return 1.0L;
		else if (nr>N) return 0.0L;
		vector<plansza> V=P.upuscDiament();
		LD wynik=0.0L;
		for (int i=0; i<SIZE(V); ++i)
		{
			P=V[i];
			wynik+=DFS(nr+1)/SIZE(V);
		}
		return wynik;
	}

	LD solve()
	{
		P.reset(X,Y);
		LD wyn=DFS();
		return wyn;
	}
public:
	void czytaj() { cin>>N>>X>>Y; }
	void wypiszWynik()
	{
		LD wynik=solve();
		cout<<wynik;
	}
};

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int nrTestu=1; nrTestu<=Testow; ++nrTestu)
	{
		problem Prob;
		Prob.czytaj();
		cout<<"Case #"<<nrTestu<<": ";
		Prob.wypiszWynik();
		cout<<endl;
	}

	return 0;
}