#include "bits/stdc++.h"

using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

#define MAXV 100005
int n,m; 
vi adj[MAXV]; 
int para[MAXV]; 
bool vis[MAXV];
vector<pair<string, string> > input;
set<string> wordsL, wordsR;
map<string, int> ML, MR;

bool augment (int v) {         // 1 <= v <= n (lub v = -1)
   if (v == -1) return 1;
   if (vis[v]++) return 0;
   FOREACH(x,adj[v]) {
      if (augment(para[*x])) { para[*x] = v; para[v] = *x; return 1; }
   }
   return 0;
}

// wierzchołki z pierwszej części mają mieć nry 1..n, z drugiej - n+1..n+m
// PRE: ustawić n,m,adj (adj wystarczy mieć wypełnione dla wierzchołków 1..n), oraz

// stałą MAXV = maksymalne n+m
int matching () {
   FORI(i,n+m) para[i] = -1;
   int w = 0;
   FORI(i,n) {
      FORI(j,n) vis[j] = 0;
      w += augment(i);
   }
   return w;
}

void solve() {
   input.clear(); wordsL.clear(); wordsR.clear(); ML.clear(); MR.clear();
   FOR(i,MAXV) adj[i].clear();
   int k;
   cin>>k;
   FOR(i,k) {
      string l, r;
      cin>>l>>r;
      input.pb(mp(l,r));
      wordsL.insert(l); wordsR.insert(r);
   }
   int cnt = 1;
   for(set<string>::iterator it = wordsL.begin(); it != wordsL.end(); it++) {
      ML[*it] = cnt;
      cnt++;
   }
   cnt = 1;
   for(set<string>::iterator it = wordsR.begin(); it != wordsR.end(); it++) {
      MR[*it] = cnt;
      cnt++;
   }
   n = wordsL.size();
   m = wordsR.size();
   FOR(i, input.size()) {
      adj[ML[input[i].fi]].pb(n+MR[input[i].se]);
      adj[n+MR[input[i].se]].pb(ML[input[i].fi]);
   }
   /*cout<<"\nG: \n";
   REP(i,1,n+m) {
      cout<<i<<": ";
      FOR(j,adj[i].size()) cout<<adj[i][j]<<" ";
      cout<<endl;
   }*/
   int match = matching();
   //cout<<"match "<<match<<endl;
   cout<<k - (n+m-match)<<"\n";
}

int main()
{
   ios_base::sync_with_stdio(0);

   int t;
   cin>>t;
   for(int i=1; i<=t; i++) {
      cout<<"Case #"<<i<<": ";
      solve();
   }  
   return 0;
}
