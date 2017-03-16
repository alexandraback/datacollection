//By momo
#include <cstdio>
#include <vector>
#include <algorithm>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define LL long long
#define FOR(it, c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();it++)
using namespace std;

vector<int> dat;
vector<int> INT(int v){
	dat.clear();
	while(v){ dat.PB(v % 10); v /= 10; }
	return dat;
}

vector<vector<int> > ans;
vector<int> now, nxt, num, A, B;

vector<int> c;
vector<int> operator*(vector<int>& a, vector<int>& b){
	c.clear(); c.resize(SZ(a) + SZ(b) - 1, 0);
	for(int i = 0; i < SZ(a); i++)
		for(int j = 0; j < SZ(b); j++)
			c[i + j] += a[i] * b[j];
	return c;
}

void print(vector<int>& x){
	for(int i = 0; i < SZ(x); i++)
		printf("%d", x[i]);
	puts("");
}

void dfs(int p){
	if(p == 26) return;
	if(p == 0){
		now.PB(1); dfs(p+1); now.pop_back();
		now.PB(2); dfs(p+1); now.pop_back();
	}
	else{
		nxt = now; reverse(nxt.begin(), nxt.end());
		num.clear(); num = now;
		FOR(it, nxt) num.PB(*it);
		vector<int> mul = num * num;
		bool fl = 1;
		FOR(it, mul) if(*it >= 10) fl = 0;
		if(!fl) return;
		ans.PB(mul);

		for(int i = 0; i < 3; i++){
			num.clear(); num = now;
			num.PB(i);
			FOR(it, nxt) num.PB(*it);
			mul = num * num;
			fl = 1;
			FOR(it, mul) if(*it >= 10) fl = 0;
			if(fl) ans.PB(mul);
		}

		now.PB(0); dfs(p+1); now.pop_back();
		now.PB(1); dfs(p+1); now.pop_back();
	}
}

bool comp(const vector<int>& a, const vector<int>& b){
	if(SZ(a) < SZ(b)) return 1;
	if(SZ(a) > SZ(b)) return 0;
	return a < b;
}

char s[110];
int main (){
	freopen("out.txt", "w", stdout);
	ans.PB(INT(1)); ans.PB(INT(4));
	ans.PB(INT(9)); dfs(0);
	sort(ans.begin(), ans.end(), comp);
	int t; scanf("%d", &t);
	for(int x = 0; x < t; x++){
		printf("Case #%d: ", x+1);
		scanf("%s", s);
		A.clear();
		for(int i = 0; s[i]; i++) A.PB(s[i]-'0');
		scanf("%s", s);
		B.clear();
		for(int i = 0; s[i]; i++) B.PB(s[i]-'0');
		int pnt =
		upper_bound(ans.begin(), ans.end(), B, comp) -
		lower_bound(ans.begin(), ans.end(), A, comp);
		printf("%d\n", pnt);
	}
}
