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

int gnCase;
char gStr[1024];
ifstream gIn; ofstream gOut;
string ReadToEndLine() { string sLine; getline(gIn, sLine); return sLine; }
// sprintf_s(gStr, "%d", );

typedef vector<pair<int, int64>> Kind;
int N1, N2;
Kind K1(N1), K2(N2);

int64 iter(int n1, int n2, int64 rest1, int64 rest2)
{
	if(n1 >= N1 || n2 >=N2)
		return 0;

	int64 sum=0;
	if(K1[n1].first == K2[n2].first)
	{
		if(rest1 > rest2)
		{
			sum += rest2;
			rest1 -= rest2;
			rest2 = 0;

		}
		else
		{
			sum += rest1;
			rest2 -= rest1;
			rest1 = 0;
		}
	}

	int64 s1 = (n1 == N1-1) ? 0 : iter(n1+1, n2, K1[n1+1].second, rest2);
	int64 s2 = (n2 == N2-1) ? 0 : iter(n1, n2+1, rest1, K2[n2+1].second);
	return sum + max(s1, s2);
}

void run()
{
	gIn >> N1 >> N2;
	K1.resize(N1);
	K2.resize(N2);
	FORS(i, K1)
	{
		int kind; int64 count;
		gIn >> count >> kind;
		K1[i] = MP(kind, count);
	}
	FORS(i, K2)
	{
		int kind; int64 count;
		gIn >> count >> kind;
		K2[i] = MP(kind, count);
	}

	int64 nRes = iter(0, 0, K1[0].second, K2[0].second);

  gOut << "Case #" << gnCase << ": ";
  gOut << nRes;
  gOut << endl;
}

void main(int argc, char *argv[])
{
  string sFile(argv[1]);
  gIn.open(sFile.c_str());
  sFile.resize(SIZE(sFile)-2);
  sFile += "out";
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
