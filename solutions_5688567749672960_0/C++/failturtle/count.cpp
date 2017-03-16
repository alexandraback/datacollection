#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define FO(i,a,b) for (int i = a; i < b; i++)
#define sz(v) (int)(v.size())

using namespace std;

long long pow (int k) {
	long long asdf = 1;
	while (k-->0) asdf*=10;
	return asdf;
}

long long re (long long num) {
	int stuff[20];
	FO (i,0,16) stuff[i] = 0;
	int i = 0;
	while (num > 0) {
		stuff[i] = num%10;
		num/=10;i++;
	}
	long long ret = 0;
	int copy = i;
	while (i >=0) {
		ret += stuff[i]*pow(copy-i-1);
		i--;
	}
	return ret;
}
int seen[1000005];
int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	queue<pair<long long,long long> > q;
	int t;
	scanf("%d\n",&t);
	FO(_,0,t) {
		long long n;
		scanf("%lld\n",&n);
		FO(i,0,1000000) seen[i] = 0;
		while (!q.empty())q.pop();
		q.push(make_pair(1ll, 1ll));
		while (!q.empty()) {
			long long a = q.front().first;
			long long b = q.front().second;
			q.pop();
			if (seen[a]) continue;
			seen[a] = 1;
			if (a == n){
				printf("Case #%d: %lld\n", 1+_, b);
				break;
			}
			a++; b++;
			q.push(make_pair(a,b));
			a--;
			q.push(make_pair(re(a),b));
		}
	}
}


