#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:167772160000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <sstream>
#include <assert.h>
#include <functional>
#include <climits>
#include <cstring>

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
typedef std::pair<long double,long double> pdd;
#define forn(N)          for(int i = 0; i<(int)N; i++)
#define fornj(N)         for(int j = 0; j<(int)N; j++)
#define fornk(N)         for(int k = 0; k<(int)N; k++)
#define forn1(N)          for(int i = 1; i<=(int)N; i++)
#define fornj1(N)         for(int j = 1; j<=(int)N; j++)
#define fornk1(N)         for(int k = 1; k<=(int)N; k++)
#define PI 3.1415926535897932384626433
#define v vector
#define ll long long
#define print(n) printf("%d ", (n));
#define printll(n) printf("%I64d", (n));
#define printline() printf("\n");
#define read(n) scanf("%d", &n);
#define read2(n, m) scanf("%d%d", &n, &m);
#define readll(n) scanf("%I64d", &n);
#define mp make_pair
using namespace std;

v<int> Cans, Jans;
ll ans;
ll ansC, ansJ;
v<int>C, J;
int n;
v<int>Cnow, Jnow;

bool see() {
	v<int>a;
	forn(3)a.push_back(0);
	v<int>b;
	forn(3)b.push_back(0);

	for (a[0] = 0; a[0] < 10; a[0]++)
		for (a[1] = 0; a[1] < 10; a[1]++)
			for (a[2] = 0; a[2] < 10; a[2]++)
				for (b[0] = 0; b[0] < 10; b[0]++)
					for (b[1] = 0; b[1] < 10; b[1]++)
						for (b[2] = 0; b[2] < 10; b[2]++) {
							bool f = 0;
							forn(n)if (a[i] != C[i] && C[i] != -1)f = 1;
							forn(n)if (b[i] != J[i] && J[i] != -1)f = 1;
							if (f)continue;

							ll Csum = 0;
							ll Jsum = 0;
							forn(n) {
								Csum *= 10;
								Jsum *= 10;
								Csum += a[i];
								Jsum += b[i];

							}
							ll diff = abs(Csum - Jsum);
							if (diff < ans || (diff == ans && Csum < ansC) || (diff == ans && Csum == ansC && Jsum < ansJ)) {
								return 1;


							}
						}
	
	if (Cans.size() != n || Jans.size() != n)return 1;
	forn(n)if (Cans[i]!= C[i] && C[i] != -1)return 1;
	forn(n)if (Jans[i]!= J[i] && J[i] != -1)return 1;

	return 0;
}

void chk() {
	ll Csum = 0;
	ll Jsum = 0;
	forn(n) {
		Csum *= 10;
		Jsum *= 10;
		Csum += Cnow[i];
		Jsum += Jnow[i];

	}
	ll diff = abs(Csum - Jsum);

	if (diff < ans || (diff == ans && Csum < ansC) || (diff == ans && Csum == ansC && Jsum < ansJ)) {
		ans = diff;
		ansC = Csum;
		ansJ = Jsum;
		Cans = Cnow;
		Jans = Jnow;


	}
	return;

}
void src1(int a) {
	if (a == n) {
		chk();
		return;
	}
	Cnow.push_back(C[a]);
	Jnow.push_back(J[a]);
	if (Cnow.back() == -1)Cnow.back() = 0;
	if (Jnow.back() == -1)Jnow.back() = 9;
	src1(a + 1);
	Cnow.pop_back();
	Jnow.pop_back();
	return;
}


void src2(int a) {
	if (a == n) {
		chk();
		return;
	}
	Cnow.push_back(C[a]);
	Jnow.push_back(J[a]);
	if (Cnow.back() == -1)Cnow.back() = 9;
	if (Jnow.back() == -1)Jnow.back() = 0;
	src2(a + 1);
	Cnow.pop_back();
	Jnow.pop_back();
	return;
}




void src0(int a) {
	if (a == n) {
		chk();
		return;
	}
	if (C[a] == -1 && J[a] == -1) {
		Cnow.push_back(0);
		Jnow.push_back(0);
		src0(a + 1);
		Cnow.back() = 1;
		src1(a + 1);
		Cnow.back() = 0;
		Jnow.back() = 1;
		src2(a + 1);
		Cnow.pop_back();
		Jnow.pop_back();
		
	}
	else if (C[a] == -1) {
		Jnow.push_back(J[a]);
		Cnow.push_back(J[a]);
		src0(a + 1);
		Cnow.back()--;
		if (Cnow.back() >= 0)src2(a + 1);
		Cnow.back() += 2;
		if (Cnow.back() <= 9)src1(a + 1);
		Cnow.pop_back();
		Jnow.pop_back();

	}
	else if (J[a] == -1) {

		Cnow.push_back(C[a]);
		Jnow.push_back(C[a]);
		src0(a + 1);
		Jnow.back()--;
		if (Jnow.back() >= 0)src1(a + 1);
		Jnow.back() += 2;
		if (Jnow.back() <= 9)src2(a + 1);
		Cnow.pop_back();
		Jnow.pop_back();

	}
	else {
		Cnow.push_back(C[a]);
		Jnow.push_back(J[a]);
		if (Cnow.back() == Jnow.back())src0(a + 1);
		else if (Cnow.back() > Jnow.back())src1(a + 1);
		else if (Cnow.back() < Jnow.back())src2(a + 1);
		Cnow.pop_back();
		Jnow.pop_back();
	}
	return;

}

int main()
{
#if defined(_DEBUG) || defined(_RELEASE)
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//(File".in", "r", stdin); freopen(File".out", "w", stdout);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int T; cin >> T;
	fornk1(T) {
		if (Cnow.size() || Jnow.size())
			cout << endl << endl;
		string CC, JJ; cin >> CC >> JJ;
		ansC = ansJ = ans = 5E18;
		C.clear();
		J.clear();
		forn(CC.length())if (CC[i] != '?')C.push_back(CC[i] - '0');
		else C.push_back(-1);
		forn(JJ.length())if (JJ[i] != '?')J.push_back(JJ[i] - '0');
		else J.push_back(-1);
		n = C.size();
		src0(0);
		//ans++;
		if (see())
			cout << endl << endl;
		cout << "Case #" << k << ": ";
		forn(n)cout << Cans[i];
		cout << " ";
		forn(n)cout << Jans[i];
		cout << endl;

	}
	

	return 0;

}
