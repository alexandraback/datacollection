#include<bits/stdc++.h>
using namespace std;
const int MAXN=100111;
char a[MAXN];
main(){
	int test;scanf("%d",&test);
	for(int tnr=1;tnr<=test;tnr++){
		int s;scanf("%d",&s);
		scanf("%s",a);
		int wyn=0;
		int ob=0;
		for(int i=0;i<=s;i++){
			if(ob<i) wyn+=i-ob,ob=i;
			ob+=a[i]-'0';
		}
		printf("Case #%d: %d\n",tnr,wyn);
	}
}
	
