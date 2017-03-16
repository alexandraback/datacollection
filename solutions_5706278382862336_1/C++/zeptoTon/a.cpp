/* Problem A. Magic Trick */

/*
	using Set.
	n = 8
	runtime O(n)
	Mem O(n)
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
ll p, q;
int res=0;

ll gcd(ll a, ll b)
{
    if (b==0) return a;
    return gcd(b, a%b);
}

void SimplfyFraction(ll &resa, ll &resb){
	ll d = gcd(resa, resb);
	resa = resa / d;
	resb = resb / d;
}

int main(){
	freopen("input.in", "r", stdin);
	freopen("bigoutput.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		res = 0;
		scanf("%lld/%lld",&p ,&q);
		SimplfyFraction(p, q);
		if (((q & (q - 1)) != 0))
		{
			printf("Case #%d: impossible\n", i+1);
			continue;
		}else{
			double t = (double)p/q;
			while (t < 1){
				t *= 2;
				res++;
			}
			if (res==0) res =1;
		}
		printf("Case #%d: %d\n", i+1, res);
	}

	return 0;
}