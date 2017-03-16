#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

#define MR 20
int zbior[MR], p[MR], k[MR];
int ileMax;

int t[MR];

char s[MR], s1[MR];

double pr;

string text;

int ile(string text, string pattern)
{
	int ile = 0;
	FORQ(i,0,(int)text.length()-(int)pattern.length())
		if(text.substr(i,pattern.length()) == pattern) ile++;

	return ile;
}

void go(int n)
{
	string pattern = "";
	REP(i,n+1) pattern += s[zbior[i]];
	int pom = ile(pattern, text);
	ileMax = max(ileMax, pom);
	t[pom]++;
}//do

void find(int x, int n, int zbior[])    //rekurencyjnie znajdz podzbiory
{
	while(true)
	{
		if (x == n)
			go(n);
		else find(x+1, n, zbior);		//najpierw idz do nast pozycji
		zbior[x]++;						//zwieksz licznik
		if(zbior[x] > k[x])				//musisz sie cofnac	
		{
			zbior[x] = p[x];
			return;
		}
	}
}//find

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		REP(i,MR) t[i] = 0;
		ileMax = 0;
		double res = 0;
		int K, L, S;
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s%s", s, s1);
		text = string(s1);
		REP(i,S) p[i] = 0;
		REP(i,S) k[i] = K-1;
		REP(i,S) zbior[i] = 0;		
		int pot = 1;
		REP(i,S) pot *= K;
		pr = 1/(double)pot;
		find(0, S-1, zbior);

		REP(i,MR) res += t[i]*i*pr;
		printf("Case #%d: %.10lf\n", c+1, ileMax-res);
	}
	return 0;
}