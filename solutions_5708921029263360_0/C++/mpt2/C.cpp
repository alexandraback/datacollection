#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <tuple>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef long long ll;

ll J,P,S,K;

map<pair<ll,ll>, ll> JP;
map<pair<ll,ll>, ll> JS;
map<pair<ll,ll>, ll> PS;

vector<tuple<ll,ll,ll>> ergv;

const int MAXN = 190000, MAXC = 1<<29;
struct edge { int dest, capacity, rev; };
vector<edge> adj[MAXN];
int vis[MAXN], target, iter, cap;

void addedge(int x, int y, int c)
{
	adj[x].push_back(edge {y, c, (int)adj[y].size()});
	adj[y].push_back(edge {x, 0, (int)adj[x].size() - 1});
}

bool dfs(int x)
{
	if (x == target) return 1;
	if (vis[x] == iter) return 0;
	vis[x] = iter;
	for (edge& e: adj[x])
	if (e.capacity >= cap && dfs(e.dest))
	{
		e.capacity -= cap;
	 adj[e.dest][e.rev].capacity += cap;
	 return 1;
	}
	return 0;
 }

int maxflow(int S, int T)
{
	cap = MAXC, target = T;
	int flow = 0;
	while(cap) 
	{
		while(++iter, dfs(S))
		flow += cap;
		cap /= 2;
	}
	return flow;
 }

 
 
  
int main()
{
  ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int tt=0;tt<T;tt++)
	{
		cin>>J>>P>>S>>K;
		JP.clear(); JS.clear(); PS.clear();
		ergv.clear();

	for(ll j=1;j<=J;j++)  for(ll p=1;p<=P;p++) JP[make_pair(j, p)] = K;
	for(ll j=1;j<=J;j++)  for(ll s=1;s<=S;s++) JS[make_pair(j, s)] = K;
	for(ll p=1;p<=P;p++)  for(ll s=1;s<=S;s++) PS[make_pair(p, s)] = K;
	
	
	while(true)
	{
		ll maxv = 0;
		pair<ll,ll> jp;
		pair<ll,ll> js;
		pair<ll,ll> ps;
		for(auto p: JP)
		{
			if(maxv < p.second) {maxv = p.second; jp = p.first;}
		}
		if(maxv == 0) break;
		
		maxv = 0;
		for(auto p: JS)
		{
			if(p.first.first != jp.first || find(ergv.begin(), ergv.end(), make_tuple(jp.first, jp.second, p.first.second)) != ergv.end())  continue;
			if(maxv < p.second) {maxv = p.second; js = p.first;}
		}
		if(maxv == 0) break;
		maxv = 0;
		for(auto p: PS)
		{
			if(p.first.first != jp.second || find(ergv.begin(), ergv.end(), make_tuple(jp.first, jp.second, p.first.second)) != ergv.end()) continue;
			if(maxv < p.second) {maxv = p.second; ps = p.first;}
		}
		if(maxv == 0) break;
		
		JS[js]--;
		JP[jp]--;
		PS[ps]--;
		
		ergv.push_back(make_tuple(jp.first, jp.second, js.second));
	}
	
/*
		for(ll j=1;j<=J;j++)  for(ll p=1;p<=P;p++)
		{			
			int jp = j+p*20;
			addedge(source, jp, K);
			for(ll p=1;p<=P;p++)
			{
				
				addedge(j, jp, K);
			}
		}
		
		for(ll j=1;j<=J;j++) 
		{			
			addedge(source, j, K);
			for(ll p=1;p<=P;p++)
			{
				int jp = j+p*20;
				addedge(j, jp, K);
			}
		}
		
		for(ll j=1;j<=J;j++) for(ll p=1;p<=P;p++) 
		{
			int jp = j+p*20;
			for(ll j=1;j<=J;j++) for(ll p=1;p<=P;p++)  for(ll s=1;s<=S;s++) addedge(jp, j+p*20+s*20*20, 1);
		}
		
		for(ll j=1;j<=J;j++) for(ll p=1;p<=P;p++) for(ll s=1;s<=S;s++)
		{
			int jp = j+p*20;
			 for(ll s=1;s<=S;s++) addedge(jp, s*20*20, 1);
		}
		
		for(ll s=1;s<=S;s++) addedge(s*20*20, t, K);
		
		ll erg = maxflow(source,t);
		
		
		
		for(ll j=1;j<=J;j++) for(ll p=1;p<=P;p++)
		{
			int jp = j+p*20;
			for(auto e : adj[jp])
			{
				if(e.capacity >= 1) continue;
				ergv.push_back(make_tuple(j, p, e.dest/(20*20)));
			}
		}			*/
		cout << "Case #" << tt+1 << ": " << ergv.size() << "\n";
		for(auto t : ergv) cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
		
	}
  return 0;
}
