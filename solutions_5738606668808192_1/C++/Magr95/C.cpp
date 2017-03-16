#include <cstdio>
#include <iostream>
#include <queue>
#include <bitset>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

int N = 32;

int divis[11];

vector<int> v;

ll sieve_size;
bitset<10000010> bs;
unordered_set<ll> primes;

void sieve(ll upperbound) {
    sieve_size=upperbound+1;
    bs.set(); bs[0]=bs[1]=0;
    for (ll i=2; i<=sieve_size; i++) if(bs[i]) {
        for (ll j=i*i; j<=sieve_size; j+=i) bs[j] = 0;
        primes.insert(i);
    }
}

void proc(int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int cont) {
	//printf("T%d\n", cont);
	if (cont == N - 1) {
		v[cont] = 1;
		if (!primes.count(p2*2 + 1) && !primes.count(p3*3 + 1) && !primes.count(p4*4 + 1) && !primes.count(p5*5 + 1)
			&& !primes.count(p6*6 + 1) && !primes.count(p7*7 + 1) && !primes.count(p8*8 + 1) && !primes.count(p9*9 + 1)
			&& !primes.count(p10*10 + 1)) {
			for (int i = 0; i < N; i++) cout << v[i];
			cout << endl;
		}
	} else {
		v[cont] = 0;
		proc(p2*2, p3*3, p4*4, p5*5, p6*6, p7*7, p8*8, p9*9, p10*10, cont + 1);
		v[cont] = 1;
		proc(p2*2 + 1, p3*3 + 1, p4*4 + 1, p5*5 + 1, p6*6 + 1, p7*7 + 1, p8*8 + 1, p9*9 + 1, p10*10 + 1, cont + 1);
	}
}

void proc2(__int128 p2, __int128 p3, __int128 p4, __int128 p5, __int128 p6, __int128 p7, __int128 p8, __int128 p9, __int128 p10, int cont) {
	//printf("T%d\n", cont);
	if (cont == N - 1) {
		v[cont] = 1;
		/*if (!primes.count(p2*2 + 1) && !primes.count(p3*3 + 1) && !primes.count(p4*4 + 1) && !primes.count(p5*5 + 1)
			&& !primes.count(p6*6 + 1) && !primes.count(p7*7 + 1) && !primes.count(p8*8 + 1) && !primes.count(p9*9 + 1)
			&& !primes.count(p10*10 + 1)) {
			for (int i = 0; i < N; i++) cout << v[i];
			cout << endl;
		}*/
		p2 = p2*2 + 1;
		p3 = p3*3 + 1;
		p4 = p4*4 + 1;
		p5 = p5*5 + 1;
		p6 = p6*6 + 1;
		p7 = p7*7 + 1;
		p8 = p8*8 + 1;
		p9 = p9*9 + 1;
		p10 = p10*10 + 1;
		for (int j = 0; j < 11; j++) divis[j] = -1;
		int contT = 0;
		for (int j = 3; j < 10000 && contT < 9; j++) {
			if (divis[2] == -1 && p2 % j == 0 && p2 != j) divis[2] = j, contT++;
			if (divis[3] == -1 && p3 % j == 0 && p3 != j) divis[3] = j, contT++;
			if (divis[4] == -1 && p4 % j == 0 && p4 != j) divis[4] = j, contT++;
			if (divis[5] == -1 && p5 % j == 0 && p5 != j) divis[5] = j, contT++;
			if (divis[6] == -1 && p6 % j == 0 && p6 != j) divis[6] = j, contT++;
			if (divis[7] == -1 && p7 % j == 0 && p7 != j) divis[7] = j, contT++;
			if (divis[8] == -1 && p8 % j == 0 && p8 != j) divis[8] = j, contT++;
			if (divis[9] == -1 && p9 % j == 0 && p9 != j) divis[9] = j, contT++;
			if (divis[10] == -1 && p10 % j == 0 && p10 != j) divis[10] = j, contT++;
		}
		if (contT == 9) {
			for (int i = 0; i < N; i++) cout << v[i];
			for (int i = 2; i <= 10; i++) cout << " " << divis[i];
			cout << endl;
		}


	} else {
		v[cont] = 0;
		proc2(p2*2, p3*3, p4*4, p5*5, p6*6, p7*7, p8*8, p9*9, p10*10, cont + 1);
		v[cont] = 1;
		proc2(p2*2 + 1, p3*3 + 1, p4*4 + 1, p5*5 + 1, p6*6 + 1, p7*7 + 1, p8*8 + 1, p9*9 + 1, p10*10 + 1, cont + 1);
	}
}

int main() {
	//freopen("C-small-practice.in", "r", stdin);
	//freopen("C-large-practice.in", "r", stdin);
	freopen("large.out", "w", stdout);
	//sieve(1000000);
	v.assign(N, 0);
	v[0] = 1;
	printf("Case #1:\n");
	proc2(1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	//sieve(1000000);printf("----\n");proc(1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	return 0;
}
