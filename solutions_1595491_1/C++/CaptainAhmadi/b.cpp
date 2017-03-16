
//Written by Alex H Ahmadi (alex@hamedahmadi.com)

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
using namespace std;

#define FOR(i,n) for (int i=0;i<(n);i++)
#define FORIT(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define P(x) cerr<<#x<<" = "<<x<<endl
#define pb push_back

#define zer(x) memset(x,0,sizeof(x));
#define isin(x,s) (s.find(x)!=s.end())

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

const int maxn=110;
int d[maxn][maxn];
int n;
int t[maxn];
int p;

/*
struct Trip {
  int x,y,z;
  Trip () {};
  Trip(int i, int j, int k):x(i),y(j),z(k) {}
  };*/

/*vector <Trip> trip[40];
  vi <Trip> strip[40];*/
bool trip[40][12];
bool strip[40][12];

void init() {
  for (int i=0;i<=10;i++)
	for (int j=i;j<=10;j++)
	  for (int k=j;k<=10;k++) {
		int sum=i+j+k;
		if (k-i<=1) {
		  //trip[sum]=1;
		  for (int l=0;l<=k;l++) trip[sum][l]=1;
		}
		if (k-i==2) {
		  for (int l=0;l<=k;l++)
			strip[sum][l]=1;
		}
	  }
}

void clear() {
  memset(d,-1,sizeof d);
}

int go(int n, int s) {
  if (n<=0) return 0;
  //if (s>n) return 0;
  if (d[n][s]>=0) return d[n][s];
  int sum=t[n-1];

  int best=0;
  //no surp
  //hi
  if (trip[sum][p])
	best=max(best, go(n-1,s)+1);
  else {
	//lo
	best=max(best, go(n-1,s));
  }
  
  //surp
  if (s && strip[sum][p]) 
	best=max(best, go(n-1,s-1)+1);

  return d[n][s]=best;
}

void solve(int cnum) {
  cout<<"Case #"<<cnum<<": ";

  int s;
  cin>>n;
  cin>>s>>p;
  FOR (i,n) cin>>t[i];

  int ans=go(n,s);
  
  cout<<ans<<endl;
}

int main() {
  init();
  int nt;
  cin>>nt;
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
