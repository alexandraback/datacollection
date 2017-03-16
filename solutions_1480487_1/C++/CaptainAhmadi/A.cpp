
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

//////////////

const int maxn= 300;

int n;
double s[maxn];

void clear() {
}

void solve(int cnum) {
  cin>>n;

  FOR (i,n) cin>>s[i];
  double x=0;
  FOR (i,n) x+=s[i];

  cout<<"Case #"<<cnum<<":";

  for (int i=0;i<n;i++) {
	double lo=0;
	double hi=1;

	while (hi-lo>1e-10) {
	  double m=(hi+lo)/2;

	  double val=s[i]+x*m;

	  double sum=m;
	  for (int j=0;j<n;j++) {
		if (i!=j && val>s[j])
		  sum+=(val-s[j])/x;
	  }
	  if (sum<1) {
		//can be eliminated
		lo=m;
	  } else
		hi=m;
	}

	double ans=(lo+hi)/2;
	ans*=100;

	char e[100];
	sprintf(e,"%.6f",ans);
	cout<<" "<<e;
  }
  cout<<endl;
}

int main() {
  int nt;
  cin>>nt;
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
