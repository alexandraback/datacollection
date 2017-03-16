#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

const int SIZE = 2000000;
int board[SIZE];

bool subset_sum(vi &S, int b, int N) {
	int neg = 0, pos = 0;
	for (int i = 0; i<N; i++) {
		if (b&(1<<i)) neg += S[i];
		else pos += S[i];
	}

	for (int i = 0; i<neg+pos; ++i)
		board[i] = 0;

	//cout<<"b = "<<b<<" neg = "<<neg<<" pos = "<<pos<<endl;
	for (int i = 0; i<N; i++) {
		int v = S[i];
		if (b&(1<<i)) v = -S[i];
		
		//cout<<"Testing v="<<v<<endl;
		for (int a = 0; a<neg+pos; a++) {
			if (board[a] > 0 and (board[a]&(1<<i))==0 and board[a+v] == 0) {
				board[a+v] = board[a] | (1<<i);
				//cout<<"  "<<a-neg<<" + "<<v<<" = "<<a+v<<":"<<board[a+v]<<endl;
			}
		}
		if (board[neg+v] == 0) board[neg+v] = (1<<i);
	}

	if (board[neg] > 0) {
		//cout<<"Solution for neg="<<neg<<", "<<board[neg]<<endl;
		vi p, n;
		for (int i = 0; i<N; i++) {
			if (board[neg] & (1<<i)) {
				if (b & (1<<i)) {
					n.push_back(S[i]);
				} else {
					p.push_back(S[i]);
				}
			}
		}
		printf("%d",p[0]);
		for (int i = 1; i<p.size(); i++) {
			printf(" %d",p[i]);
		}
		printf("\n");
		printf("%d",n[0]);
		for (int i = 1; i<n.size(); i++) {
			printf(" %d",n[i]);
		}
		printf("\n");
		return true;
	}
	return false;
}

int main (void) {
    int T = 0;
    cin >> T;

    for (int c = 1; c<=T; ++c) {
		int N, t;
		cin >> N;
		vi S;
		S.reserve(N);
		for (int i = 0; i<N; ++i) {
			cin >> t;
			S.push_back(t);
		}
		
		printf("Case #%d:\n",c);
		bool found = false;
		for (int b = 1; b< (1<<N); ++b) {
			if (subset_sum(S, b, N)) {
				found = true;
				break;
			}
		}
		
		if (!found) {
			printf("Impossible\n");
		}
    }

    return 0;
}
