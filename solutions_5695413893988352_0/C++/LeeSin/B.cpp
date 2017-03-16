#include <cstdio>
#include <algorithm>
#include <vector>
#define N 20
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, best, n, aa, ab;
char s[N], t[N];
vector<int> sv, tv;

void go(int x, char s[], vector<int> &v){
	if(!s[x]){
		int r = 0;
		fi(i, 0, x) r = r * 10 + s[i] - '0';
		v.push_back(r);
		return;
	}
	
	if(s[x] == '?'){
		fi(i, 0, 10){
			s[x] = i + '0';
			go(x + 1, s, v);
			s[x] = '?';
		}
	}else go(x + 1, s, v);
}

void print(int x, int a){
	if(x == n) return;
	print(x + 1, a / 10);
	printf("%d", a % 10);
}

void solve(int tt){
	scanf("%s %s", s, t);
	for(n = 0; s[n]; n++);
	sv.clear();
	tv.clear();
	
	go(0, s, sv);
	go(0, t, tv);
	
	best = 1000000000;
	
	fi(i, 0, sv.size()) fi(j, 0, tv.size()){
		int d = abs(sv[i] - tv[j]);
		if(d < best || d == best && sv[i] < aa || d == best && sv[i] == aa && tv[j] < ab){
			best = d;
			aa = sv[i];
			ab = tv[j];
		}
	}
	
	printf("Case #%d: ", tt);
	print(0, aa);
	printf(" ");
	print(0, ab);
	puts("");
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc) solve(z);
	scanf("\n");
}
