#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <set>
#include <string.h>
#include <map>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define mp make_pair 
#define f first
#define s second
#define MAXN 10009

int N,ans,siz;
map<double,int>wall;

struct st {
	int strg,day,west,east;
}A[MAXN];

struct var {
	int w,e,val;
};


inline st mp(int str,int day,int w,int e) {
	st p;
	p.strg=str;
	p.day=day;
	p.west=w;
	p.east=e;
	return p;
}

inline var make_var(int w,int e,int val) {
	var a;
	
	a.w=w;
	a.e=e;
	a.val=val;
	
	return a;
}


void Read() {
	scanf("%d",&N);
	
	for (int i=1;i<=N;i++) {
		int ni,sday,sstr,spos,str,fday,se,sw;
		
		scanf("%d %d %d %d %d %d %d %d",&fday,&ni,&se,&sw,&str,&sday,&spos,&sstr);
		
		A[++siz]=mp(str,fday,sw,se);
		
		for (int j=1;j<=ni-1;j++) {
			A[++siz]=mp(str+sstr,fday+sday,sw+spos,se+spos);
			str+=sstr;
			fday+=sday;
			sw+=spos;
			se+=spos;
		}
	}
}

bool cmp(st a,st b) {
	return a.day<b.day;
}

void Solve(int kase) {
	
	vector<var>interval;
	sort(A+1,A+siz+1,cmp);
	ans=0;
	
	for (int i=1;i<=siz;i++) {
		
		bool ok=false;
		
		for (double j=A[i].east;j<=A[i].west;j+=0.5) {
			if (wall[j]<A[i].strg) {
				if (!ok) {
					ok=true;
				}
			}
		}
		
		if (ok) {
			interval.push_back(make_var(A[i].west,A[i].east,A[i].strg));
		}
		
		if (A[i].day!=A[i+1].day) {
			
			ans+=interval.size();
			
			for (int j=0;j<interval.size();j++) {
				
				for (double k=interval[j].e;k<=interval[j].w;k+=0.5) {
					wall[k]=max(wall[k],interval[j].val);
				}
			}
			
			interval.clear();
		}
	}
	
	printf("Case #%d: %d\n",kase,ans);
}

void Init() {
	for (int i=1;i<=siz;i++) {
		A[i].strg=0;
		A[i].day=0;
		A[i].west=0;
		A[i].east=0;
	}
	siz=0;
	
	wall.clear();
}

int main () {
	
	freopen("codejam.in","r",stdin);
	freopen("codejam.out","w",stdout);
	
	int t;
	
	scanf("%d",&t);
	
	for (int i=1;i<=t;i++) {
		Read();
		Solve(i);
		Init();
	}
	
	return 0;
}
