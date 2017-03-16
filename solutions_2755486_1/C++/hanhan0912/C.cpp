/* hanhanw v1.2 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=(y); x<=(z); x++)
#define FORD(x,y,z) for(int x=(y); x>=(z); x--)
#define FLST(x,y,z) for(int x=(y); x; x=z[x])
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define SZ(x) ((int)x.size())
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

const int N = 1024;

struct QQ{
	LL l,r,s,d;
	QQ (){};
	QQ (LL _l, LL _r, LL _s, LL _d){ l=_l; r=_r; s=_s; d=_d; }
}att[N*N],x[N*N];

int n,nat,ans,nx;
LL ns,seq[6*N*N];
LL tree[18*N*N],p[18*N*N],high[6*N*N];

bool comp(QQ a, QQ b){ return a.d != b.d ? a.d < b.d : a.s < b.s; }
void init(int l, int r, int id){
	tree[id] = 0;
	p[id]=-1;
	if (l == r) return ;
	init(l,(l+r)/2,id*2+1);
	init((l+r)/2+1,r,id*2+2);
}
void update(int l, int r, int fl, int fr, LL s, int id){
	if (l == fl && r == fr){
	//	tree[id]=p[id]=s;
		tree[id] = max(tree[id],s);
		p[id] = max(p[id],s);
		return ;
	}
	int m=(l+r)/2,lc=id*2+1,rc=id*2+2;
	if (p[id] != -1){
		p[lc] = max(p[lc],p[id]);
		p[rc] = max(p[rc],p[id]);
		tree[lc] = max(tree[lc],p[id]);
		tree[rc] = max(tree[rc],p[id]);
		p[id]=-1;
	}
	if (fr <= m) update(l,m,fl,fr,s,lc);
	else if (m < fl) update(m+1,r,fl,fr,s,rc);
	else {
		update(l,m,fl,m,s,lc);
		update(m+1,r,m+1,fr,s,rc);
	}
	tree[id] = min(tree[lc], tree[rc]);
}
LL query(int l, int r, int fl, int fr, int id){
	if (l == fl && r == fr) return tree[id];
	int m=(l+r)/2,lc=id*2+1,rc=id*2+2;
	if (p[id] != -1){
		p[lc] = max(p[lc],p[id]);
		p[rc] = max(p[rc],p[id]);
		tree[lc] = max(tree[lc],p[id]);
		tree[rc] = max(tree[rc],p[id]);
		p[id]=-1;
	}
	if (fr <= m) return query(l,m,fl,fr,lc);
	if (m < fl) return query(m+1,r,fl,fr,rc);
	return min(query(l,m,fl,m,lc), query(m+1,r,m+1,fr,rc));
}
void update2(int st, int ed, LL s){
	for (int i=st; i<=ed; i++)
		high[i]=max(high[i],s);
}
LL query2(int st, int ed){
	LL res=9223372036854775807ll>>1;
	for (int i=st; i<=ed; i++)
		res = min(res,high[i]);
	return res;
}

void solve(int T){
	nat=ans=0;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		LL fd,l,r,s,deld,delp,dels,m;
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d", &fd, &m, &l, &r, &s, &deld, &delp, &dels);
		if (l > r) swap(l,r);
		att[nat++] = QQ(l,r,s,fd);
		for (int j=2; j<=m; j++){
			l += delp;
			r += delp;
			s += dels;
			fd += deld;
			if (l > r) swap(l,r);
			att[nat++] = QQ(l,r,s,fd); 
		}
	}
	n=nat;
	sort(att,att+n,comp);
	for (int i=0; i<n; i++){
		att[i].l*=2ll;
		att[i].r*=2ll;
	//	printf("%d %I64d: %I64d %I64d %I64d\n", i, att[i].d, att[i].l, att[i].r, att[i].s);
	}
	ns=0;
	for (int i=0; i<n; i++){
		seq[ns++] = att[i].l-1;
		seq[ns++] = att[i].l;
		seq[ns++] = att[i].l+1;
		seq[ns++] = att[i].r-1;
		seq[ns++] = att[i].r;
		seq[ns++] = att[i].r+1;
	}
	sort(seq,seq+ns);
	ns = unique(seq,seq+ns)-seq;
	for (int i=0; i<n; i++){
		att[i].l = lower_bound(seq,seq+ns,att[i].l)-seq;
		att[i].r = lower_bound(seq,seq+ns,att[i].r)-seq;
		
	}
	init(0,ns,0);
//	printf("%d\n", n);
	MSET(high,0);
	for (int i=0; i<n; i++){
		nx=0;
		for (int j=i; j<n; j++){
			if (att[i].d == att[j].d){
				x[nx++] = att[j];
			} else {
				break;
			}
			i=j;
		}
		for (int j=0; j<nx; j++){
			if (query(0,ns,x[j].l,x[j].r,0) < x[j].s)
				ans++;
		//	printf("%I64d ", query2(x[j].l,x[j].r));
		//	if (query2(x[j].l,x[j].r) < x[j].s)
		//		ans++;
		}
		for (int j=0; j<nx; j++){
			update(0,ns,x[j].l,x[j].r,x[j].s,0);
		//	update2(x[j].l,x[j].r,x[j].s);
		}
	//	printf("#%d: %d\n", i,ans);
	}
	printf("Case #%d: %d\n", T, ans);
}
int main(){
	int nT; scanf("%d", &nT);
	for (int i=1; i<=nT; i++)
		solve(i);
	
	return 0;
}
