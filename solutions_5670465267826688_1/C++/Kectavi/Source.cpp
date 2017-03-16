
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;

int Pdc(char in1, char in2, char* out)
{
	if (in1 == '1' && in2 == '1') { out[0] = '1'; return 0; }
	if (in1 == '1' && in2 == 'i') { out[0] = 'i'; return 0; }
	if (in1 == '1' && in2 == 'j') { out[0] = 'j'; return 0; }
	if (in1 == '1' && in2 == 'k') { out[0] = 'k'; return 0; }

	if (in1 == 'i' && in2 == '1') { out[0] = 'i'; return 0; }
	if (in1 == 'i' && in2 == 'i') { out[0] = '1'; return 1; }
	if (in1 == 'i' && in2 == 'j') { out[0] = 'k'; return 0; }
	if (in1 == 'i' && in2 == 'k') { out[0] = 'j'; return 1; }

	if (in1 == 'j' && in2 == '1') { out[0] = 'j'; return 0; }
	if (in1 == 'j' && in2 == 'i') { out[0] = 'k'; return 1; }
	if (in1 == 'j' && in2 == 'j') { out[0] = '1'; return 1; }
	if (in1 == 'j' && in2 == 'k') { out[0] = 'i'; return 0; }

	if (in1 == 'k' && in2 == '1') { out[0] = 'k'; return 0; }
	if (in1 == 'k' && in2 == 'i') { out[0] = 'j'; return 0; }
	if (in1 == 'k' && in2 == 'j') { out[0] = 'i'; return 1; }
	if (in1 == 'k' && in2 == 'k') { out[0] = '1'; return 1; }
}

void main()
{

ifstream pin;
ofstream oput;

pin.open("C-large.in");//m.txt
oput.open("out_3_l");
string p;
getline(pin, p);
int cNum = atoi(p.c_str());

for (int i = 0; i < cNum; i++)
{
	//cout << i << endl;
	getline(pin, p);
	int pos1 = p.find(" ");
	int L = atoi(p.substr(0, pos1).c_str());
	int X = atoi(p.substr(pos1 + 1).c_str());
	cout << i << ", "<<L<<", "<<X<< endl;

	string dd;
	getline(pin, dd);

	vector<vector<char>> atable(L);
	vector<vector<int>> itable(L);
	for (int j = 0; j < L; j++)
	{
		char sr = dd[j];
		char tod;
		int fneg = 0;
		atable[j].push_back(sr);
		itable[j].push_back(fneg);
		for (int z = j+1; z < L; z++)
		{
			fneg += Pdc(sr, dd[z], &tod);
			atable[j].push_back(tod);
			itable[j].push_back(fneg);
			sr = tod;
		}
	}
	
	int ifind = 0;
	char sri = '1';
	char todi = '1';
	int fnegi = 0;
	for (int j = 0; j < L*min(4,X); j++)
	{
		fnegi += Pdc(sri, dd[j%L], &todi);
		if (todi == 'i' && !(fnegi%2))
		{
			char srj = '1';
			char todj = '1';
			int fnegj = 0;
			for (int z = j + 1; z < min(L*min(4, X) + j,L*X); z++)
			{
				fnegj += Pdc(srj, dd[z%L], &todj);
				if (todj == 'j' && !(fnegj % 2)) 
				{
					int npd;
					if ((z + 1) % L == 0) npd = 0;
					else npd = min(z%L + 1, L - 1);
					int rdf = (X - z / L - 1) % 4;
					char srz = '1';
					char todz = '1';
					int fnegz = 0;
					for (int lop = 0; lop < rdf; lop++)
					{
						fnegz += Pdc(srz, atable[0][L-1], &todz);
						fnegz += itable[0][L - 1];
						srz = todz;
					}
					char todpp='1';
					int glpp=0;
					if (npd == 0) { todpp = todz; glpp = fnegz; }
					else {	glpp = Pdc(atable[npd][L - 1 - npd], todz, &todpp); 
							glpp += fnegz; 
							glpp += itable[npd][L - 1 - npd];
					}
					if (todpp == 'k' && !(glpp % 2)) { 
						ifind = 1; 
						break;
					}
					else srj = todj;
				}
				else srj = todj;
				if (ifind == 1) break;
			}
			if (ifind == 1) break;
			else sri = todi;
		}
		else sri = todi;
	}

	if (ifind==1)
		oput << "Case #" << i + 1 << ": Yes" << endl;
	else
		oput << "Case #" << i + 1 << ": NO" << endl;
}
pin.close();
oput.close();

	cout << "Program Done!" << endl;
	getchar();
	//return 0;
}
