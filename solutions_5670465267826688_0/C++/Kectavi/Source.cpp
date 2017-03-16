
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

pin.open("C-small-attempt0.in");//m.txt
oput.open("out_3_s");
string p;
getline(pin, p);
int cNum = atoi(p.c_str());

for (int i = 0; i < cNum; i++)
{
	cout << i << endl;
	getline(pin, p);
	int pos1 = p.find(" ");
	int L = atoi(p.substr(0, pos1).c_str());
	int X = atoi(p.substr(pos1 + 1).c_str());

	string dd;
	getline(pin, dd);

	vector<vector<char>> atable(L*X);
	vector<vector<int>> itable(L*X);
	for (int j = 0; j < L*X; j++)
	{
		char sr = dd[j%L];
		char tod;
		int fneg = 0;
		atable[j].push_back(sr);
		itable[j].push_back(fneg);
		for (int z = j+1; z < L*X; z++)
		{
			fneg += Pdc(sr, dd[z%L], &tod);
			atable[j].push_back(tod);
			itable[j].push_back(fneg);
			sr = tod;
		}
	}
	int ifind = 0;
	for (int j = 0; j < L*X; j++)
	{
		if (atable[0][j] == 'i' && !(itable[0][j] % 2))
		{
			for (int z = j + 1; z < L*X; z++)
			{
				if (atable[j + 1][z - j - 1] == 'j' && !(itable[j + 1][z - j - 1] % 2) && z + 1<L*X &&
					atable[z + 1][L*X - 1-z-1] == 'k' && !(itable[z + 1][L*X - 1-z-1] % 2))
				{ifind = 1;break;}
			}
			if (ifind == 1) break;
		}
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
