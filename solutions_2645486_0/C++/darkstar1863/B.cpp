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

using namespace std;

#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
#define MP(X,Y) make_pair(X,Y)//NOTES:MP(
#define FORD(i, a, b) for(int i=(a); i<(b); i++)
#define FORS(i, a) for(int i=(0); i<SIZE(a); i++)
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
#define two(X) (1<<(X))//NOTES:two(
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(
const double pi=acos(-1.0);//NOTES:pi
const double eps=1e-11;//NOTES:eps
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
typedef pair<int,int> ipair;//NOTES:ipair
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(

template<class T> void setbit(T& v, int position)    { v |= (T)1 << position; }
template<class T> void unsetbit(T& v, int position)  { v &= ~((T)1 << position); }
template<class T> void togglebit(T& v, int position) { v ^= (T)1 << position; }
template<class T> bool isbit(T v, int position) { return (v & ((T)1 << position)) != 0; }

int gnCase;
char gStr[1024];
ifstream gIn; ofstream gOut;
string ReadToEndLine() { string sLine; getline(gIn, sLine); return sLine; }
// sprintf_s(gStr, "%d", );

void run()
{
	int E, R, N;
	gIn >> E >> R >> N;

	vector<int> V(N);
	FORS(i, V)
		gIn >> V[i];

	vector<vector<int>> M(N, vector<int>(E+1, 0));
	FORD(i, 0, E+1)
	{
		M[0][i] = (E - i) * V[0];
	}

	FORD(v, 1, N)
	{
		FORD(i, 0, E+1)
		{
			int m = -1;
			FORD(prev, 0, E+1)
			{
				int after = min(prev + R, E);
				if(after < i)
					continue;
				int cur = (after-i)*V[v] + M[v-1][prev];
				m = max(m, cur);
			}
			M[v][i] = m;
		}
	}

	int res = -1;
	FORD(i, 0, E+1)
	{
		res = max(res, M[N-1][i]);
	}

    gOut << "Case #" << gnCase << ": ";
    gOut << res;
    gOut << endl;
}

void main(int argc, char *argv[])
{
    string sFile(__FILE__);
    sFile.resize(SIZE(sFile)-4);
	sFile += "-test.in";
	if(argc >= 2)
	{
		sFile = argv[1];
	}
    gIn.open(sFile.c_str());

    sFile += ".out";
    gOut.open(sFile.c_str());

    int CASES;
    gIn >> CASES;
    ReadToEndLine();
    FORD(i, 0, CASES)
    {
        gnCase=i+1;
        run();
    }

    if(gOut.tellp() < 1000)
    {
        gOut.close();
        ifstream fOut(sFile.c_str());
        cout << fOut.rdbuf();
    }
    cout << "Ok" << endl;
    getchar();
}
