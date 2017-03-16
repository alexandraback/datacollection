#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int check(int d,int p){
	if (d<=1) if (p<=d) return 3;else return 0;
	if (d>=29) return 3;
	if (p*3-2<=d) return 2;else 
		if (p*3-4<=d) return 1;else return 0;
}

int solve(){
	int n,S,p,i,t,s[4];
	memset(s,0,sizeof(s));
	scanf("%d%d%d",&n,&S,&p);
	for (i=1;i<=n;i++){
		scanf("%d",&t);
		s[check(t,p)]++;
	}
	//for (i=0;i<=3;i++) printf("%d ",s[i]);printf("\n");
	if (s[1]>=S) return S+s[2]+s[3];else return s[1]+s[2]+s[3];
}

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,t;	cin>>T;
	for (t=1;t<=T;t++){
		printf("Case #%d: %d\n",t,solve());
	}
}
