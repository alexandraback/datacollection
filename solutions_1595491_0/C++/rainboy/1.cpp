#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
int main(){
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	int T;
	scanf("%d\n", &T);
	for (int tt=1;tt<=T;tt++){
		int N,S,L,x;
		scanf("%d %d %d", &N, &S, &L);
		int ret=N,tot=0;
		for (int i=0;i<N;i++){
			int p=1;
			scanf("%d", &x);
			for (int j=0;j<=10;j++)
			for (int k=j;k<=10 && k<=j+2;k++)
			for (int l=k;l<=10 && l<=j+2;l++)
			if (j+k+l==x){
				if (l>=L) p=0;
			}
			if (x==L*3-4 || x==L*3-3) tot++;
			ret-=p;
		}
		if (tot>S) ret-=(tot-S);
		if (ret<0) ret=0;
		printf("Case #%d: %d\n", tt, ret);
	}
	return 0;
}
