/*
	In the Name of God
	Aida Sadat Mousavi
*/

#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
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
#define ull unsigned long long int
#define ll long long 
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define sz size()
#define EXIST(a,b) find(ALL(a),(b))!=(a).end()
#define Sort(x) sort(ALL(x))
#define UNIQUE(v) Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define timestamp(x) printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define N 55
//const double PI = acos(-1);
typedef complex<double> point;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef vector<ll> vi;
typedef vector<vi > vii;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;

int mat[N][N];
#define cout fout
int main()
{
	ofstream fout;
  	fout.open ("Banssmall.txt");
  	int T; cin>>T;
  	FOR1(cs,T)
  	{
  		ll b,m; cin>>b>>m;
  		cout<<"Case #"<<cs<<": "; 
		if(m>(1<<(b-2))) 
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		cout<<"POSSIBLE\n";
		CLR(mat,0);
		FORA(i,1,N-1)
			FORA(j,i+1,N-1)
			{
				mat[i][j]=1;
				//cout<<mat[i][j];
			}
		//sh(m);
		if(m==(1LL<<(b-2))) 
		{
			FORA(i,1,b-1) mat[0][i]=1;	
		}
		else 
		{
			for(ll i=0; i<55; i++)
			{
				if(m&(1LL<<i))
				{
					//sh(i);
					mat[0][b-2-i]=1;
				}	
			}
		}
		FOR(i,b)
		{
			FOR(j,b)
				cout<<mat[i][j];
			cout<<endl;
		}
	}
	fout.close();
}
