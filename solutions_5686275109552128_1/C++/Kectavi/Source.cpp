
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

typedef pair<int, int> P2;

void main()
{

ifstream pin;
ofstream oput;

pin.open("B-large.in");//m.txt
oput.open("out_2_l");
string p;
getline(pin, p);
int cNum = atoi(p.c_str());

for (int i = 0; i < cNum; i++)
{
/*	getline(pin, p);
	int N = atoi(p.c_str());
	priority_queue<P2,vector<P2>,less<P2>> ap1;

	getline(pin, p);
	for (int j = 0; j < N - 1; j++)
	{
		int pos1 = p.find(" ");
		ap1.push(P2(atoi(p.substr(0, pos1).c_str()),1));
		p=p.substr(pos1 + 1);
	}
	ap1.push(P2(atoi(p.c_str()), 1));
	vector<int> res;
	
	res.push_back(ap1.top().first);
	int ccut = 0;
	while (ap1.size()>0)
	{
		P2 k1 = ap1.top();
		ap1.pop();
		if (k1.first <= 3)
		{
			res.push_back(ccut + k1.first);
			break;
		}
		else
		{
			res.push_back(ccut + k1.first);
			ccut += k1.second;
			if (k1.first % 2){
				ap1.push(P2(k1.first / 2, k1.second));
				ap1.push(P2(k1.first / 2+1, k1.second));
			}
			else ap1.push(P2(k1.first / 2, k1.second*2));
			res.push_back(ccut + ap1.top().first);
		}
	}

	int minVal = *min_element(res.begin(),res.end());
	*/
	cout << i << endl;
	getline(pin, p);
	int N = atoi(p.c_str());
	vector<int> ap1;

	getline(pin, p);
	for (int j = 0; j < N - 1; j++)
	{
		int pos1 = p.find(" ");
		ap1.push_back(atoi(p.substr(0, pos1).c_str()));
		p = p.substr(pos1 + 1);
	}
	ap1.push_back(atoi(p.c_str()));

	int maxVal = *max_element(ap1.begin(), ap1.end());

	int lkm = 0;
	int kkp = 0;
	for (int z = 1; z <= maxVal; z++)
	{
		for (int l = 1; l <= z; l++)
		{
			int gsum = 0;
			for (int pp = 0; pp < ap1.size(); pp++)
			{
				int tx = (ap1[pp]-1) / l;
				//if (ap1[pp]-1 != tx*l) tx++;
				gsum += tx;
			}
			if (gsum <= z - l) {
				lkm = 1; break;
			}
		}
		if (lkm == 1) { kkp = z; break; }
	}

	oput << "Case #" << i + 1 << ": " << kkp << endl;
}
pin.close();
oput.close();

	cout << "Program Done!" << endl;
	getchar();
	//return 0;
}
