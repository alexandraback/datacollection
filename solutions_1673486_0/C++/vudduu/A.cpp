#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

void solve(int caso){
	int A, B;
	double r = 0.0;
	scanf("%d %d", &A, &B);
	vector<double> pos(A+1);
	vector<double> probTRUE(A+2, 0);
	vector<double> probFALSE(A+2, 0);
	vector<double> probFALSESUM(A+2, 0);
	F(i, A+1){
		if(i < A) cin>>pos[i];
		else pos[i] = 1.0;
		if(i){
			probTRUE[i] = probTRUE[i-1] * pos[i];
			probFALSE[i] = probTRUE[i-1] * (1.0 - pos[i]);
			probFALSESUM[i] = probFALSE[i] + probFALSESUM[i-1];
		}
		else{
			probTRUE[i] = pos[i];
			probFALSE[i] = 1.0 - pos[i];
			probFALSESUM[i] = probFALSE[i];
		}
	}
	r = B+2; //Keystrokes if I press enter right away
	r = min(r, double(A + B) + 1.0); //Keystrokes if I press backspace 'A' times
	F(ba, A){ //Keystrokes if I press backspace 'ba' times
		double aux = probFALSESUM[A-ba-1] * (ba*2 + B-A + 1 + B + 1);
		aux += probTRUE[A-ba-1] * (ba*2 + B-A + 1);
		r = min(aux, r);
	}
	cout<<"Case #"<<caso<<": ";
	printf("%.7lf\n", r);
}

int main(){
	//freopen("a.in", "r", stdin);
	freopen("A-small-attempt0.in.txt", "r", stdin);
	//freopen("A-large.in.txt", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solve(i+1); }
}

