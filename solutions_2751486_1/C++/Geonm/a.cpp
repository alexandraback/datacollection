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
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define mp make_pair 
#define f first
#define s second
#define MAXN 1000009

char s[MAXN];
int v,N;
vector<int>occ;

int upper(int b) {
	
	int lo=0,hi=occ.size();
	
	while (lo<hi) {
		int mid=(lo+hi)/2;
		
		if (occ[mid]<b)
			lo=mid+1;
		else
			hi=mid;	
	}
	
	return occ[lo];
}

void Solve(int kase) {
	
	scanf("%s %d",s,&v);
	N=strlen(s);
	
	int curr=0;
	
	for (int i=0;i<N;i++) {
		
		if (s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
			curr++;
		else 
			curr=0;
		
		if (curr==v) {
			occ.push_back(i);
			curr--;
		}
	}
	
	occ.push_back(N);
	
	ll total=0;
	
	for (int i=0;i<N-v+1;i++) {
		total+=(ll)N-upper(i+v-1);
	}
	
	printf("Case #%d: %lld\n",kase,total);
}

void Init() {
	memset(s,0,sizeof s);
	occ.clear();
}

int main () {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	int t;
	
	scanf("%d",&t);
	
	for (int i=1;i<=t;i++) {
		Solve(i);
		Init();
	}
	
	return 0;
}



