#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stdio.h>
#include <valarray>



#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble; 

using namespace std;



void imprimirVector (vector<tint> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

tint toNumber (string s)
{
	tint Number;
	if ( ! (istringstream(s) >> Number) ) Number = 0; // el string vacio lo manda al cero
	return Number;
}

string toString (tint number)
{    
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}


void appender (string coder, vector<string> &coderScore)
{
	tint n = coder.size();
	bool flag = true;
	forn(i,n)
		if (coder[i] == '?')
		{
			flag = false;
			forn(j,10)
			{
				coder[i] = '0'+j;
				appender(coder,coderScore);
			}
		}
	if (flag)
		coderScore.push_back(coder);
		
}

struct Score
{
	string coder,jammer;
	Score(string cc, string jj)
	{
		coder = cc;
		jammer = jj;
	}
};

bool operator < (Score s1, Score s2)
{
	return make_tuple(abs(toNumber(s1.coder)-toNumber(s1.jammer)), s1.coder,s1.jammer) < make_tuple(abs(toNumber(s2.coder)-toNumber(s2.jammer)), s2.coder,s2.jammer);
}

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
		assert(freopen("salida.out", "w", stdout));
	#endif
	ios_base::sync_with_stdio(0);
	tint t;
	cin >> t;
	forsn(caso,1,t+1)
	{
		string c,j;
		cin >> c >> j;
		vector<string> coderScore;
		vector<string> jammerScore;
		appender(c,coderScore);
		appender(j,jammerScore);
		Score bestSolution = Score(coderScore[0],jammerScore[0]);
		forn(i,coderScore.size())
		forn(k,jammerScore.size())
		{
			Score score = Score(coderScore[i],jammerScore[k]);
			bestSolution = min(bestSolution,score);
		}
		cout << "Case #" << caso << ": " << bestSolution.coder << " " << bestSolution.jammer << endl;
	}
	return 0;
}




