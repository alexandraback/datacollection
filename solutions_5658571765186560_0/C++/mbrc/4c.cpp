#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REPE(i,x,y) for (int i=(x);i<(y);i++)
#define REP(i,x,y) for (int i=(x);i<=(y);i++)
#define DREP(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define pb push_back
#define MAXN 100100

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	int n; int x,r,c;
	cin>>n;
	REP(i,1,n) {
		string ans;
		cin>>x>>r>>c;
		if (x==1) { ans = "GABRIEL"; }
		if (x==2) {
			if (((r*c)%2) == 0) {
				ans = "GABRIEL";
			} else { 
				ans = "RICHARD";
			}
		}
		if (x==3) {
			if (((r*c)%3) != 0) { ans = "RICHARD"; }
			else { 
				if (c==3) { c=r; }
				if (c==1) { ans = "RICHARD"; }
				else if (c==2) { ans = "GABRIEL"; }
				else if (c==3) { ans = "GABRIEL"; }
				else { ans = "GABRIEL"; }
			}
		}
		if (x==4) { 
			if (((r*c)%4) != 0) {
				ans = "RICHARD"; 
			} else {
				if (c<r) { int tmp=c; c=r; r=tmp; }
				if (r==1) {
					ans = "RICHARD";
				} else if (r==2) {
					ans = "RICHARD";
				} else if (r==3) {
					ans = "GABRIEL";
				} else if (r==4) {
					ans = "GABRIEL";
				}
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
			

}
