#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
int a[30];
char str[2005];
int ans[10];
int main() {
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		for(int j=0;j<=26;j++) {
			a[j]=0;
		}
		for(int j=0;j<10;j++) {
			ans[j]=0;
		}
		scanf("%s",str);
		int l = strlen(str);
		for(int j=0;j<l;j++) {
			a[str[j]-'A']++;
		}
		ans[0]=a['Z'-'A'];
		if(a['O'-'A']>(a['W'-'A']+a['U'-'A']+a['Z'-'A'])) {
			ans[1]=a['O'-'A']-(a['W'-'A']+a['U'-'A']+a['Z'-'A']);
		}
		ans[2]=a['W'-'A'];
		if(a['R'-'A']>(a['U'-'A']+a['Z'-'A'])) {
			ans[3]=a['R'-'A']-(a['U'-'A']+a['Z'-'A']);
		}
		ans[4]=a['U'-'A'];
		if(a['F'-'A']>a['U'-'A']) {
			ans[5]=a['F'-'A']-a['U'-'A'];
		}
		ans[6]=a['X'-'A'];
		if(a['S'-'A']>a['X'-'A']) {
			ans[7]=a['S'-'A']-a['X'-'A'];
		}
		ans[8]=a['G'-'A'];
		if(a['I'-'A']>(ans[8]+ans[6]+ans[5])) {
			ans[9]=a['I'-'A']-(ans[8]+ans[6]+ans[5]);
		}
		printf("Case #%d: ",i);
		for(int j=0;j<10;j++) {
			for(int k=0;k<ans[j];k++) {
				printf("%d",j);
			}
		}
		printf("\n");
	}
	return 0;
}