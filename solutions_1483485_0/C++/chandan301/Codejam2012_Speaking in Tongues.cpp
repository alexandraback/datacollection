//============================================================================
// Name        : Codejam2012_Speaking.cpp
// Author      : Chandan Giri
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>

//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define s(n)                                    scanf("%d",&n)
#define sl(n)                                   scanf("%lld",&n)
#define sf(n)                                   scanf("%lf",&n)
#define ss(n)                                   scanf("%s",n)
#define p(n)                                    printf("%d\n",n)
#define pl(n)                                   printf("%lld\n",n)
#define maX(a,b)                                ((a)>(b)?(a):(b))
#define miN(a,b)                                ((a)<(b)?(a):(b))
#define abS(x)                                  ((x)<0?-(x):(x))
#define FOR(i,a,b)                              for(int i=a;i<b;i++)
#define mp                                      make_pair
#define FF                                      first
#define SS                                      second
#define pb                                      push_back
#define SZ(v)                                   ((int)(v.size()))
#define all(x)                                  x.begin(),x.end()
#define INF                                     (int)1e9
#define LINF                                    (long long)1e18
#define EPS                                     1e-9
#define MOD                                     ((1 << 30)-1))
#define MSZ                                     80

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;

//=========================================================================================

/* Main Code begins here */

string M = "yhesocvxduiglbkrztnwjpfmaq";

string solve(char S[])
{
	int i,l;
	string sol="";
	l = strlen(S);
	for(i=0; i<l; i++)
	{

		if(S[i] != ' ')
			sol += M[S[i]-'a'];
		else
			sol += S[i];
	}
	return sol;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w+", stdout);
	int t,i=1;
	char S[1010];
	string sol;
	scanf("%d\n",&t);
	while(i<=t)
	{
		gets(S);
		sol = solve(S);
		cout << "Case #"<<i<<": "<<sol<<endl;
		i++;
	}
	return 0;
}
