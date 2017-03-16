#include <cstdio>
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

int l; int x;

Symbol list[12001], prefix[12001], suffix[12001];
void work(){
	scanf("%d%d", &l, &x);
	scanf("%s", buf);
	if (l * x <= 2) {
		puts("NO");
		return ;
	}
	for (int i = 0; i < l * x; i++){
		list[i] = Symbol(buf[i % l]);
	}
	l = l * x;
	prefix[0] = list[0];
	for (int i = 1; i < l; i++)
		prefix[i] = prefix[i - 1] * list[i];

	suffix[l - 1] = list[l - 1];
	for (int i = l - 2; i >= 0; i--) {
		suffix[i] = list[i] * suffix[i + 1];
	}
	for (int i = 0; i < l - 2; i++){
		Symbol sb = list[i + 1];
		for (int j = i + 1; j < l - 1; j++){
			if (prefix[i] == Symbol(0, I) && suffix[j + 1] == Symbol(0, K) && sb == Symbol(0, J)){
				puts("YES");
				return ;
			}
			sb = sb * list[j + 1];

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
		work();
	}
}
