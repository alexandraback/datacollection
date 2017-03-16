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
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i = (a) ; i < (b) ; i ++)
#define REP(i,n) FOR(i, 0, n)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define pb push_back

string fsmall = "A-small-attempt0.in";
string flarge = "A-large.in";
ofstream fout;
ifstream fin;
int flag[1001];
int coun[1001];
int mat[1001][1001];
int n,m,k;

int expend(int x)
{
	flag[x] = 1;
	FOR(i,1,n+1)
		if (mat[x][i] > 0)
		{
			if (coun[i] > 0)
			{
				return -1;
			}else
			{
				coun[i] = 1;
				if (expend(i) < 0)
					return -1;
			}
		}
	return 0;
}

void func()
{
	int t = 1;
	memset(flag, 0, sizeof(flag));
	memset(mat, 0, sizeof(mat));
	fin>>n;
	FOR(i,1,n+1)
	{
		fin>>m;
		REP(j,m)
		{
			fin>>k;
			mat[i][k] = 1;
		}
	}
	FOR(i,1,n+1)
	{
		if (flag[i] > 0)
		{
			continue;
		}
		memset(coun, 0, sizeof(coun));
		if (expend(i) < 0)
		{
			t = 0;
			break;
		}
	}
	if (t == 0)
	{
		fout<<" Yes";
	}else
		fout<<" No";
}

int main()
{
	int n;
	fin.open(fsmall.c_str());
	fout.open("out.txt");
	fin>>n;
	REP(i,n)
	{
		fout<<"Case #"<<i+1<<":";

		func();

		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;

}