#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <assert.h>
#include <math.h>
using namespace std;

const string file = "file";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f; 
const int MODN = 666013;
const double EPS = 0.0000001;

//#define ONLINE_JUDGE

int Count[30],i,T,t,fact[110],N,P[110],len[110],j,sol,total,nr,pos,cnt;
char S[110][110],last,Res[100010];

bool check()
{
    nr = 1;
    cnt = Res[0] - 'a';
    for(int i=1;i<total;i++)
    {
        if(Res[i-1] == Res[i])
        {
            nr++;
            continue;
        }
        if(nr != Count[cnt])return false;
        nr = 1;
        cnt = Res[i] - 'a';
    }
    if(nr != Count[cnt])return false;
    return true;
}


int main()
{
#ifdef ONLINE_JUDGE
	ostream &fout = cout;
	istream &fin = cin;
#else
	fstream fin(infile.c_str(), ios::in | ios::binary);
	fstream fout(outfile.c_str(), ios::out);
#endif	
	
	int T;
	fin >> T;

	fact[0] = 1;
    for(i = 1; i <= 11; i++)
	{
		fact[i] = fact[i-1] * i;
	}

	for(int t = 1; t <= T; t++)
	{
		fin >> N;
		memset(Count,0,sizeof(Count));
        total = 0;
        for(i=1;i<=N;i++)
        {
			string s;
			fin >> s;
			strcpy_s(S[i], s.c_str());
            P[i] = i;
            len[i] = strlen(S[i]);
            total += len[i];
            for(j = 0; j < len[i]; j++)
                Count[S[i][j]-'a']++;
        }
        sol = 0;
        for(i = 1; i <= fact[N]; i++)
        {
            strcpy_s(Res,S [P[1]]);
            for(j=2; j <= N ; j++)
				strcat_s(Res, S[P[j]]);
            sol += check();
            next_permutation(P + 1 , P + N + 1);
        }

		fout << "Case #" << t << ": ";
		fout << sol;
		fout << "\n";

	}

#ifdef ONLINE_JUDGE
#else
    fout.close();
	fin.close();
#endif
}
