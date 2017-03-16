#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define L 1000010
char str[L];
int v[L], valid[26];
int n, l;

void init() {
	memset(valid, 1, sizeof(valid));
	valid[0]=valid['e'-'a']=valid['i'-'a']=valid['o'-'a']=valid['u'-'a']=0;
}

void conduct() {
	int i;
	long long ans, pre;
	scanf("%s%d", str, &l);
	n = strlen(str);
	if (valid[str[0]-'a']) v[0]=1; else v[0]=0;
	for (i=1; i<n; ++i) if (valid[str[i]-'a']) v[i]=v[i-1]+1; else v[i]=0;
	for (ans=pre=0, i=l-1; i<n; ++i) {
//		printf("v[%d]=%d, %lld\n", i, v[i], pre);
		if (v[i]>=l) pre=i-l+2;
		ans += pre;
	}
	cout << ans << endl;
}

int main() {
	init();
	int time; scanf("%d", &time);
	for (int i=1; i<=time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	}
	return 0;
}
