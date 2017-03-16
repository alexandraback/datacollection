#include <iostream>

using namespace std;
long long f(long long k, long long c, long long l, long long r) {
	//cout << "AAA " << l << " " << r << endl;
	long long total = 0, cur = l;
	for(int i=0;i<c;i++) {
		total = (total * k + cur);
		cur = min(cur+1, r);
	}
	return total;
}
int main() {
	freopen("A.in","r",stdin);
	freopen("B.txt","w",stdout);
	int t, K, C, S;
	cin >> t;
	for(int ii=0;ii<t;ii++) {
		cin >> K >> C >> S;
		
		if(S < (K + C -1)/C) // impossible
		{
			cout << "Case #" << ii+1 << ": IMPOSSIBLE" << endl;
			continue;
		}
		cout << "Case #" << ii+1 << ": ";
		int m = (K + C -1)/C;
		for(int i=0;i<=K-1;i+=C) {
			cout << f(K, C, i, min(i+C-1, K-1)) + 1<< " ";
		}
		cout << endl;
	}
}