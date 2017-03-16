#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <fstream>
#include <queue>
#include <cstring>
#include <string>
#include <complex>
#include <unordered_map>
#include <valarray>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define FOREACH(it,x) for (auto it = (x).begin(); it!=(x).end(); ++it) 
#define sz(x) (int)(x).size()
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define ROF(i,n) for (ll i = (ll)(n-1); i >= 0; i--)
#define FOR1(i,n) for (ll i = 1; i < ll(n); i++)
#define REP(i,a,b) for (ll i = a; i < ll(b); i++)
#define READ(a) ll a; scanf("%d", &a);
#define READV(v,n) vi v(n);FOR(i,n){scanf("%d", &v[i]);}
#define WRITE(v) FOR(i,sz(v))cout<<v[i]<<" ";
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ff first
#define ss second
#define oo ((1LL<<62)+((1LL<<31)-1))
#define MOD 1000000007ll
const double PI = std::atan(1.0)*4;

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

//#include <windows.h>
//#include <thread>
//#include <chrono>

int main(int argc, char *argv[]){
	int T;
	cin>>T;
	FOR(t, T){
		vi v(10,0);
		vi p(256,0);
		string s;
		cin>>s;
		FOR(i, s.length()){
			p[s[i]]++;
		}

		v[6]=p['X'];
		p['S']-=p['X'];
		p['I']-=p['X'];
		p['X']-=p['X'];
		
		v[4]=p['U'];
		p['F']-=p['U'];
		p['O']-=p['U'];
		p['R']-=p['U'];
		p['U']-=p['U'];
		
		v[8]=p['G'];
		p['E']-=p['G'];
		p['I']-=p['G'];
		p['H']-=p['G'];
		p['T']-=p['G'];
		p['G']-=p['G'];
		
		v[2]=p['W'];
		p['T']-=p['W'];
		p['O']-=p['W'];
		p['W']-=p['W'];

		v[3]=p['H'];
		p['T']-=p['H'];
		p['R']-=p['H'];
		p['E']-=p['H'];
		p['E']-=p['H'];
		p['H']-=p['H'];
		
		v[7]=p['S'];
		p['E']-=p['S'];
		p['V']-=p['S'];
		p['E']-=p['S'];
		p['N']-=p['S'];
		p['S']-=p['S'];

		v[5]=p['V'];
		p['F']-=p['V'];
		p['I']-=p['V'];
		p['E']-=p['V'];
		p['V']-=p['V'];

		v[0]=p['R'];
		p['Z']-=p['R'];
		p['E']-=p['R'];
		p['O']-=p['R'];
		p['R']-=p['R'];

		v[1]=p['O'];
		v[9]=p['I'];

		cout<<"Case #"<<(t+1)<<": ";
		FOR(i, 10){
			FOR(j, v[i]){
				cout<<i;
			}
		}
		cout<<endl;
	}
	return 0;
}