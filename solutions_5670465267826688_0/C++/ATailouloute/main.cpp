/*
 * author ATailouloute
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <climits>
#include <deque>

using namespace std;

#define F(i,L,R)   for(int i=L; i<R;  i++)
#define FE(i,L,R)  for(int i=L; i<=R; i++)
#define FF(i,L,R)  for(int i=L; i>R;  i--)
#define FFE(i,L,R) for(int i=L; i>=R; i--)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

/**
 * 1 --> 1
 * i --> 2
 * j --> 3
 * k --> 4
 */

int x[4][4] = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };


int mul(int a, int b) {
	int sign = a < 0 || b < 0 ? -1 : 1;
	a = abs(a);
	b = abs(b);
	int ret = x[a - 1][b - 1];
	return sign * ret;
}

int hash(char c){
	return (c == '1') ? 1 : c - 'i' + 2;
}

int mul(char a, char b){
	return mul(hash(a), hash(b));
}

int read(){
	char c;
	do {
		scanf("%c", &c);
	}while(c < 'i' || c > 'k');
	return hash(c);
}

int main() {

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out","w",stdout) ;

	int T, X, L, XX[10000];
	scanf("%d", &T);

	FE(caseID ,1, T){
		bool ok = false;
		scanf("%d %d", &X, &L);

		F(i, 0, X){
			XX[i] = read();
		}

		deque<int> D;

		F(i, 0, L){
			F(j, 0, X){
				D.push_back(XX[j]);
			}
		}

		// Make i
		while(D.front() != 2 && D.size() >= 2){
			int ret = D.front();
			D.pop_front();
			ret = mul(ret, D.front());
			D.pop_front();
			D.push_front(ret);
		}

		if(!D.empty() && D.front() == 2){

			D.pop_front();

			// Make j
			while(D.front() != 3 && D.size() >= 3){
				int ret = D.front();
				D.pop_front();
				ret = mul(ret, D.front());
				D.pop_front();
				D.push_front(ret);
			}

			if(!D.empty() && D.front() == 3){

				D.pop_front();

				int ret = D.front();
				D.pop_front();

				while(!D.empty()){
					ret = mul(ret, D.front());
					D.pop_front();
				}

				if(ret == 4){
					ok = true;
				}

			}

		}

		printf("Case #%d: %s\n", caseID, ok ? "YES" : "NO");
	}

	return 0;
}
