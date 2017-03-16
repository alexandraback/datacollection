#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
using namespace std;

int t;
long long int c, d, v;
vector<long long int> vv;
int main(){
	scanf("%d", &t);
	int ca = 0;
	while (t--){
		vv.clear();
		scanf("%lld%lld%lld", &c, &d, &v);
		for (int i = 0; i < d; i++){
			long long int a;
			scanf("%lld", &a);
			vv.push_back(a);
		}
		unsigned long long int mint = 0;
		unsigned long long int maxt = 0;
		long long int countt = 0;
		sort(vv.begin(), vv.end());
		int z = 0;
		while (maxt<v){
			while (z < vv.size() && vv[z] <= maxt + 1LL){
				maxt += vv[z] * (long long int)(c);
				if (maxt > v){
					break;
				}
				z++;
			}
			if (maxt >= v){
				break;
			}
			long long int i = maxt + 1LL;
			countt++;
			maxt += (long long int)(i)*(long long int)(c);
		}
		ca++;
		cout << "Case #" << ca << ": " << countt << endl;
	}
	return 0;
}