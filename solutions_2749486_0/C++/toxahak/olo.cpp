#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iomanip> 
#include <ctime>
using namespace std;

#define sz size()
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second 

typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii; 
const int INF=~(1<<31);
const double eps=1e-6;
 
const long double PI = 3.1415926535;
 
 
int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  int n;
  int q,Q;
  cin>>Q;
  FOR(q,1,Q){
	printf("Case #%d: ",q);
	int x,y;
	cin>>x>>y;
	map<pii,int> M;
	map<pii,char> P;
	queue<pii> qu;
	qu.push(pii(0,0));
	M[pii(0,0)]=0;
	P[pii(0,0)]=0;
	while(M.count(pii(x,y))==0){
		pii g=qu.front(); qu.pop();
		int h=M[g];
		
		{
			pii z=g;
			z.first+=h+1;
			if(M.count(z)==0){
				M[z]=h+1;
				P[z]=1;
				qu.push(z);
			}
		}
		{
			pii z=g;
			z.first-=h+1;
			if(M.count(z)==0){
				M[z]=h+1;
				P[z]=2;
				qu.push(z);
			}
		}
		{
			pii z=g;
			z.second+=h+1;
			if(M.count(z)==0){
				M[z]=h+1;
				P[z]=3;
				qu.push(z);
			}
		}
		{
			pii z=g;
			z.second-=h+1;
			if(M.count(z)==0){
				M[z]=h+1;
				P[z]=4;
				qu.push(z);
			}
		}
	}
	string ans;
	pii g=pii(x,y);
		int h=M[g];
	while(g!=pii(0,0)){
		char c=P[g];
		if(c==1){
			ans.pb('E');
			g.first-=h;
		}
		if(c==2){
			ans.pb('W');
			g.first+=h;
		}
		if(c==3){
			ans.pb('N');
			g.second-=h;
		}
		if(c==4){
			ans.pb('S');
			g.second+=h;
		}
		h--;
	}
	reverse(all(ans));
	cout<<ans<<'\n';
  }
  return 0;
}
