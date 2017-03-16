#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

#define DICC_SIZE 521196

using namespace std;

int minimoError(string& S, vector<string>& dicc, int i, int u, vector<vector<int> >& minimosParciales, vector< vector<int> >& posibles)
{
	if (i == S.length())
		return 0;

	if (minimosParciales[i][u] != -1)
		return minimosParciales[i][u];

	int minTotal = 99999;
	for (int di = 0; di < posibles[i].size(); ++di)
	{
		string& p(dicc[posibles[i][di]]);
		
		if (p.length() > S.length() - i)
			continue;
		
		int cantCambios = 0;
		int ultimoCambio = (u == S.length() ? -6 : u);
		
		bool sirvio = true;
		for (int j = 0; j < p.length(); ++j)
		{
			if (p[j] != S[i+j])
			{
				if (j+i - ultimoCambio < 5)
				{
					sirvio = false;
					break;
				}
				ultimoCambio = j+i;
				cantCambios++;
			}
		}
		if (!sirvio)
			continue;
		
		minTotal = min(minTotal, cantCambios + minimoError(S, dicc, i+p.length(), (ultimoCambio == -6 ? S.length() : ultimoCambio), minimosParciales, posibles));
	}
	
	minimosParciales[i][u] = minTotal;
	return minTotal;
}

bool ordenar(const string& s1, const string& s2)
{
	return s1.length() > s2.length();
}

int main()
{
	vector<string> dicc(DICC_SIZE);
	FILE* fDicc = fopen("dicc.in", "r");
	if (fDicc != NULL)
	{
		for (int i = 0; i < DICC_SIZE; ++i)
		{
			char s[12];
			fscanf(fDicc, "%s", s);
			dicc[i] = string(s);
		}
		fclose(fDicc);
	}
	sort(dicc.begin(), dicc.end(), ordenar);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << (t+1) << ": ";
		string S;
		cin >> S;
		
		vector< vector<int> > posibles(S.length());
		for (unsigned int i = 0; i < S.length(); ++i)
		{
			for (int d = 0; d < DICC_SIZE; ++d)
			{
				string& p(dicc[d]);
		
				if (p.length() > S.length() - i)
					continue;
		
				int ultimoCambio = -6;
		
				bool sirvio = true;
				for (int j = 0; j < p.length(); ++j)
				{
					if (p[j] != S[i+j])
					{
						if (j - ultimoCambio < 5)
						{
							sirvio = false;
							break;
						}
						ultimoCambio = j;
					}
				}
				if (sirvio)
					posibles[i].push_back(d);
			}
		}
		
		vector<vector<int> > parciales(S.length()+1);
		for (unsigned int i = 0; i < S.length(); ++i)
			parciales[i] = vector<int>(S.length()+1,-1);
		
		cout << minimoError(S,dicc,0,S.length(),parciales, posibles);
		
		cout << endl;
	}
	return 0;
}
