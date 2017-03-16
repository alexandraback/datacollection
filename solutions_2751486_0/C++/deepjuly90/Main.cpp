#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define pb push_back
#define FOREACH(x,y) for(typeof(y.begin()) x = y.begin() ; x != y.end() ; x++)

#define LL long long
#define NUM 1000002

LL MOD = 1000000007;

bool isVowel(char ch) {
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
	else return false;
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	cin >> tc;
	char ch;
	char arr[NUM];
	for(int t = 1 ; t <= tc ; t++) {
		scanf("%*c");
		scanf("%c",&ch);
		int len = 0;
		while(ch!= ' ') {
			arr[len++] = ch;
			scanf("%c",&ch);
		}
		int n;
		scanf("%d",&n);
		int c = 0;
		int imax = 0;
		LL ans = 0;
		for(int i = 0 ; i < len ; i++) {
			if(!isVowel(arr[i])) {
				c++;
			} else {
				c = 0;
			}
			if(c >= n) {
				ans = ans + (i - n - imax + 2) * (len - i);
				imax = i - n + 2;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return (0);
}