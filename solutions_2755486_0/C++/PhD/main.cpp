#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
using namespace std;

int buf;
inline int in(){
	scanf("%d", &buf);
	return buf;
}

long long gcd(long long a, long long  b,long long  &x, long long  &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a)*x1;
	y = x1;
	return d;
}

long long lcm(long a, long b){
	long long  x, y;
	return a/gcd(a, b, x, y)*b;
}


int gcd(int a, int b, int &x, int &y){
	if(a == 0){
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int g = gcd(b % a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return g;
}

int rev(int a, int p){
	int x, y;
	int g = gcd(a, p, x, y);
	if(g == 1){
		return  (x%p + p) % p;		
	}

}

int binpow(int a, int n, int p){
	int res = 1;
	while(n){
		if(n & 1) res = (res * a) % p;
		a = (a * a) % p;
		n >>= 1;
	}
	return res;
}

int inv(int a, int m){
	int x, y;
	int g = gcd(a, m, x, y);
	if (g == 1){
		x = (x % m + m) % m;
		return x;
	}
}



bool f(char c){
    if(c=='a' || c=='o' || c=='e' || c=='u' || c=='i') 
		return 0;
    return 1;
}

struct trib{
    long long firsd, n, l, r, s;
    long long deld, deldist, dels;
};

struct att{
    long long curd, l, r, s;
};

bool comp(const att a, const att b){
    return a.curd<b.curd;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

    int T = in(), t = 0;
    while(t < T){
        int n = in();
        vector<trib> v;
        long long ans=0;
        for(int i = 0; i < n; ++i){
            trib cur;
            cur.firsd = in();
            cur.n = in();
            cur.l = in();
            cur.r = in();
            cur.s = in();
            cur.deld = in();
            cur.deldist = in();
            cur.dels = in();
            v.push_back(cur);
        }
        vector<att> a;
        long long mid = 50000;
        for(int i=0;i<v.size();++i){
            trib cur=v[i];
             long long curd=cur.firsd, str=cur.s, curl=cur.l, curr=cur.r;
            for(int j=1;j<=cur.n;++j){
                att at;
                at.curd=curd;
                at.s=str;
                at.l=curl*4+mid;
                at.r=curr*4+mid;
                a.push_back(at);

                curd+=cur.deld;
                str+=cur.dels;
                curl+=cur.deldist;
                curr+=cur.deldist;
            }
        }
        sort(a.begin(), a.end(), comp);
        int lastd=0;
        vector<  long long> wall(100000, 0), w;
		w=wall;
        for(int i=0;i<a.size();++i){
            att cur=a[i];
            if(cur.curd>lastd) wall=w;
            bool ta=0;
            for(int j = cur.l; j<=cur.r; ++j){
                if(wall[j]<cur.s)  ta=1, w[j]=max(cur.s, w[j]);
             
            }
            if(ta) ans++;
            lastd=cur.curd;
        }
        printf("Case #%d: %lld\n", ++t, ans);
	}
	return 0;
}