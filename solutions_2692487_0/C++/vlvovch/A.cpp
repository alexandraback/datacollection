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
vector<int> motes(0);
int A;

int main()
{
    fstream fin("A-small-attempt0.in",ifstream::in);
    fstream fout("A-small-attempt0.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
        //cout << tc << "\n";
		fin >> A >> N;
		motes.resize(N);
		rep(i,N) fin >> motes[i];
		sort(motes.begin(), motes.end());
		int tret = N + 1;
		int cst = 0;
		int tans = 0;
		int AA = A;
		for (int dels=0;dels<=N;dels++)
		{
			cst = 0;
			tans = dels;
			AA = A;
			vector<int> mot(motes.size()-dels);
			rep(i, mot.size()) mot[i] = motes[i];
			while (cst<mot.size())
			{
				while (cst<mot.size() && AA>mot[cst]) { AA += mot[cst]; cst++; }
				if (cst==mot.size()) break;
				if (AA==1) break;
				AA += AA-1;
				tans++;
			}
			if (cst==mot.size()) tret = min(tret, tans);
		}
		fout << "Case #" << tc << ": " << tret << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    //system("PAUSE");
    return 0;
}
