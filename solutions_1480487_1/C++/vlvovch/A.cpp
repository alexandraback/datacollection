#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;
int N;
vector<int> scr;
int pnts;

bool possib(int n, double pct)
{
	double score = scr[n] + pnts*pct;
	double rema = 1. - pct;
	rep(i,N)
		if (i!=n)
		{
			double need = (score - scr[i]) / pnts;
			if (need<0.) continue;
			if (need>rema) return 1.;
			rema -= need;
		}
	return 0;
}

double findans(int n)
{
	double left = 0., right = 1.;
	double ctr = (left+right)/2.;
	while ((right-left)/right>1e-8)
	{
		ctr = (left+right)/2.;
		if (possib(n, ctr))
		{
			right = ctr;
		}
		else left = ctr;
	}
	return ctr;
}

int main()
{
    fstream fin("A-large.in",ifstream::in);
    fstream fout("A-large.out",ofstream::out);
    fin >> T;
	//char cc[400];
	//fin.getline(cc, 400);
    for(int j=1;j<=T;j++)
    {
		int tmp = 0;
		fin >> N;
		scr.resize(0);
		pnts = 0;
		rep(i,N)
		{
			fin >> tmp;
			scr.push_back(tmp);
			pnts += tmp;
		}
		fout << "Case #" << j << ": ";
		rep(i, scr.size()) fout << 100.*findans(i) << " ";
		fout << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC;
    system("PAUSE");
    return 0;
}
