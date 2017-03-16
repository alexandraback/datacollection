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
int A,B,K;

int main()
{
    fstream fin("B-small-attempt0.in",ifstream::in);
    fstream fout("B-small-attempt0.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
		fin >> A >> B >> K;
		long long ret = 0;
		for(int i=0;i<A;++i)
			for(int j=0;j<B;++j)
				if ((i&j)<K) ret++;
		cout << "Case #" << tc << ": " << ret << "\n";
		fout << "Case #" << tc << ": " << ret << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    system("PAUSE");
    return 0;
}
