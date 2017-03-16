
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

const int maxn=600;

int n;
map<int,int> m;
int a[maxn];

void clear() {
  m.clear();
}


void solve(int cnum) {
  cout<<"Case #"<<cnum<<":"<<endl;

  int n;
  cin>>n;
  FOR (i,n) cin>>a[i];
  FOR (x,(1<<n)) {
	int sum=0;
	FOR (i,n) if (x&(1<<i)) sum+=a[i];
	if (m.find(sum)!=m.end()) {
	  int y=m[sum];
	  FOR (i,n) if (y&(1<<i)) cout<<a[i]<<" "; cout<<endl;
	  FOR (i,n) if (x&(1<<i)) cout<<a[i]<<" "; cout<<endl;
	  return;
	}
	m[sum]=x;
  }

  cout<<"Impossible"<<endl;

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
