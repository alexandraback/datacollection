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

struct Tower
{
	Tower() {}
	Tower(int n1, int n2) : N1(n1), N2(n2), Is1(false), Is2(false) {}
	int N1, N2;
	bool Is1, Is2;
};

void run()
{
	int N;
	gIn >> N;

	vector<Tower> V(N);
	FORS(i, V)
	{
		int n1, n2;
		gIn >> n1 >> n2;
		V[i] = Tower(n1, n2);
	}

	int nGained = 0, nIters = 0;
	bool bNeedProcessed = true;
	bool bFaled = false;
	while(bNeedProcessed)
	{
		bNeedProcessed = false;

		int nIndex1 = -1;
		int nIndex2 = -1;
		int nMaxDist = 0;
		FORS(i, V)
		{
			if(V[i].Is2)
				continue;

			bNeedProcessed = true;
			if(V[i].N2 <= nGained)
			{
				nIndex2 = i;
				break;
			}
			if(V[i].N1 <= nGained && !V[i].Is1)
			{
				if(nMaxDist < V[i].N2-V[i].N1)
				{
					nIndex1 = i;
					nMaxDist = V[i].N2-V[i].N1;
				}
				continue;
			}
		}

		if(!bNeedProcessed)
			break;
		if(nIndex1 < 0 && nIndex2 < 0)
		{
			bFaled = true;
			break;
		}
		if(nIndex2 >= 0)
		{
			V[nIndex2].Is2 = true;
			nGained += V[nIndex2].Is1 ? 1 : 2;
		}
		else
		{
			V[nIndex1].Is1 = true;
			nGained += 1;
		}
		++nIters;
	}

  gOut << "Case #" << gnCase << ": ";
  if(bFaled)
	gOut << "Too Bad";
  else
	gOut << nIters;
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
