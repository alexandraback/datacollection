#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<n;i++)
#define forup(i,a,b) for(int i=a;i<=b;i++)
#define fordn(i,a,b) for(int i=a;i>=b;i--)
#define drep(i,n) for(i=0;i<n;i++)
#define dforup(i,a,b) for(i=a;i<=b;i++)
#define dfordn(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define permute(x) next_permutation(all(x))
#define pb push_back
#define mp make_pair
#define fi first
#define sc second

int tot,z,x,y;
void calc(vs grid,int n) {
	if(n==0) {
		tot++;
		if(grid[x+10][y]=='x') z++;
		return;
	}
	int l=0,m,x1=10;
	while(l<=10) {
		if(grid[x1][l]=='x') l+=2;
		else break;
	}
	m=l;
	bool f=false;
	if(l>0 and grid[x1-1][l-1]!='x') {
		while(l>0) {
			if(grid[x1-1][l-1]!='x') {
				x1--;
				l--;
			}
			else break;
		}
		grid[x1][l]='x';
		f=true;
		calc(grid,n-1);
		grid[x1][l]='.';
	}
	x1=10; l=m;
	if(l>0 and grid[x1+1][l-1]!='x') {
		while(l>0) {
			if(grid[x1+1][l-1]!='x') {
				x1++;
				l--;
			}
			else break;
		}
		grid[x1][l]='x';
		f=true;
		calc(grid,n-1);
		grid[x1][l]='.';
	}
	if(!f) {
		grid[10][l]='x';
		calc(grid,n-1);
	}
}

int main() {
	int T,n;
	double ans;
	scanf("%d",&T);
	rep(t,T) {
		scanf("%d%d%d",&n,&x,&y);
		vs grid(21,string(21,'.'));
		tot=z=0;
		if(x>10 || x<-10 || y>10) ans=0;
		else {
			calc(grid,n);
			ans=double(z)/double(tot);
		}
		printf("Case #%d: %.8lf\n",t+1,ans);
	}
	return 0;
}
