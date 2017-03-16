#include <cstdio>
#include <algorithm>
#include <vector>
#define N 20
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, n;
LL aa, ab, best;
char s[N], t[N];

void go(int x, int y){
	//printf("%d %d %s %s\n", x, y, s, t);
	if(!s[x]){
		LL an = 0;
		fi(i, 0, x) an = an * 10 + s[i] - '0';
		LL bn = 0;
		fi(i, 0, x) bn = bn * 10 + t[i] - '0';
		
		LL d = abs(an - bn);
		if(d < best || d == best && an < aa || d == best && an == aa && bn < ab){
			best = d;
			aa = an;
			ab = bn;
		}
		
		return;
	}
	
	if(y < 0){
		if(s[x] == '?' && t[x] == '?'){
			s[x] = '9';
			t[x] = '0';
			go(x + 1, y);
			s[x] = t[x] = '?';
		}else if(s[x] == '?'){
			s[x] = '9';
			go(x + 1, y);
			s[x] = '?';
		}else if(t[x] == '?'){
			t[x] = '0';
			go(x + 1, y);
			t[x] = '?';
		}else go(x + 1, y);
	}else if(y > 0){
		if(s[x] == '?' && t[x] == '?'){
			s[x] = '0';
			t[x] = '9';
			go(x + 1, y);
			s[x] = t[x] = '?';
		}else if(s[x] == '?'){
			s[x] = '0';
			go(x + 1, y);
			s[x] = '?';
		}else if(t[x] == '?'){
			t[x] = '9';
			go(x + 1, y);
			t[x] = '?';
		}else go(x + 1, y);
	}else{
		if(s[x] == '?' && t[x] == '?'){
			s[x] = '0';
			t[x] = '0';
			go(x + 1, y);
			s[x] = '1';
			t[x] = '0';
			go(x + 1, 1);
			s[x] = '0';
			t[x] = '1';
			go(x + 1, -1);
			s[x] = t[x] = '?';
		}else if(s[x] == '?'){
			s[x] = t[x];
			go(x + 1, y);
			if(t[x] > '0'){
				s[x] = t[x] - 1;
				go(x + 1, -1);	
			}
			if(t[x] < '9'){
				s[x] = t[x] + 1;
				go(x + 1, 1);
			}
			s[x] = '?';
		}else if(t[x] == '?'){
			t[x] = s[x];
			go(x + 1, y);
			if(s[x] > '0'){
				t[x] = s[x] - 1;
				go(x + 1, 1);
			}
			if(s[x] < '9'){
				t[x] = s[x] + 1;
				go(x + 1, -1);
			}
			t[x] = '?';
		}else{
			if(s[x] == t[x])
				go(x + 1, y);
			else if(s[x] < t[x])
				go(x + 1, -1);
			else
				go(x + 1, 1);
		}
	}
}

void print(int x, LL a){
	if(x == n) return;
	print(x + 1, a / 10);
	printf("%d", a % 10);
}

void solve(int tt){
	scanf("%s %s", s, t);
	for(n = 0; s[n]; n++);
	
	best = 1000000000000000000LL;
	go(0, 0);
	printf("Case #%d: ", tt);
	print(0, aa);
	printf(" ");
	print(0, ab);
	puts("");
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc) solve(z);
	scanf("\n");
}
