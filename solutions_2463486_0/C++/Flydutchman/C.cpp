#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

struct Big {
	int a[110];
	Big() { Fill(a,0); a[0] = 1; }
	void Print() {
		printf("%d",a[a[0]]);
		Cor(i,a[0] - 1,1) {
			//if (a[i] < 100) printf("0");
			//if (a[i] < 10) printf("0");
			printf("%d",a[i]);
		}
		cout << endl;
	}
};

Big operator + (Big a,Big b) {
	int l = max(a.a[0],b.a[0]);
	For(i,1,l) a.a[i] += b.a[i];
	For(i,1,l) {
		int t = a.a[i] / 10; a.a[i + 1] += t; a.a[i] -= 10 * t;
	}
	while (a.a[l + 1]) { ++l;
		int t = a.a[l] / 10; a.a[l + 1] += t; a.a[l] -= 10 * t;
	}
	a.a[0] = l; return a;
}

Big operator * (Big a,Big b) {
	Big c; int l = a.a[0] + b.a[0] - 1;
	For(i,1,a.a[0]) For(j,1,b.a[0]) c.a[i + j - 1] += a.a[i] * b.a[j];
	For(i,1,l) {
		int t = c.a[i] / 10; c.a[i + 1] += t; c.a[i] -= 10 * t;
	}
	while (c.a[l + 1]) { ++l;
		int t = c.a[l] / 10; c.a[l + 1] += t; c.a[l] -= 10 * t;
	}
	c.a[0] = l; return c;
}

bool operator < (Big a,Big b) { // only for a and b with the same opt
	if (a.a[0] != b.a[0]) return a.a[0] < b.a[0];
	Cor(i,a.a[0],1) {
		if (a.a[i] != b.a[i]) return a.a[i] < b.a[i];
	}
	return false ;
}

bool check(Big a) {
	For(i,1,a.a[0] / 2) if (a.a[i] != a.a[a.a[0] + 1 - i]) return false ;
	return true;
}

Big cache[MaxN]; Big cur;
int n,Tot = 0; int rem = 0;
void dfs(int now) {
	if (now > n) {
		For(i,1,n - 1) cur.a[n + n - i] = cur.a[i];
		cur.a[0] = n + n - 1;
		Big t = cur * cur;
		if (check(t)) cache[++Tot] = t;
		For(i,n + 2,n + n) cur.a[i] = cur.a[i - 1]; cur.a[n + 1] = cur.a[n];
		cur.a[0] = n + n;
		t = cur * cur;
		if (check(t)) cache[++Tot] = t;
		return ;
	}
	For(i,now == 1,2 + (now == 1)) {
		if (now < n && i == 2 && now > 1) break ;
		cur.a[now] = i; rem -= i * i; if (rem < 0) { rem += i * i; continue ; }
		dfs(now + 1); rem += i * i;
	}
}

string s,s1,s2;
int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	For(i,1,30938) {
		cin >> s;
		cache[++Tot].a[0] = s.length();
		Cor(i,s.length() - 1,0) cache[Tot].a[cache[Tot].a[0] - i] = s[i] - '0';
	}
	
	int T; cin >> T;
	For(TTT,1,T) { printf("Case #%d: ",TTT);
		cin >> s1 >> s2;
		Big A,B;
		A.a[0] = s1.length();
		Cor(i,s1.length() - 1,0) A.a[A.a[0] - i] = s1[i] - '0';
		B.a[0] = s2.length();
		Cor(i,s2.length() - 1,0) B.a[B.a[0] - i] = s2[i] - '0';
		int l = 0,r = Tot;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (cache[mid] < A) l = mid; else r = mid - 1;
		}
		int t1 = l;
		l = 0, r = Tot;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if(mid==2) {
				int z=mid;
			}
			if (B < cache[mid]) r = mid - 1; else l = mid;
		}
		cout << l - t1 << endl;
	} 
	int z = Tot;
	return 0;
}

