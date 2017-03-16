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

int main()
{
    fstream fin("B-large.in",ifstream::in);
    fstream fout("B-large.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
        vector< vector<int> > lawn;
		int N, M;
		fin >> N >> M;
		lawn.resize(N);
		rep(i,N)
		{
			lawn[i].resize(M);
			rep(j,M) fin >> lawn[i][j];
		}
		bool ans = 1;
		rep(i,N)
		{
			if (ans)
			{
			rep(j,M)
				if (ans)
				{
					bool posr = 1, posc = 1;
					rep(k,N) if (lawn[k][j]>lawn[i][j]) posc = 0;
					rep(k,M) if (lawn[i][k]>lawn[i][j]) posr = 0;
					if (posr==0 && posc==0) ans = 0;
				}
			}
		}
        if (ans) fout << "Case #" << tc << ": YES\n";
		else fout << "Case #" << tc << ": NO\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    system("PAUSE");
    return 0;
}
