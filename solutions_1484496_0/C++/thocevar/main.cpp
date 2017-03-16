#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#define all(c) (c).begin(),(c).end()
#define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define pb push_back
#define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
typedef long long int64;
typedef pair<int,int> PII;

int tests;
int n,x[20],f[20],stop;

void solve(int id, int s1=0, int s2=0) {
	if (s1!=0 && s1==s2) stop=1;
	if (stop || id==n) return;
	else {
		f[id]=0;
		solve(id+1,s1,s2);
		if (stop) return;
		f[id]=1;
		solve(id+1,s1+x[id],s2);
		if (stop) return;
		f[id]=2;
		solve(id+1,s1,s2+x[id]);
		if (stop) return;
		f[id]=0;
	}
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++) {
    	printf("Case #%d:\n",test);
    	scanf("%d",&n);
    	for (int i=0;i<n;i++) {
    		scanf("%d",&x[i]);
    		f[i]=0;
    	}
    	stop=0;
    	solve(0);
    	if (!stop) printf("Impossible\n");
    	else {
    		for (int i=0;i<n;i++) if (f[i]==1) printf("%d ",x[i]);
    		printf("\n");
    		for (int i=0;i<n;i++) if (f[i]==2) printf("%d ",x[i]);
    		printf("\n");
    	}
    	fprintf(stderr,"%d\n",test);
	}
    return 0;
}
