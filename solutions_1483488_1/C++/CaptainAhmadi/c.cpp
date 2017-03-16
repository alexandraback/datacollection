
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

void clear() {

}

void solve(int cnum) {
  int lo, hi;
  cin>>lo>>hi;
  int cnt=0;

  for (int x=lo;x<=hi;x++) {

	int front=1;
	for (int z=x;z;z/=10) front*=10;
	front/=10;

	int y=x;
	for(;;) {
	  int left=y%10;
	  y=y/10+front*left;
	  if (x==y) break;
	  if (left!=0) {
		if (x<y && y<=hi) cnt++;
	  }
	} 
	  
  }

  cout<<"Case #"<<cnum<<": "<<cnt<<endl;;

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
