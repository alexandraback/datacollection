
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

void main()
{

ifstream pin;
ofstream oput;

pin.open("A-small-attempt0.in");//m.txt
oput.open("out_1_s");
string p;
getline(pin, p);
int cNum = atoi(p.c_str());

for (int i = 0; i < cNum; i++)
{
	getline(pin, p);

	int pos1 = p.find(" ");
	int N = atoi(p.substr(0, pos1).c_str());
	string lpo = p.substr(pos1 + 1).c_str();

	int pcl = 0;
	int addp = 0;
	for (int j = 0; j <= N; j++)
	{
		if (lpo[j] != 48){
			if (pcl >= j) pcl += (lpo[j] - 48);
			else
			{
				addp += j - pcl;
				pcl = j + (lpo[j] - 48);
			}
		}
	}

	oput << "Case #" << i + 1 << ": " << addp << endl;

}
pin.close();
oput.close();

	cout << "Program Done!" << endl;
	getchar();
	//return 0;
}
