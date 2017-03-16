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

int K, N;

bool solv;

struct chest {
	int ke;
	vector<int> keys;
};

vector<chest> ch;

vector<int> used;
vector<int> trav;

vector<int> ckeys(101);

vector<int> totkeys(101);
vector<int> totkeysw(101);
vector<int> wrkkeys(101);

void go(int st)
{
	if (st==N)
	{
		solv = 1;
		return;
	}
	rep(i, ch.size())
		if (used[i]==0 && ckeys[ch[i].ke]>0)
		{
			used[i] = 1;
			trav[st] = i;
			ckeys[ch[i].ke]--;
			wrkkeys[ch[i].ke]--;
			totkeysw[ch[i].ke]--;
			//totkeys[ch[i].ke]--;
			rep(j, ch[i].keys.size()) 
				{
					ckeys[ch[i].keys[j]]++;
					if (ch[i].ke==ch[i].keys[j]) totkeysw[ch[i].keys[j]]++;
					//totkeys[ch[i].keys[j]]++;
				}
			if (!(wrkkeys[ch[i].ke]==1 && totkeysw[ch[i].ke]==0)) go(st+1);
			//go(st+1);
			if (solv) return;
			rep(j, ch[i].keys.size()) 
				{
					ckeys[ch[i].keys[j]]--;
					if (ch[i].ke==ch[i].keys[j]) totkeysw[ch[i].keys[j]]--;
					//totkeys[ch[i].keys[j]]--;
				}
			ckeys[ch[i].ke]++;
			wrkkeys[ch[i].ke]++;
			totkeysw[ch[i].ke]++;
			//totkeys[ch[i].ke]++;
			used[i] = 0;
			if (ckeys[ch[i].ke]>=wrkkeys[ch[i].ke]) return;
		}
	return;
}

int main()
{
    fstream fin("D-small-attempt1.in",ifstream::in);
    fstream fout("D-small-attempt1.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
        
		fin >> K >> N;
		cout << tc << " " << K << " " << N << "\n";
		rep(i,ckeys.size()) ckeys[i] = 0;
		rep(i,totkeys.size()) totkeys[i] = 0;
		rep(i,totkeysw.size()) totkeysw[i] = 0;
		rep(i,wrkkeys.size()) wrkkeys[i] = 0;
		trav.resize(N);
		used.resize(N);
		rep(i,used.size()) used[i] = 0;
		ch.resize(N);
		int tmp = 0;
		rep(i, K)
		{
			fin >> tmp;
			ckeys[tmp]++;
			totkeys[tmp]++;
			totkeysw[tmp]++;
		}
		rep(i, N)
		{
			fin >> tmp;
			ch[i].ke = tmp;
			wrkkeys[tmp]++;
			fin >> tmp;
			ch[i].keys.resize(tmp);
			rep(j, ch[i].keys.size()) 
				{
					fin >> ch[i].keys[j];
					totkeys[ch[i].keys[j]]++;
					if (ch[i].keys[j]!=ch[i].ke) totkeysw[ch[i].keys[j]]++;
				}
		}
		solv = 0;
		bool gfl = 1;
		rep(i,totkeys.size()) if (totkeys[i]<wrkkeys[i]) gfl = 0;
		if (gfl) go(0);
		if (!solv) fout << "Case #" << tc << ": IMPOSSIBLE\n";
		else
		{
			fout << "Case #" << tc << ": ";
			rep(i, trav.size()) fout << trav[i]+1 << " ";
			fout << "\n";
		}
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    system("PAUSE");
    return 0;
}
