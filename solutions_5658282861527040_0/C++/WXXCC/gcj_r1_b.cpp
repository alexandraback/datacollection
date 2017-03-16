#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include <iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

//typedef long long LL;
long long a, b, c;

long long getLow(const long long &x, int l)
{
    return x & (1ll << l) - 1;
}

long long getHigh(const long long &x, int l)
{
    return x & ~((1ll << l) - 1);
}

long long dfs(const long long &x, const long long &y, const int p) {
	if (x >= a || y >= b) return 0;
	//cout << x << ' ' << y << ' ' << p << endl;
	if (p < 0) return (x & y) < c;
	if ((x & y) >= c) return 0;
	if (((x & y) | (1ll << p + 1) - 1) < c) {
		long long t1, t2;
		if (getHigh(a, p + 1) == x) t1 = getLow(a, p + 1);
		else t1 = 1ll << p + 1;
		if (getHigh(b, p + 1) == y) t2 = getLow(b, p + 1);
		else t2 = 1ll << p + 1;
		return t1 * t2;
	}
	long long sum = 0;
	for (long long i = 0; i < 2; ++i) {
		for (long long j = 0; j < 2; ++j) {
			sum += dfs(x | i << p, y | j << p, p - 1);
		}
	}
	return sum;
}

int main() {
	freopen("Bs.in", "r", stdin);
	freopen("B.txt", "w", stdout);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {
		cin >> a >> b >> c;
		cout << "Case #" << cas << ": " << dfs(0, 0, 30) << endl;
	}
	return 0;
}

/*const double eps = 1e-12;
const double dinf = 99999999999.99;

int main()
{
      freopen("in.txt","r",stdin);
//    freopen("B1.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--){
        cout<<"Case #"<<cas<<": ";
        int a,b,k;
        cin>>a>>b>>k;
        set<int> hsh;
        long long ans = 0;
        for(int i = 0; i < a; i ++){
            for(int j = 0; j < b; j ++){
                int c = a&b;
                if(c < k && hsh.find(c) == hsh.end()){
                    ans ++;
                    hsh.insert(c);
                }
            }
        }
        cout<<ans<<endl;
        cas++;
    }
    return 0;
}
*/
