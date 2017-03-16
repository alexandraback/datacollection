#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<string.h>

#define f first
#define s second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define MAXN 109

using namespace std;

int A,N,p[MAXN];

void Read() {
	scanf("%d %d",&A,&N);
	
	for (int i=1;i<=N;i++) {
		scanf("%d",&p[i]);
	}
	
	sort(p+1,p+N+1);
}

void Init() {
	memset(p,0,sizeof p);
}

void Solve(int kase) {
	
	int cur=0,ans=N,curA=A;
	
		for (int j=N;j>=1;j--) {
			cur=N-j;
			curA=A;
			
			if (A<=p[1]&&A==1)
				continue;
			
			else {
			int i=1;
			
			while (1) {
				if (i==j+1)
					break;
				if (curA>p[i]) {
					curA+=p[i];
					i++;
				}
				else {
					curA=curA+curA-1;
					cur++;
				}
			}
			ans=min(cur,ans);
		}
	}
	
	printf("Case #%d: %d\n",kase,ans);
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





