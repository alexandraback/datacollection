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
#include <unordered_set>
#include <iomanip>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef long long ll;


int N;
ll P[128][128];
ll M[128][128];

unordered_map<string, ll> Pmap;
unordered_map<string, ll> Mmap;

string flip(string& s)
{
	string ns = s;
	for(size_t i=0;i<ns.size();i++) ns[i] = (ns[i]=='+')?'-':'+';
	reverse(ns.begin(), ns.end());	
	return ns;
}

ll foom(string& s);

ll foop(string& s)
{
	if(s.size() == 0) return 0;
	if(s.size() == 1) return (s[0] == '+')?0:1;
	if(s.find_last_of('-')==string::npos) return 0;
	if(s.find_last_of('+')==string::npos) return 1;
	if(s.find_last_of('-') != s.size()-1) 
	{
		string s2 = s.substr(0, s.find_last_of('-') + 1);
		return foop(s2);
	}
	if(Pmap.count(s)) return Pmap[s];
	ll erg = std::numeric_limits<ll>::max();
//cout<<"P in:\n";	db(s);	
	for(size_t pos=1;pos<s.size();pos++)
	{
		string pre = s.substr(0, pos);
		string suf = s.substr(pos);
		suf = flip(suf);
//db(pre);db(suf);		
		erg = min(erg, foop(suf) + foom(pre) + 1);
//db(erg);		
		erg = min(erg, foom(suf) + foop(pre) + 2);
//db(erg);		
	}
	Pmap[s] = erg;
//cout<<"P out:\n";	db(s);db(erg);
	return erg;
}

ll foom(string& s)
{
	if(s.size() == 0) return 0;
	if(s.size() == 1) return (s[0] == '-')?0:1;
	if(s.find_last_of('-')==string::npos) return 1;
	if(s.find_last_of('+')==string::npos) return 0;
	if(s.find_last_of('+') != s.size()-1) 
	{
		string s2 = s.substr(0, s.find_last_of('+') + 1);		
		return foom(s2);
	}
	if(Mmap.count(s)) return Mmap[s];
	ll erg = std::numeric_limits<ll>::max();
	for(size_t pos=1;pos<s.size();pos++)
	{
		string pre = s.substr(0, pos);
		string suf = s.substr(pos);
		suf = flip(suf);
		erg = min(erg, foop(suf) + foom(pre) + 2);
		erg = min(erg, foom(suf) + foop(pre) + 1);
	}
	Mmap[s] = erg;
	return erg;
}

int main()
{
  ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		string start;
		cin>>start;
		N = start.size();
		Pmap.clear(); Mmap.clear();
		
		cout << "Case #" << t+1 << ": " << foop(start) << "\n";
		
		
		
		
		
		/*
		for(ll i=0;i<N;i++) P[i][i] = (start[i] == '+')?0:1;
		for(ll i=0;i<N;i++) M[i][i] = (start[i] == '-')?0:1;
		for(ll i=1;i<N;i++)
		{
			for(ll j=i-1;j>=0;j--)
			{
				ll minp = std::numeric_limits<ll>::max();
				ll minm = std::numeric_limits<ll>::max();
				if(start[i] == '+')
				{
					minp = min(minp, P[i-1][j]);
					minp = min(minp, 1 + M[i-1][j]);
					minm = min(minm, P[i-1][j] + 1);
					minm = min(minm, M[i-1][j] + 2);
				}
				else
				{
					minp = min(minp, P[i-1][j] + 2);
					minp = min(minp, 1 + M[i-1][j]);
					minm = min(minm, P[i-1][j] + 1);
					minm = min(minm, M[i-1][j]);
				}
				
				for(ll k=i-2;k>=j;k--)
				{
					ll prep = P[k][j];
					ll prem = M[k][j];
					ll sufp = P[i][k+1];
					ll sufm = M[i][k+1];
					minp = min(minp, prep + sufp + 1);
					minp = min(minp, prem + sufm + 1);
					minm = min(minm, prem + sufm + 1);
					minm = min(minm, prep + sufp + 1);
				}
				P[i][j] = minp;
				M[i][j] = minm;
				
				/*
				ll minv = (G[i][i]==1)?(G[i-1][j] + 2):(G[i-1][j]);
				
				bool allm = true; for(ll k=j;k<=i;k++) if(G[k][k]==0) allm = false;
				if(allm) minv = min(minv, 1LL);
				
				for(ll k=i-2;k>=j;k--) minv = min(minv, G[k][j] + G[i][k+1] + 3);
				G[i][j] = minv;*/
				/*
db(i);db(j);db(P[i][j]);db(M[i][j]);
			}
		}*/
				
		//cout << "Case #" << t+1 << ": " << P[N-1][0] << "\n";
	}
  return 0;
}
