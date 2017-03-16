#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int T, teste;
int n;
int a[1100];

int test(int target) {
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int x = (a[i] + target - 1) / target;
		ans += x-1;
	}

	return ans;
}

int main() {
	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++teste);
	
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		sort(a, a+n);

		int best = 10000;
		for (int i = 1; i <= 1000; i++) {
			best = min(best, i + test(i));
		}

		printf("%d\n", best);
	}
}