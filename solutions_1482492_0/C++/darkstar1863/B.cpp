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

double D;
int N, A;
vector<double> t;
vector<double> x;
vector<double> a;

void run()
{
	gIn >> D >> N >> A;
	t.resize(N);
	x.resize(N);
	a.resize(A);
	FORD(i, 0, N)
	{
		gIn >> t[i];
		gIn >> x[i];
	}
	FORS(i, a)
	{
		gIn >> a[i];
	}

	if(N>2)
		return;

	gOut << "Case #" << gnCase << ": " << endl;
	FORS(acsIndex, a)
	{
		double acs = a[acsIndex];
		if(N==1)
		{
			// drive as fast as we can
			double t = sqrt(2*D/acs);
			sprintf_s(gStr, "%.6f", t);
			gOut << gStr << endl;
		}
		else
		{
			double v = (x[1] - x[0]) / (t[1]-t[0]);
			double desc = 4*v*v + 8*acs*x[0];
			double tMeet = (2.0*v+sqrt(desc)) / (2.0*acs);

			double dMeet = acs*tMeet*tMeet / 2.0;
			double t = sqrt(2*D/acs);
			if(dMeet < D && x[0] < D)
			{
				t = (D-x[0]) / v;
			}
			sprintf_s(gStr, "%.6f", t);
			gOut << gStr << endl;
		}
	}

//  gOut << ;
//  gOut << endl;
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
