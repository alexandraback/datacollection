#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2000;
//#define LOCAL
char s[N << 1], t[N << 1];
int main(){
	#ifdef LOCAL
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	for(int times=1;times<=T;times++){
		scanf("%s",s);
		int n = strlen(s);
		int st,ed;
		st = ed = N;
		t[ed] = s[0];
		for(int i=1;i<n;i++){
			if (s[i]>=t[st]){
				t[--st] = s[i];
			}else t[++ed] = s[i];
		}
		t[++ed] = 0;
		printf("Case #%d: %s\n",times,t+st);
	}
	return 0;
}