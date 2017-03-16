/*
	In the Name of God
	Aida Sadat Mousavifar
*/

#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <set>
#include <stack>
#include <stdio.h>

using namespace std;

#define MAXN 60
#define X first
#define Y second
#define CLR(x,a) memset(x,a,sizeof(x))
#define FOR(i,b) for(ll i=0;i<(b);i++)
#define FOR1(i,b) for(ll i=1;i<=(b);i++)
#define FORA(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORB(i,b,a) for(ll i=(b);i>=(a);i--)
#define sh(x) cerr<<(#x)<<" = "<<(x)<<endl
#define EPS 0.00001
#define ll long long 
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define sz size()
#define EXIST(a,b) find(ALL(a),(b))!=(a).end()
#define Sort(x) sort(ALL(x))
#define UNIQUE(v) Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define timestamp(x) printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define N 5019
//const double PI = acos(-1);
typedef complex<double> point;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef vector<ll> vi;
typedef vector<vi > vii;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;

string all[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int perm[10]={0,2,6,8,3,4,5,7,9,1};
char c[10]={'Z','W','X','G','T','R','F','V','I','N'};
int main()
{
	int t; cin>>t;//sh(t);
	FOR1(i,t)
	{
		string s; cin>>s;	
		//sh(s);
		vi ans;
		int num[26]={0};
		FOR(j,s.sz) num[s[j]-'A']++;
		//FOR(j,26) {sh((char)('A'+j));sh(num[j]);}
		FOR(j,10)
		{

			int x=num[c[j]-'A'];
			//sh(c[j]);sh(perm[j]);sh(x);
			FOR(k,x) ans.PB(perm[j]);
			FOR(k,all[perm[j]].sz)
			{
				num[all[perm[j]][k]-'A']-=x;
			}
		}
		Sort(ans);
		cout<<"Case #"<<i<<": ";
		FOR(j,ans.sz) cout<<ans[j];
		cout<<endl;
	}
		
}
