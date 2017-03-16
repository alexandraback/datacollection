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
int n,s[200];

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++) {
    	printf("Case #%d:",test);
    	scanf("%d",&n);
    	int x=0;
    	for (int i=0;i<n;i++) {
    		scanf("%d",&s[i]);
    		x+=s[i];
    	}
    	for (int i=0;i<n;i++) {
			double mf=0,Mf=1;
			for (int it=1;it<=100;it++) {
				double f=(mf+Mf)/2;
				double sc=s[i]+f*x;
				double g=0;
				int st=0;
				for (int j=0;j<n;j++) if (j!=i && s[j]<sc) {
					g+=(sc-s[j])/x;
					st++;
				}
				if (g>1-f && st>0) Mf=f; else mf=f;
			}
			printf(" %.6lf",mf*100);
    	}
    	printf("\n");
	}
    return 0;
}
