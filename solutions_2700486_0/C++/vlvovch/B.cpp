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
int X;
int Y;

struct conf
{
	vector< vector<int> > diam;
	double prob;
	conf() {}
	conf(const vector< vector<int> > & diam, double prob):diam(diam), prob(prob) { }
};

vector<conf> curc;

int main()
{
    fstream fin("B-small-attempt0.in",ifstream::in);
    fstream fout("B-small-attempt0.out",ofstream::out);
    fin >> T;
	for(int tc=1;tc<=T;tc++)
    {
		fin >> N >> X >> Y;
		curc.resize(0);
		vector< vector<int> > stc(1);
		stc[0].resize(1);
		stc[0][0] = 0;
		curc.push_back(conf(stc, 1.));
		for(int i=2;i<=N;++i)
		{
			vector<conf> next(0);
			rep(k, curc.size())
			{
				int stY = curc[k].diam.size() + (curc[k].diam.size()%2);
				int stX = 0;
				if (curc[k].diam.size()-1<stY-1)
				{
					int tstY = stY-1;
					int tstX = stX-1;
					while(1)
					{
						if (tstY==0) break;
						if (find(curc[k].diam[tstY-1].begin(), curc[k].diam[tstY-1].end(), tstX-1)!=curc[k].diam[tstY-1].end()
							&& find(curc[k].diam[tstY-1].begin(), curc[k].diam[tstY-1].end(), tstX+1)!=curc[k].diam[tstY-1].end()) break;
						if (find(curc[k].diam[tstY-1].begin(), curc[k].diam[tstY-1].end(), tstX-1)!=curc[k].diam[tstY-1].end())
						{
							tstY--;
							tstX++;
							continue;
						}
						else
						{
							tstY--;
							tstX--;
							continue;
						}
					}
					conf tmp = curc[k];
					if (tstY<tmp.diam.size()) tmp.diam[tstY].push_back(tstX);
					else 
					{
						vector<int> tmp1(0);
						tmp1.push_back(tstX);
						tmp.diam.push_back(tmp1);
					}
					tmp.prob /= 2.;
					next.push_back(tmp);

					tstY = stY-1;
					tstX = stX+1;
					while(1)
					{
						if (tstY==0) break;
						if (find(curc[k].diam[tstY-1].begin(), curc[k].diam[tstY-1].end(), tstX-1)!=curc[k].diam[tstY-1].end()
							&& find(curc[k].diam[tstY-1].begin(), curc[k].diam[tstY-1].end(), tstX+1)!=curc[k].diam[tstY-1].end()) break;
						if (find(curc[k].diam[tstY-1].begin(), curc[k].diam[tstY-1].end(), tstX-1)!=curc[k].diam[tstY-1].end())
						{
							tstY--;
							tstX++;
							continue;
						}
						else
						{
							tstY--;
							tstX--;
							continue;
						}
					}
					tmp = curc[k];
					if (tstY<tmp.diam.size()) tmp.diam[tstY].push_back(tstX);
					else 
					{
						vector<int> tmp1(0);
						tmp1.push_back(tstX);
						tmp.diam.push_back(tmp1);
					}
					tmp.prob /= 2.;
					next.push_back(tmp);
				}
				else
				{
					while(1)
					{
						if (stY==0) break;
						if (find(curc[k].diam[stY-1].begin(), curc[k].diam[stY-1].end(), stX-1)!=curc[k].diam[stY-1].end()
							&& find(curc[k].diam[stY-1].begin(), curc[k].diam[stY-1].end(), stX+1)!=curc[k].diam[stY-1].end()) break;
						if (find(curc[k].diam[stY-1].begin(), curc[k].diam[stY-1].end(), stX-1)!=curc[k].diam[stY-1].end())
						{
							stY--;
							stX++;
							continue;
						}
						else
						{
							stY--;
							stX--;
							continue;
						}
					}
					conf tmp = curc[k];
					if (stY<tmp.diam.size()) tmp.diam[stY].push_back(stX);
					else 
					{
						vector<int> tmp1(0);
						tmp1.push_back(stX);
						tmp.diam.push_back(tmp1);
					}
					next.push_back(tmp);
				}
			}
			curc.resize(0);
			map< vector< vector<int> >, int> confmap;
			confmap.clear();
			rep(j, next.size())
			{
				if (confmap.count(next[j].diam)==0)
				{
					curc.push_back(next[j]);
					confmap[next[j].diam] = curc.size()-1;
				}
				else curc[confmap[next[j].diam]].prob += next[j].prob;
			}
		}
		double ret = 0.;
		rep(i, curc.size())
		{
			if (curc[i].diam.size()>Y && find(curc[i].diam[Y].begin(), curc[i].diam[Y].end(), X)!=curc[i].diam[Y].end())
				ret += curc[i].prob;
		}
        fout << "Case #" << tc << ": " << ret << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    //system("PAUSE");
    return 0;
}
