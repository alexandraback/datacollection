#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   
};

long long kgcd(long long a, long long b){ 
if(a == 0) return b; 
if(b == 0) return a; 
if(!(a & 1) && !(b & 1)) return kgcd(a>>1, b>>1) << 1; 
else if(!(b & 1)) return kgcd(a, b>>1); 
else if(!(a & 1)) return kgcd(a>>1, b); 
else return kgcd(abs(a - b), min(a, b)); 
}

int main() {
	long long T;
	freopen("A-large.in", "r", stdin);
	freopen("output1.txt", "w", stdout);

	scanf("%I64d", &T);
	long long P, Q;
	char c;
	for (long long i=0; i<T; ++i) {
		scanf("%I64d", &P);
		scanf("%c", &c);
		scanf("%I64d", &Q);
		long long gcd = kgcd(P, Q);
		P = P/gcd;
		Q = Q/gcd;
		if ((Q & (Q - 1)) != 0) {
			printf("Case #%I64d: impossible\n", i+1);
			continue;
		}
		double value = Q * 1.0 / P;
		long long res = 1;
		long long curValue = 2;
		while (curValue < value) {
			++ res;
			curValue = curValue<<1;
		}
		printf("Case #%I64d: %I64d\n", i+1, res);
	}
	return 0;
}