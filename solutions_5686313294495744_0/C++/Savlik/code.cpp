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
#define ROF(i,n) for (ll i = ((ll)n-1); i >= 0; i--)
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
		ll res = 0;
		int n;
		cin>>n;
		map<string, int> a,b;
		vpii edges;
		FOR(i, n){
			string s, r;
			cin>>s>>r;
			int x,y;
			if(a.find(s)!=a.end()){
				x=a[s];
			}else{
				x=a.size();
				a[s]=x;
			}
			if(b.find(r)!=b.end()){
				y=b[r];
			}else{
				y=b.size();
				b[r]=y;
			}
			edges.pb(mp(x,y));
		}
		int k = a.size();
		int l = b.size();
		FOR(mask, 1<<n){
			vi used(k, 0), used2(l,0);
			int c =0;
			FOR(i, n){
				if((mask>>i) & 1){
					used[edges[i].ff]=1;
					used2[edges[i].ss]=1;
				}else{
					c++;
				}
			}
			bool good = true;
			FOR(i, k){
				if(used[i]==0){
					good = false;
					break;
				}
			}
			FOR(i, l){
				if(used2[i]==0){
					good = false;
					break;
				}
			}
			if(good){
				gmax(res, c);
			}
		}
		cout<<"Case #"<<(t+1)<<": "<<res<<endl;
		
	}
	return 0;
}