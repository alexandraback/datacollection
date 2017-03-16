#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define repeat(t) for (int asdfg=0; asdfg < (t); asdfg++)
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

const int N=1000000;

struct Rec{
	int id,k,day;
	Rec() {}
	Rec(int _id,int _k,int _day): id(_id),k(_k),day(_day) {}
	bool operator <(const Rec &a) const {
		return day < a.day;
	}
};

struct Segment{
	int l,r,x;
} c[N*8];

void init(int l,int r,int k) {
	// printf("%d %d %d\n",l,r,k);
	c[k].l=l;
	c[k].r=r;
	c[k].x=0;
	if (l==r) return;
	int mid=(l+r)/2;
	if (r<=0) mid=(l+r-1)/2;
	init(l,mid,k<<1);
	init(mid+1,r,k<<1|1);
}

void update(int l,int r,int k,int w) {
	if (c[k].x>=w) return;
	if (l==c[k].l && r==c[k].r) {
		if (c[k].x<w) c[k].x=w;
		return;
	}
	int mid=(c[k].l+c[k].r)/2;
	if (c[k].r<=0) mid=(c[k].l+c[k].r-1)/2;
	if (r<=mid) update(l,r,k<<1,w);
	else if (l>mid) update(l,r,k<<1|1,w);
	else {
		update(l,mid,k<<1,w);
		update(mid+1,r,k<<1|1,w);
	}
	c[k].x=min(c[k<<1].x,c[k<<1|1].x);
}

int query(int l,int r,int k) {
	if (l==c[k].l && r==c[k].r) {
		return c[k].x;
	}
	int mid=(c[k].l+c[k].r)/2;
	if (c[k].r<=0) mid=(c[k].l+c[k].r-1)/2;
	int ret;
	if (r<=mid) ret=query(l,r,k<<1);
	else if (l>mid) ret=query(l,r,k<<1|1);
	else {
		ret=query(l,mid,k<<1);
		int tmp=query(mid+1,r,k<<1|1);
		if (tmp<ret) ret=tmp;
	}
	return ret;
}

int n,m,d[1100],t,l[1100],r[1100],s[1100],dd,dp[1100],ds[1100];
int main() {
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("C3.out", "w", stdout);
	int cas;
	scanf("%d",&cas);
	for (int T=1; T<=cas; T++) {
		scanf("%d",&n);
		vector<Rec> b;
		for (int i=0; i<n; i++) {
			scanf("%d%d%d%d%d%d%d%d",&d[i],&t,&l[i],&r[i],&s[i],&dd,&dp[i],&ds[i]);
			for (int k=0; k<t; k++) {
				b.pb(Rec(i,k,d[i]+k*dd));
			}
		}
		sort(b.begin(),b.end());
		m=b.size();
		init(-N,N,1);
		int ans=0;
		// printf("m=%d\n",m);
		for (int j,i=0; i<m; i=j) {
			Rec x=b[i];
			j=i;
			while (j<m && b[j].day==x.day) j++;
			for (int k=i; k<j; k++) {
				// printf("k=%d",k);
				int a=l[x.id]+x.k*dp[x.id];
				int b=l[x.id]+x.k*dp[x.id];
				int strength=s[x.id]-x.k*ds[x.id];
				int low=query(a,b,1);
				if (low < strength) ans++;
			}
			for (int k=i; k<j; k++) {
				int a=l[x.id]+x.k*dp[x.id];
				int b=l[x.id]+x.k*dp[x.id];
				int strength=s[x.id]-x.k*ds[x.id];
				update(a,b,1,strength);
			}
		}
		printf("Case #%d: %d\n",T,ans);
	}
	return 0;
}