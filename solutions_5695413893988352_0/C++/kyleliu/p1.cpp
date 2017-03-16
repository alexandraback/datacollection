#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define MAXN 20
#define INF 200000000000
typedef long long ll;
int T;
int a[MAXN];
int b[MAXN];
ll table[MAXN];
int cnt = 0;
ll res = INF;
ll ans1 = 0;
ll ans2 = 0;
int ar1[MAXN];
int ar2[MAXN];
ll ab(ll a, ll b)
{
	if(a<b) return b-a;
	if(a>b) return a-b;
	return 0;
}

void print(ll a, ll b, int t)
{
	for(int i=cnt-1; i>=0; i--) {
		int c1 = 0, c2 = 0;
		while(a >= table[i]) {
			a -= table[i];
			c1++;
		}
		while(b >= table[i]) {
			b -= table[i];
			c2++;
		}
		ar1[cnt-1-i] = c1;
		ar2[cnt-1-i] = c2;
	}
	printf("Case #%d: ", t);
	for(int i=0; i<cnt; i++) printf("%d", ar1[i]);
	printf(" ");
	for(int i=0; i<cnt; i++) printf("%d", ar2[i]);
	printf("\n");
}
void dfs(ll a1, ll a2, int pos)
{
	if(pos == cnt) {
		//printf("%lld %lld\n", a1, a2);
		if(ab(a1, a2) > res) return;
		if(ab(a1, a2) == res) {
			 if(a1 == ans1) ans2 = min(ans2, a2);
			 if(a1 < ans1) {
			 	ans1 = a1;
			 	ans2 = a2;
			 }
		}
		if(ab(a1, a2) < res) {
			res = ab(a1, a2);
			ans1 = a1;
			ans2 = a2;
		}
			
		return;
	}
	if((a[pos] != -1) && (b[pos] != -1)) dfs(a1, a2, pos+1);
	if((a[pos] == -1) && (b[pos] == -1)) {
		dfs(a1, a2 + table[cnt-pos-1], pos+1);
		dfs(a1 + table[cnt-pos-1], a2, pos+1);
		dfs(a1+9*table[cnt-pos-1], a2, pos+1);
		dfs(a1, a2+9*table[cnt-pos-1], pos+1);
		dfs(a1, a2, pos+1);
	}
	if((a[pos] == -1) && (b[pos] != -1)) {
		int num = b[pos];
		if(num > 0) dfs(a1+(num-1)*table[cnt-pos-1], a2, pos+1);
		dfs(a1+(num)*table[cnt-pos-1], a2, pos+1);
		if(num < 9) dfs(a1+(num+1)*table[cnt-pos-1], a2, pos+1);
		dfs(a1+9*table[cnt-pos-1], a2, pos+1);
		dfs(a1, a2, pos+1);
	}
	if((a[pos] != -1) && (b[pos] == -1)) {
		int num = a[pos];
		if(num > 0) dfs(a1, a2+(num-1)*table[cnt-pos-1], pos+1);
		dfs(a1, a2+(num)*table[cnt-pos-1], pos+1);
		if(num < 9) dfs(a1, a2+(num+1)*table[cnt-pos-1], pos+1);
		dfs(a1, a2+9*table[cnt-pos-1], pos+1);
		dfs(a1, a2, pos+1);
	}
	return;
} 
int main(void)
{
	string c, j;
	cin >> T;
	table[0] = 1;
	for(int i=1; i<=18; i++) table[i] = table[i-1] * 10;
	for(int t=1; t<=T; t++) {
		cin >> c >> j;
	//	if(t != 1) continue;
		cnt = 0;
		res = INF;
		ans1 = ans2 = INF;
		ll sm1 = 0;
		ll sm2 = 0;
		for(int i=0; i<c.size(); i++) {
			if(c[i] != '?') a[i] = c[i] - '0';
			if(j[i] != '?') b[i] = j[i] - '0';	
			if(c[i] == '?') a[i] = -1;
			if(j[i] == '?') b[i] = -1;
			cnt++;
		}
		ll mul = 10;
		for(int i=0; i<c.size(); i++) { 
			sm1 *= mul;
			sm2 *= mul;
			if(a[i] != -1) sm1 += a[i];
			if(b[i] != -1) sm2 += b[i];
		}
	//	printf("%lld %lld\n", sm1, sm2);
		dfs(sm1, sm2, 0);
		print(ans1, ans2, t);
	}
			
	return 0;
}
