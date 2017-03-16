#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <set>
#include <complex>
#include <iomanip>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define show(x) cerr << "# " << #x << endl
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;
typedef pair<int, int> pii;
typedef complex<double> point;

const int MAX_N = 1000 + 10;

int a[MAX_N];
int b[MAX_N];
int mark[MAX_N];

int main(){
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; test++){
		memset(mark, 0, sizeof mark);
		int n;
		scanf("%d", &n);
		FOR(i, n)
			scanf("%d %d", &a[i], &b[i]);
		int star = 0, ans = 0;
		while(true){
			bool find = false;
			FOR(i, n)
				if(mark[i] < 2 && star >= b[i]){
					ans++;
					star += 2 - mark[i];
					mark[i] = 2;
					find = true;
				}
			if(find)
				continue;
			int best = -1;
			FOR(i, n)
				if(mark[i] == 0 && star >= a[i])
					if(best == -1 || b[best] < b[i])
						best = i;
			if(best == -1)
				break;
			else{
				ans++;
				mark[best]++;
				star++;
			}
		}
		bool bad = false;
		FOR(i, n)
			if(mark[i] < 2)
				bad = true;
		if(bad)
			printf("Case #%d: Too Bad\n", test);
		else
			printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
