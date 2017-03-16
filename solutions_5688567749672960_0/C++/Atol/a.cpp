#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(I,C) for(__typeof(C.begin()) I = (C).begin(); I != (C).end(); I++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair

#define MAX 100000001

int pd[MAX];
int N;

int reverse(int x) {
	if (x % 10 == 0) {
		return x;
	}
	int aux = 0;
	while(x) {
		aux *= 10;
		aux += (x%10);
		x /= 10;
	}
	return aux;
}

void solve() {
	cin >> N;
	FOR(i, N+1) pd[i] = i;


	for(int i = 1; i <= N; i++) {
		int a = i+1;
		pd[a] = min(pd[a], pd[i] + 1);

		int b = reverse(i);
		pd[b] = min(pd[b], pd[i] + 1);
	}

	cout << pd[N] << endl;
	/*
	FOR(i, N + 1) {
		cout << "PD " << i << " = " << pd[i] << endl;
	}
	*/
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
