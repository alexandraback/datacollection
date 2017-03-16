//Grzegorz Prusak
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)

template<typename T> void checkmin(T &a, T b){ if(a>b) a = b; }

typedef long long LL;

enum { n_max = 5000 };

std::vector<std::string> D;

int dyn[5][n_max];

std::string input;

void diff(int i, int j, const std::string &v)
{
	if(j+v.size()>input.size()) return;
	int l = -i-1; int c = dyn[i][j];
	REP(x,v.size()) if(v[x]!=input[j+x])
	{
		if(x-l<5) return;
		l = x; c++;
	}
	checkmin(dyn[std::min<int>(v.size()-l-1,4)][j+v.size()],c);
}

int main()
{
	std::ifstream f("dict.txt");
	for(std::string s; f >> s;) D.push_back(s);
	f.close();

	int t; std::cin >> t;
	FOR(_,1,t)
	{
		REP(i,5) REP(j,n_max) dyn[i][j] = n_max;
		dyn[4][0] = 0;
		std::cin >> input;
		REP(j,input.size()) REP(i,5) REP(k,D.size()) diff(i,j,D[k]);
		int res = n_max;
		REP(i,5) checkmin(res,dyn[i][input.size()]);
		printf("Case #%d: %d\n",_,res);
	}

	return 0;
}

