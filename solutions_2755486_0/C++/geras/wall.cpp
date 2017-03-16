// Author: Kamil Niziński
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <algorithm>
#define debug(fmt,...) //fprintf(stderr,fmt, ## __VA_ARGS__)
#define mp make_pair
#define ft first
#define sd second
#define psb push_back
#define ppb pop_back
using namespace std;
typedef long long int ll;
typedef long long unsigned llu;
typedef double dd;
typedef pair < int , int > pii;
const int shift=1<<21, przes=1000003;
int MIN[shift<<1],N;
int odp;
vector < vector < pair < int, pii > > > D;
int minimum(int p, int q) {
	p+=shift;
	q+=shift;
	int w=min(MIN[p],MIN[q]);
	while((p>>1)!=(q>>1)) {
		if(!(p&1)) w=min(w,MIN[p+1]);
		if(q&1) w=min(w,MIN[q-1]);
		p>>=1;
		q>>=1;
		w=max(w,max(MIN[p],MIN[q]));
	}
	while(p>1) {
		p>>=1;
		w=max(w,MIN[p]);
	}
	return w;
}
void attack(int p, int q, int s) {
	p+=shift;
	q+=shift;
	MIN[p]=max(MIN[p],s);
	MIN[q]=max(MIN[q],s);
	while((p>>1)!=(q>>1)) {
		if(!(p&1)) MIN[p+1]=max(MIN[p+1],s);
		if(q&1) MIN[q-1]=max(MIN[q-1],s);
		p>>=1;
		q>>=1;
		MIN[p]=min(MIN[p<<1],MIN[(p<<1)+1]);
		MIN[q]=min(MIN[q<<1],MIN[(q<<1)+1]);
	}
	while(p>1) {
		p>>=1;
		MIN[p]=min(MIN[p<<1],MIN[(p<<1)+1]);
	}
}
void solve() {
	int i,j;
	for(i=0;i<(shift<<1);i++) MIN[i]=0;
	D.clear();
	odp=0;
	scanf("%d",&N);
	int d,n,w,e,s,delta_d,delta_p,delta_s;
	D.resize(676061);
	debug("ok\n");
	while(N--) {
		scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&delta_d,&delta_p,&delta_s);
		w+=przes;
		e+=przes;
		while(n--) {
			D[d].psb(mp(s,mp(w,e)));
			d+=delta_d;
			w+=delta_p;
			e+=delta_p;
			s+=delta_s;
		}
	}
	debug("gut\n");
	for(i=0;i<676061;i++) {
		for(j=0;j<D[i].size();j++) {
			s=D[i][j].ft;
			w=D[i][j].sd.ft;
			e=D[i][j].sd.sd;
			if(minimum(w+1,e)<s) odp++;
		}
		debug("super\n");
		for(j=0;j<D[i].size();j++) {
			s=D[i][j].ft;
			w=D[i][j].sd.ft;
			e=D[i][j].sd.sd;
			attack(w+1,e,s);
		}
		debug("wow\n");
	}
	printf("%d\n",odp);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
