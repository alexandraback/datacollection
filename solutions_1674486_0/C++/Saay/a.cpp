#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include<iomanip>
#include <deque>

using namespace std;

bool parcourlargeur (int debut, int N, vector<int> graphe[1200], int dejavu[1200])
{
	for (int i = 1; i <= N; i += 1)
	{
		dejavu[i]=0;
	}
	deque<int> file;
	file.push_back(debut);
	bool resultat = false;
	while (not file.empty() && resultat == false)
	{
		int courant = file.front();
		file.pop_front();
		if (dejavu[courant])
		{
			resultat = true;
		}
		else
		{
			dejavu[courant] = 1;
			for (int i = 0; i < graphe[courant].size(); i += 1)
			{
				file.push_back(graphe[courant][i]);
			}
		}
	}
	return resultat;
}

int main (int argc, char const* argv[])
{
	int T;
	cin >> T;
	vector<int> graphe[1200];
	int dejavu[1200];
	for (int cas = 0; cas < T; cas += 1)
	{
		int N;
		for (int i = 0; i <= N; i += 1)
		{
			graphe[i].clear();
		}
		int nb;
		int temp;
		cin >> N;
		for (int i = 1; i <= N; i += 1)
		{
			cin >> nb;
			for (int j = 0; j < nb; j += 1)
			{
				cin >> temp;
				graphe[i].push_back(temp);
			}
		}
		bool resultat = false;
		for (int i = 1; i <= N; i += 1)
		{
			resultat  = parcourlargeur(i,N,graphe,dejavu);
			if (resultat)
			{
				break;
			}
		}
		if (resultat)
		{
			cout << "Case #" << cas+1 << ": Yes" << endl;
		}
		else
		{
			cout << "Case #" << cas+1 << ": No" << endl;
		}
	}
	return 0;
}
