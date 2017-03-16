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

bool win(const vector<string>& V, char ch, int sRow, int sCol, int dRow, int dCol)
{
	FORD(i, 0, 4)
	{
		if(V[sRow][sCol] != ch && V[sRow][sCol] != 'T')
			return false;
		sRow += dRow;
		sCol += dCol;
	}
	return true;
}

bool win(const vector<string>& V, char ch)
{
	FORD(i, 0, 4)
	{
		if(win(V, ch, i, 0, 0, 1) || win(V, ch, 0, i, 1, 0))
			return true;
	}

	if(win(V, ch, 0, 0, 1, 1) || win(V, ch, 3, 0, -1, 1))
		return true;

	return false;
}

void run()
{
	vector<string> V(4);
	FORS(i, V)
	{
		V[i] = ReadToEndLine();
	}
	ReadToEndLine();

	bool space = false;
	FORS(i, V)
	{
		if(V[i].find('.') != string::npos)
			space = true;
	}

	string res = "Draw";
	if(win(V, 'X'))
	{
		res = "X won";
	}
	else if(win(V, 'O'))
	{
		res = "O won";
	}
	else if(space)
	{
		res = "Game has not completed";
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
