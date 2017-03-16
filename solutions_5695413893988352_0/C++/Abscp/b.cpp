#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long ans, ss, tt;
char s[30], t[30];
void dfs(long long nows, long long nowt, long long nowdif, int l, long long base) {
	//printf("%lld %lld %lld %lld\n", nows, nowt, nowdif, ans);
	if(l==-1){
		
		if(ans >= abs(nowdif)) {
			if(abs(nowdif) < ans) {
				ans = abs(nowdif);
				ss = nows;
				tt = nowt;
			}else if(ans == abs(nowdif)){
				if(nows < ss){
					ss = nows;
					tt = nowt;
				}else if(nows == ss && nowt < tt){
					tt = nowt;
				}
			} 
		}
		return;
	}
	
	if(s[l] == '?') {
		if(t[l] == '?') {
			for(int i=0; i<10; ++i)
				for(int j=0; j<10; ++j)
					dfs(nows+i*base, nowt+j*base, nowdif+(i-j)*base, l-1, base*10);
		}else{
			for(int i=0; i<10; ++i)
				dfs(nows+i*base, nowt + (t[l]-'0')*base, nowdif+(i-(t[l]-'0'))*base, l-1, base*10);
		}
	}else if(t[l] == '?') {
		for(int i=0; i<10; ++i)
			dfs(nows+(s[l]-'0')*base, nowt + i*base, nowdif+((s[l]-'0')-i)*base, l-1, base*10);
	}else{
		dfs(nows + (s[l]-'0')*base, nowt + (t[l]-'0')*base, nowdif + (s[l]-t[l])*base, l-1, base*10);
	}
}
void print(long long number, int len) {
	int a[20];
	for(int i=0; i<20; ++i) a[i]=0;
	int t=0;
	while(number) {
		a[t++] = number%10;
		number /=10;
	}
	printf(" ");
	for(int i=len-1; i>=0; --i)
		printf("%d", a[i]);
}
int main() {
	freopen("B-small-attempt4.in","r",stdin);
	freopen("B-small-attempt4.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
		
		scanf("%s%s", s, t);
		int l = strlen(s);
		ans = 1e10;
		dfs(0, 0, 0, l-1, 1);
		printf("Case #%d:", i+1);
		print(ss, l);
		print(tt, l);
		printf("\n");
	}
	
	return 0;
}
