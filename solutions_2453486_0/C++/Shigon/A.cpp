#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define PB push_back

using namespace std;

class plansza
{
private:
	string tab[4];
	char check(const string& napis)
	{
		int ileX=0,ileO=0,ileT=0;
		for (int i=0; i<4; ++i)
		{
			if (napis[i]=='X') ++ileX;
			else if (napis[i]=='O') ++ileO;
			else if (napis[i]=='T') ++ileT;
		}
		if (ileX==4 || ileX==3 && ileT==1) return 'X';
		if (ileO==4 || ileO==3 && ileT==1) return 'O';
		return 'N';
	}
public:
	void czytaj()
	{
		for (int i=0; i<4; ++i) cin>>tab[i];
	}
	string solve()
	{
		vector<string> napisy;

		//Poziome
		for (int w=0; w<4; ++w)
		{
			string napis;
			for (int i=0; i<4; ++i) napis+=tab[w][i];
			napisy.PB(napis);
		}
		//Pionowe
		for (int k=0; k<4; ++k)
		{
			string napis;
			for (int i=0; i<4; ++i) napis+=tab[i][k];
			napisy.PB(napis);
		}
		//Przekatne
		string glownaPrzekatna;
		for (int i=0; i<4; ++i) glownaPrzekatna+=tab[i][i];
		napisy.PB(glownaPrzekatna);
		string drugaPrzekatna;
		for (int i=0; i<4; ++i) drugaPrzekatna+=tab[i][3-i];
		napisy.PB(drugaPrzekatna);

		for (int i=0; i<(int)napisy.size(); ++i)
		{
			const string& napis=napisy[i];
			char wyn=check(napis);
			if (wyn!='N') return string("")+wyn+" won";
		}

		//Nie ma wygranej - remis lub gra nie zakonczona; czy jakies pole puste?
		for (int i=0; i<4; ++i)
		{
			if (tab[i].find('.')!=string::npos) return "Game has not completed";
		}
		return "Draw";
	}
};

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int nrTestu=1; nrTestu<=Testow; ++nrTestu)
	{
		plansza P;
		P.czytaj();
		string wynik=P.solve();
		cout<<"Case #"<<nrTestu<<": "<<wynik<<endl;
	}

	return 0;
}