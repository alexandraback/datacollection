#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int TTT,x,n,a[2000000];

int main(){
	freopen("A-small-attempt1.in","r",stdin);
	//freopen("A.in","r",stdin);
	
	freopen("A.out","w",stdout);
	scanf("%d",&TTT);
	for (int TT=1; TT<=TTT; TT++){
		printf("Case #%d: ",TT);
		scanf("%d %d\n",&x,&n);
		for (int i=0; i<n; i++){
			scanf("%d",&a[i]);
		}
		
		sort(a,a+n);
		int ans=n;
		int now = 0;
		for (int i=0; i<n; i++){
			if (x==1) {
				if (now+n-i<ans) ans=now+n-i;
				break;
			}
			while (x<=a[i]){
				now++; x=2*x-1;
			}
			if (now+n-i-1<ans) ans=now+n-i-1;
			x = x+a[i];
		}
		printf("%d\n",ans);
	}
	
	fclose(stdout);
	fclose(stdin);
}
