#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
using namespace std;

typedef long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}
int main() {
	int t; cin >> t;
	set<char> v;
	v.insert('a');
	v.insert('e');
	v.insert('o');
	v.insert('i');
	v.insert('u');
	for(int x = 1; x <= t; ++x){
		string name; 
		int n;
		cin >> name >> n;
		int i = 0, j;
		LL res = 0;
		LL L = name.length();
		int lasti = -1;
		while (i + n <= L) {
			j = 0;
			int ile = 0;
			while ((i + j < L) && 
						(v.find(name[i + j]) == v.end())) {
					j++;
					ile++;
			}
			if (ile >= n) {
	//			cout << ile << " " << i <<  " " << L << " " << res << endl;
				for(int k = 0; k <= ile - n; k++) {
//					cout << i + k - lasti  << " " << L + 1 - (i + n + k) << endl;
					res += (i + k - lasti ) * (L + 1 - (i + n + k));
					lasti = i + k;
				}
		//		cout << res << endl;
			}
			i += max(j, 1);
		}
		cout << "Case #" << x << ": " << res << endl;//result 
	}
	return 0;
}
