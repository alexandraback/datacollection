// run: $exec < c-small.in > c-small.out
#include <iostream>
#include <stack>

int n, m;

long long change(long long x, int base)
{
	long long tb = 1;
	long long ret = 0;
	for (int i = 0; i < n; i++, x /= 2) {
		ret += tb * (x & 1);
		tb *= base;
	}
	return ret;
}

void print(long long x, long long hx)
{
	std::stack<int> s;
	for (int i = 0; i < n; i++, x /= 2) s.push(x & 1);
	for (; !s.empty(); s.pop()) std::cout << s.top();
	for (int i = 2; i <= 10; i++) std::cout << ' ' << change(hx, i);
	std::cout << '\n';
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	std::cout << "Case #1:\n";
	std::cin >> n >> m;
	int half = n / 2;
	for (int i = 0; m-- && i < (1 << (half - 2)); i++) {
		long long tmp = i * 2 + 1 + (1 << (half - 1));
		long long tt = tmp * (1 << half) + tmp;
		print(tt, tmp);
	}
}

