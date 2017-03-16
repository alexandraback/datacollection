//MEDITATION : TOP-MOST source to get TOP-MOST knowledge of the UNIVERSE.baki sab to farzi hai!!!
//(google ABHILASH RUDRA)
//I don't want to study,still I am studying so seriously :( :( ABHI BI MOH MAYA ME PHASA HU :( :(
//I believe one day LORD SHIVA will notch me away from these pall studies :) :)
//I LOVE LORD SHIVA && LORD KRISHNA=>I LOVE every creature of this UNIVERSE!!!
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <bits/stdc++.h>
#define fr(i,n) for(int (i)=0;(i)<(n);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<long long, long long> > vpll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	freopen("in1.txt","r",stdin);
    freopen("aukat1.txt","w",stdout);
	int t;
	bool a[10000];
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		memset(a,0,sizeof a);
		int c,d,v,tmp,ans=0;
		cin>>c>>d>>v;
		for(int k=1;k<=d;++k) {cin>>tmp;a[tmp]=1;}
		float x;
		double dis=sqrt(1+8*v);
		dis-=1.0;
		dis=dis/2.0;
		int upto=ceil(dis);
		for(int j=1;j<=upto;++j)
		{
			if(a[j]==0) ans++;
		}
		
		cout<<"Case #"<<i<<": "<<ans<<"\n";
	}
	//fclose(stdout);
	return 0;
}
//Yours PARTNER


