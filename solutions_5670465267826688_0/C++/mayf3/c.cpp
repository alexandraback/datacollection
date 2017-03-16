#include <cstdio>

const int N = 23333;

typedef long long LL;

struct Node{
	int sign;
	int val;
	Node(){
		sign = 1;
		val = 0;
	}
	Node(int s, int v) : sign(s), val(v){}
};

const Node I = Node(1, 1), J = Node(1, 2), K = Node(1, 3);

Node operator *(const Node &a, const Node &b){
	if (a.val == 0) return Node(a.sign * b.sign, b.val);
	if (b.val == 0) return Node(a.sign * b.sign, a.val);
	int x = (a.val - b.val + 3) % 3;
	if (x == 0) return Node(a.sign * b.sign * -1, 0);
	if (x == 1) return Node(a.sign * b.sign * -1, a.val % 3 + 1);
	if (x == 2) return Node(a.sign * b.sign, b.val % 3 + 1);
}

bool operator ==(const Node &a, const Node &b){
	return a.sign == b.sign && a.val == b.val;
}

bool operator !=(const Node &a, const Node &b){
	return !(a == b);
}

int n;
LL x;
char s[N];

Node base;

Node change(char ch){
	if (ch == 'i') return Node(1, 1);
	if (ch == 'j') return Node(1, 2);
	if (ch == 'k') return Node(1, 3);
	return Node(0, 0);
}

Node calc(Node a, LL n){
	Node ret(1, 0);
	while(n){
		if (n & 1) ret = ret * a;
		a = a * a;
		n >>= 1;
	}
	return ret;
}

bool init(){
	scanf("%d%lld", &n, &x);
	scanf("%s", s);
	base = Node(1, 0);
	for(int i = 0; i < n; i++){
		base = base * change(s[i]);
	}
	if (calc(base, x) != Node(-1, 0)) return false;
	return true;
}

void solve(){
	LL pos_i = -1, pos_j = -1;
	if (x <= 20){
		Node now = Node(1, 0);
		for(LL i = 0; i < x; i++){
			for(LL j = 0; j < n; j++){
				now = now * change(s[j]);
				if (now == I){
					if (pos_i == -1) pos_i = i * n + j;
				}
				if (now == K){
					pos_j = i * n + j;
				}
			}
		}
	}
	else{
		Node now = Node(1, 0);
		for(LL i = 0; i < 8; i++){
			for(LL j = 0; j < n; j++){
				now = now * change(s[j]);
				if (now == I){
					if (pos_i == -1) pos_i = i * n + j;
				}
			}
		}
		now = calc(base, x - 8);
		for(LL i = x - 8; i < x; i++){
			for(LL j = 0; j < n; j++){
				now = now * change(s[j]);
				if (now == K){
					pos_j = i * n + j;
				}
			}
		}
	}
	if (pos_i != -1 && pos_j != -1 && pos_i < pos_j){
		puts("YES");
	}
	else{
		puts("NO");
	}
}

int main(){
	int test;
	scanf("%d", &test);
	for(int cas = 1; cas <= test; cas++){
		printf("Case #%d: ", cas);
		if (init()){
			solve();
		}
		else{
			puts("NO");
		}
	}
}
