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

struct Node
{
	Node() : flag(false) {}
	bool flag;
	vector<int> C;
};

void clear(vector<Node>& Nodes)
{
	FORS(i, Nodes)
	{
		Nodes[i].flag = false;
	}
}

void run()
{
	int N;
	gIn >> N;

	vector<Node> Nodes(N);
	vector<bool> Root(N, true);
	FORS(i, Nodes)
	{
		int M;
		gIn >> M;
		Nodes[i].C.resize(M);
		FORS(j, Nodes[i].C)
		{
			int c;
			gIn >> c;
			Nodes[i].C[j] = c-1;
			Root[c-1] = false;
		}
	}

	bool bYes = false;
	FORS(i, Root)
	{
		if(bYes)
			break;
		if(!Root[i])
			continue;
		clear(Nodes);

		queue<int> Q;
		Q.push(i);
		while(!Q.empty())
		{
			int cur = Q.front();
			Q.pop();

			if(Nodes[cur].flag)
			{
				bYes = true;
				break;
			}
			Nodes[cur].flag = true;

			FORS(j, Nodes[cur].C)
				Q.push(Nodes[cur].C[j]);
		}
	}

  gOut << "Case #" << gnCase << ": ";
  gOut << (bYes ? "Yes" : "No");
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
