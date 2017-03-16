#pragma comment(linker, "/STACK:36777216")
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <ctime>

#define pb push_back
#define mp make_pair
#define sz size()
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vint vector<int>
#define rep(i,n) for (int i=0; i<n; i++)
#define ll long long

using namespace std;

const int INF=~(1<<31);
const double EPS=1;
const double PI=3.141592653589793;

vint v;

int go(int i, int a, int n) {
	int r;
	if(i==n) return 0;
	if (v[i]<a) r=go(i+1,a+v[i],n);
	else {
		if (a==1) r=go(i+1,a,n)+1;
		else r=go(i,a+a-1,n)+1;
	}
	return min(r,n-i);
}

int main() {
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int T;
  scanf("%d",&T);
  rep(t,T) {
	  int n,a;
	  cin>>a>>n;
	  v.resize(n);
	  rep(i,n){
		  cin>>v[i];
	  }
	  sort(all(v));
	  printf("Case #%d: %d\n",t+1,go(0,a,n));
  }
  return 0;
}