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

struct tribe
{
	int d, n, w, e, delta_d, delta_p;
	int64 s, delta_s;
};

inline int m(int i)
{
	return i+5000;
}

vector<int> next1(vector<tribe>& T)
{
	int next = -1;
	FORS(i, T)
	{
		if(T[i].n == 0)
			continue;
		if(next == -1)
			next = i;
		else if(T[i].d < T[next].d)
			next = i;
	}

	vector<int> res;
	if(next == -1)
		return res;

	FORS(i, T)
	{
		if(T[i].n > 0 && T[i].d == T[next].d)
		{
			T[i].d += T[i].delta_d;
			--T[i].n;
			res.push_back(i);
		}
	}
	return res;
}

void run()
{
	int N;
	gIn >> N;

	vector<tribe> T(N);
	FORS(i, T)
	{
		tribe t;
		gIn >> t.d >> t.n >> t.w >> t.e >> t.s >> t.delta_d >> t.delta_p >> t.delta_s;
		T[i] = t;
	}

	int res = 0;
	vector<int64> H(10000, 0);

	vector<int> next = next1(T);
	while(!next.empty())
	{
		vector<int64> N(H);

		FORS(i, next)
		{
			bool Good = false;
			int index = next[i];

			FORD(seg, T[index].w, T[index].e)
			{
				if(H[m(seg)] < T[index].s)
				{
					Good = true;
				}
				N[m(seg)] = max(N[m(seg)], T[index].s);
			}

			if(Good)
				++res;
			T[index].w += T[index].delta_p;
			T[index].e += T[index].delta_p;
			T[index].s += T[index].delta_s;
		}

		H = N;
		next = next1(T);
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
