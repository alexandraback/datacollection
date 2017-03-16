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

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		int N, S, p;
		cin >> N;
		cin >> S;
		cin >> p;
		int k=0;
		int b0=p+2*max(0,p-1);
		int b1=p+2*max(0,p-2);
		for(int i=0;i<N;i++){
			int ti;
			cin >> ti;
			if(ti>=b0){
				k++;
			}
			else if (ti>=b1&&S>0)
			{
				k++;
				S--;
			}
		
		}
		cout << "Case #" << t << ": " << k << endl;
	}
}
