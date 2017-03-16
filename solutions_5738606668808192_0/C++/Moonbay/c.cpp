/*
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
#include <bitset>
using namespace std;
typedef long long LL;
int modular_exp(int a, int b, int c) {
	LL res, temp;
	res = 1 % c, temp = a % c;
	while (b) {
		if (b & 1) {
			res = res * temp % c;
		}
		temp = temp * temp % c;
		b >>= 1;
	}
	return (int) res;
}

int N, J;
int arr[11];
const int ptn = 168;
const int pt[ptn] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

bool isprime(LL d, int k) {
	for (int i = 0; i < ptn; i++) {
		int p = pt[i];
		int mod = 0;
		LL tmp = d;
		int b = 0;
		while (tmp > 0) {
			if (tmp % 2 == 1) {
				mod += modular_exp(k, b, p);
				mod %= p;
			}
			b++;
			tmp /= 2;
		}
		if (mod == 0) {
			arr[k] = p;
			return false;
		}
	}
	return true;
}

bool judge(LL d) {
	for (int k = 2; k <= 10; k++) {
		if (isprime(d, k)) {
			return false;
		}
	}
	return true;
}

void work() {
	printf("Case #1:\n");
	LL s = (1LL << (N - 1)) + 1;
	LL e = 1LL << N;
	int pn = 0;
	for (; s < e && pn < J; s += 2) {
		if (judge(s)) {
			if (N == 16) {
				bitset<16> bs(s);
				cout << bs;
			} else {
				bitset<32> bs(s);
				cout << bs;
			}
			for (int i = 2; i <= 10; i++) {
				printf(" %d", arr[i]);
			}
			putchar('\n');
			pn++;
		}
	}
}

int main1() {
	if (judge(35)) {
		cout << "true!" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &J);
		work();
	}
	return 0;
}


