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

const int maxn = 10004;
vector <int> ans(maxn, 0);

bool f(char c){
    if(c=='a' || c=='o' || c=='e' || c=='u' || c=='i') 
		return 0;
    return 1;
}

int main(){

	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

    int T = in(), t = 0;
	
    while(t < T){        
		string res;
		printf("Case #%d: ", ++t);
		int cur = 0;
		int x = in(), y = in();
		if(y>0){
		while( cur != y) {
			cur++;
			printf("SN");
		}
		}
	   if(y<0){
		while(cur != y) {
			cur--;
			printf("NS");
		}
	    }
		cur = 0;
		if(x>0){
		while(cur != x) {
			cur++;
			printf("WE");
		}
		}
		if(x<0){
		while(cur != x) {
			cur--;
			printf("EW");
		}
		}
		printf("\n");
    }

	return 0;
}