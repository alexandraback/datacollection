#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
#define VAR(a,b) typeof(b) a=b
#define dout cout
using namespace std;
typedef long long LL;

int Log10(int i, int& sig){
	sig=1;
	int k=0;
	while(i>=sig*10) {
		sig*=10;
		k++;
	}
	return k;
}

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		int a, b;
		cin >> a >> b;
		int k=0;
		for(int i=a+1;i<=b;i++){
			int sig;
			Log10(i, sig);
			int p=i;
			while(true){
				int r=p%10;
				p=p/10+r*sig;
				if(p==i){
					break;
				}
				if(r != 0 && a <= p && p < i){
					k++;
				}
			}
		}

		cout << "Case #" << t << ": " << k << endl;
	}
}
