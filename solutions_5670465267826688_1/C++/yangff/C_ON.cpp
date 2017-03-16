#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;
enum Sym {
	O, I, J, K
};

Sym symtable[4][4] = {
	{O, I, J, K},
	{I, O, K, J},
	{J, K, O, I},
	{K, J, I, O}
};

bool negtable[4][4] = {
	{0,0,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,0,1,1}
};

struct Symbol { 
	bool negative; // 0 = 1, 1 = -1
	Sym symbol;
	Symbol(bool negative = 0, Sym symbol = O):negative(negative), symbol(symbol){};
	Symbol(char ch){
		negative = 0;
		if (ch == 'i')
			symbol = I;
		if (ch == 'j')
			symbol = J;
		if (ch == 'k')
			symbol = K;
	}
	Symbol operator * (const Symbol &rsh){
		return Symbol(negative ^ rsh.negative ^ negtable[(int)symbol][(int)rsh.symbol], symtable[(int)symbol][(int)rsh.symbol]);
	}
	bool operator == (const Symbol &rsh){
		return negative == rsh.negative && symbol == rsh.symbol;
	}
	void print(){
		if (negative)
			printf("-");
		if (symbol == I)
			printf("i");
		if (symbol == J)
			printf("j");
		if (symbol == K)
			printf("k");
		if (symbol == O)
			printf("1");
	}
};

char buf[12001];

int l; long long x;

Symbol list[12001], prefix[12001], suffix[12001], sum[5];
void work(bool pr){
	scanf("%d", &l); scanf("%lld", &x);
	scanf("%s", buf);
	if (pr){
		//fprintf(stderr, "%d %lld\n", l, x);
		//fprintf(stderr, "%s", buf);
	} else return;
	if ((long long)l * x <= 2) {
		puts("NO");
		return ;
	}
	for (int i = 0; i < l; i++){
		list[i] = Symbol(buf[i]);
	}
	prefix[0] = list[0];
	for (int i = 1; i < l; i++)
		prefix[i] = prefix[i - 1] * list[i];
	suffix[l] = Symbol(0, O);
	suffix[l - 1] = list[l - 1];
	for (int i = l - 2; i >= 0; i--) {
		suffix[i] = list[i] * suffix[i + 1];
	}
	// 0	1	2	3	4
	// 1	i	-1	-i	1
	// 1	-i	1
	sum[0] = Symbol(0, O);
	sum[1] = prefix[l - 1];
	int cycle = 2;
	for (int i = 2; i <= 4; i++) {
		sum[i] = (sum[i - 1] * prefix[l - 1]);
		if (sum[i] == sum[0]) {
			cycle = i;
			break;
		}
	}
	Symbol A = sum[x % cycle];
	if (A == Symbol('i') * Symbol('j') * Symbol('k')) {
		int i = 0, j = 0;
		bool oI = false, oJ = false;
		for (int use = 0; use < min(x, (long long)cycle); use++)
			for (i = 0; i < l; i++)
			if (sum[use] * prefix[i] == Symbol('i')) {
				oI = true;
				x -= use;
				break;
			}
		for (int use = 0; use < min(x, (long long)cycle); use++)
			for (j = l - 1; j >= 0; j--)
			if (suffix[j] * sum[use] == Symbol('k')) {
				oJ = true;
				x -= use;
				break;
			}
		if (!oI || !oJ){
			puts("NO");
			return ;
		}
		if (x <= 0) {
			puts("NO");
			return ;
		}
		if (x == 1){
			if (i + 1 < j){
				puts("YES");
				return ;
			}
		} else if (x == 2){
			if (i != l - 1 && j != 0){
				puts("YES");
				return ;
			} 
		} else {
			puts("YES");
			return ;
		}
	}
	puts("NO");
}

int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		work(true);
		fflush(stdout);
		fprintf(stderr, ".");
	}
}
