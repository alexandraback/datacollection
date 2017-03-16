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
bool flag[31];
int main(){
	scanf("%d", &t);
	int ca = 0;
	while (t--){
		memset(flag, false, sizeof(flag));
		scanf("%lld%lld%lld", &c, &d, &v);
		for (int i = 0; i < d; i++){
			long long int a;
			scanf("%lld", &a);
			flag[a] = true;
			//vv.push_back(a);
		}
		long long int mint = 0;
		long long int maxt = 0;
		int countt = 0;
		for (int i = 1; i <= v; i++){
			if (flag[i]){
				maxt += i;
				continue;
			}
			if (i <= maxt){
				continue;
			}
			countt++;
			maxt += i;
		}
		ca++;
		cout << "Case #" << ca << ": " << countt << endl;
	}
	return 0;
}