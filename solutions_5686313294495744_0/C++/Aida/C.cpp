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


int main()
{
	int t; cin>>t;
	FOR1(cs,t)
	{
		map<string, int> fr;
		map<string, int> sec;
		
		int n, n1=1,n2=1,ans=20; cin>>n;

		vpii all;
		FOR(i,n)
		{
			string a,b; cin>>a>>b;
			if(fr[a]==0) fr[a]=n1++;
			if(sec[b]==0) sec[b]=n2++; 
			all.PB(pii(fr[a],sec[b]));
		}
		n1--;n2--;
		for(int i=0; i<(1<<n); i++)
		{
			set<int> frs; set<int> secs;
			int num=0;
			for(int j=0; j<n; j++)
			{
				if((i&(1<<j))) 
				{
					frs.insert(all[j].X);
					secs.insert(all[j].Y);
					num++;
				}
			}
			if(frs.sz==n1 && secs.sz==n2)
				ans=min(ans,num);
		}
		cout<<"Case #"<<cs<<": "<<(n-ans)<<endl;
	}
}
