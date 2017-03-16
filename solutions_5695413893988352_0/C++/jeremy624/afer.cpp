#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const long long INF = 1e18;
int t,i,j,k,l;
char s[105],s1[105],ans[105],ans1[105],t2[105],t1[105];
long long val,val1,diff,num[105],ansx,ansy,ansz;

char fix(long long temp){
	if(temp > '9')
	return '9';
	else if(temp < '0')
	return '0';
	else
	return temp;
}
void solve(int id, long long r){
	if(id == l){
		long long val = 0;
		long long val1 = 0;
		for(int k = 0; k < l; k++){
			val = val * 10 + (ans1[k] - '0');
			val1 = val1 * 10 + (ans[k] - '0');
		}
		if(abs(r) < ansx || (abs(r) == ansx && ansy > val)){
			ansx = abs(r);
			ansy = val;
			ansz = val1;
			for(int k = 0; k < l; k++){
				t2[k] = ans[k];
				t1[k] = ans1[k];
			}
		}
		return;
	}
	if(s[id] == '?' && s1[id] == '?'){
		if(r == 0){
			ans[id] = '0';
			ans1[id] = '0';
			solve(id + 1, r);
		}
		else if(r > 0){
			long long temp = r / num[(l - id - 1)];
			ans[id] = '0';
			ans1[id] = fix('0' + temp);
			solve(id + 1, r + num[(l - id - 1)] * ((ans[id] - '0') - (ans1[id] - '0')));
			if('0' + temp + 1 <= '9')
			ans1[id] = fix('0' + temp + 1);
			solve(id + 1, r + num[(l - id - 1)] * ((ans[id] - '0') - (ans1[id] - '0')));
		}
		else{
			long long temp = -r / num[(l - id - 1)];
			ans1[id] = '0';
			ans[id] = fix('0' + temp);
			solve(id + 1, r + num[(l - id - 1)] * ((ans[id] - '0') - (ans1[id] - '0')));
			ans[id] = fix('0' + temp + 1);
			solve(id + 1, r + num[(l - id - 1)] * ((ans[id] - '0') - (ans1[id] - '0')));
		}
	}
	else if(s[id] == '?'){
		ans1[id] = s1[id];
		if(r == 0){
			ans[id] = s1[id];
			solve(id + 1, r);
		}
		else if(r > 0){
			long long temp = r / num[(l - id - 1)];
			ans[id] = '0';
			solve(id + 1, r);
			ans[id] = '0';
			solve(id + 1, r);
		}
		else{
			long long temp = -r / num[(l - id - 1)];
			ans[id] = fix('0' + temp);
			solve(id + 1, r + num[(l - id - 1)] * (ans[id] - '0'));
			ans[id] = fix('0' + temp + 1);
			solve(id + 1, r + num[(l - id - 1)] * (ans[id] - '0'));
		}
	}
	else if(s1[id] == '?'){
		ans[id] = s[id];
		if(r == 0){
			ans1[id] = s[id];
			solve(id + 1, r);
		}
		else if(r > 0){
			long long temp = r / num[(l - id - 1)];
			ans1[id] = fix('0' + temp);
			solve(id + 1, r - num[(l - id - 1)] * (ans1[id] - '0'));
			ans1[id] = fix('0' + temp + 1);
			solve(id + 1, r - num[(l - id - 1)] * (ans1[id] - '0'));
		}
		else{
			long long temp = -r / num[(l - id - 1)];
			ans1[id] = '0';
			solve(id + 1, r);
			ans1[id] = '0';
			solve(id + 1, r);
		}
	}
	else{
		ans[id] = s[id];
		ans1[id] = s1[id];
		solve(id + 1, r);
	}
}

int main(){
	scanf("%d", &t);
	num[0] = 1LL;
	for(i = 1; i <= 18; i++)
	num[i] = num[i - 1] * 10LL;
	int testcase = 0;
	while(++testcase <= t){
		ansx = INF;
		ansy = INF;
		ansz = INF;
		scanf("%s%s", s, s1);
		l = strlen(s);
		val = 0;
		val1 = 0;
		for(i = 0; i < l; i++){
			val = val * 10;
			if(s[i] != '?')
			val += (s[i] - '0');
		}
		for(i = 0; i < l; i++){
			val1 = val1 * 10;
			if(s1[i] != '?')
			val1 += (s1[i] - '0');
		}
		diff = val - val1;
		solve(0, diff);
		printf("Case #%d: ", testcase);
		for(int k = 0; k < l; k++)
		printf("%c", t2[k]);
		printf(" ");
		for(int k = 0; k < l; k++)
		printf("%c", t1[k]);
		printf("\n");
	}
}

