#include <stdio.h>
#include <cassert>
#include <cstring>
#include <map>
#include <set>
#include <time.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

typedef pair <int, int> ii;
typedef pair <long long, long long> ll;
typedef pair <long long, ll> pp;

char C[22], J[22];

long long getMax(long long s, int a, int b, char c[]) {

	for (int i = a; i <= b; i++) {
		if (c[i] == '?') s = s * 10 + 9;
		else s = s * 10 + (c[i] - '0');

	}
	return s;
}


long long getMin(long long s, int a, int b, char c[]) {

	for (int i = a; i <= b; i++) {
		if (c[i] == '?') s = s * 10 + 0;
		else s = s * 10 + (c[i] - '0');
	}
	return s;
}

void print(long long s, int l) {
	vector <long long> v;
	for (int i = 0; i < l; i++) {
		v.push_back(s % 10);
		s /= 10;
	}
	for (int i = ((int)v.size()) - 1; i >= 0; i--)
		printf("%lld", v[i]);
}

pp get(int st, int l) {
	
	long long Cs = 0, Js = 0;
	
	for (int i = st; i < l; i++) {
		if (C[i] == J[i] || C[i] == '?' || J[i] == '?') {
			if (C[i] == '?' && J[i] == '?') {
				C[i] = '0';
				J[i] = '0';
				pp same = get(i, l);
				C[i] = '1';
				J[i] = '0';
				pp bigC = get(i, l);
				C[i] = '0';
				J[i] = '1';
				pp bigJ = get(i, l);
				same = min(same, min(bigC, bigJ));
				for (int j = i; j < l; j++) {
					Cs = Cs * 10;
					Js = Js * 10;
				}
				Cs += same.second.second;
				Js += same.second.first;
				C[i] = J[i] = '?';
				break;
			}
			else if (J[i] == '?'){
				J[i] = C[i];
				pp same = get(i, l);
				for (int j = 0; j <= 9; j++) {
					J[i] = j + '0';
					if( J[i] != C[i])
						same = min( same, get(i, l) );
				}
				for (int j = i; j < l; j++) {
					Cs = Cs * 10;
					Js = Js * 10;
				}
				Cs += same.second.second;
				Js += same.second.first;
				J[i] = '?';			
				break;
			} else if( C[i] == '?' ){
				C[i] = J[i];
				pp same = get(i, l);
				for (int j = 0; j <= 9; j++) {
					C[i] = j + '0';
					if (J[i] != C[i])
						same = min(same, get(i, l));
				}
				for (int j = i; j < l; j++) {
					Cs = Cs * 10;
					Js = Js * 10;
				}
				Cs += same.second.second;
				Js += same.second.first;
				C[i] = '?';
				break;
			}
			else {
				Cs = Cs * 10 + (C[i] - '0');
				Js = Js * 10 + (J[i] - '0');
			}
		}
		else {

			if (J[i] < C[i]) {
				Js = getMax(Js, i, l - 1, J);
				Cs = getMin(Cs, i, l - 1, C);
			}
			else {
				Cs = getMax(Cs, i, l - 1, C);
				Js = getMin(Js, i, l - 1, J);
			}
			break;
		}

	}
	return pp(abs(Cs - Js), ll(Js, Cs));
}

void solve() {
	scanf("%s %s", C, J);

	int l = strlen(C);

	pp re = get(0, l);

	print(re.second.second, l);
	printf(" ");
	print(re.second.first, l);
	puts("");

}

int main() {
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int R = 1; R <= T; R++) {
		printf("Case #%d: ", R);
		solve();

	}

}