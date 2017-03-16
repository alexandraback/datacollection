#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

#define LLU long long unsigned int
#define MAX 1000001

int T, X, Y;

int abs(int i) { return (i < 0)? -i : i; }

string solve() {
	string out = "";
	for(int i=0;i<abs(X);i++)
		out+= (X > 0) ? "WE" : "EW";
	for(int i=0;i<abs(Y);i++)
		out+=(Y > 0) ? "SN" : "NS";
	return out;
}

int main() {
	freopen("a.in", "r", stdin);
    freopen("op.out", "w", stdout);
	scanf("%d", &T);
	int count=1;
	while(T--) {
		scanf("%d %d", &X, &Y);
		printf("Case #%d: %s\n", count++, solve().c_str());
	}
	return 0;
}