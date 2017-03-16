#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include<iomanip>
using namespace std;

int main (int argc, char const* argv[])
{
	int T;
	cin >> T;
	int tableau[500];
	int dejaenlever[500];
	for (int cas = 0; cas < T; cas += 1)
	{
		int N;
		cin >> N;
		int somme = 0;
		for (int i = 0; i < N; i += 1)
		{
			cin >> tableau[i];
			somme += tableau[i];
			dejaenlever[i]=0;
		}
		int n =N;
		int doublesomme = 2*somme;
		for (int i = 0; i < N; i += 1)
		{
			for (int j = 0; j < N; j += 1)
			{
				
				if (tableau[j] > doublesomme/(double(n)) && dejaenlever[j] == 0)
				{
					n = n-1;
					dejaenlever[j] = 1;
					doublesomme = doublesomme - tableau[j];
				}
			}
		}
		cout << "Case #" << cas+1 << ":";
		for (int i = 0; i < N; i += 1)
		{
			double resultat;
			cout << " " << fixed << setprecision(6) << max (0.,(100. * (doublesomme/(double(n))/somme - tableau[i] / (double(somme)))));
			
		}
		cout << endl;
	}
	return 0;
}
