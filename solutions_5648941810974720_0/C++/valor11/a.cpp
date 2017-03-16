#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2200;
//#define LOCAL
char s[N];
int cc[256];
int ans[10];
char num[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int dd[10] =  { 0,  8,  6,  2,  3,  4,  1,  5,  7,  9};
char ss[10] = {'Z','G','X','W','H','U','O','F','V','I'};
int main(){
	#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	for(int times=1;times<=T;times++){
		scanf(" %s",s);
		int n = strlen(s);
		memset(cc,0,sizeof(cc));
		for(int i=0;i<n;i++)
			cc[s[i]]++;

		for(int i=0;i<10;i++){
			int tmp=dd[i];
			ans[tmp] = cc[ss[i]];
			for(int j=0;num[tmp][j];j++)
				cc[num[tmp][j]]-=ans[tmp];
		}
		printf("Case #%d: ",times);
		for(int i=0;i<10;i++)
			for(int j=0;j<ans[i];j++)
				printf("%d",i);
		puts("");
	}
	return 0;
}