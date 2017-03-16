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
#include<valarray>
//#include<bits/stdc++.h>
using namespace std;
int t;
vector<pair<double, double> > v;
int main(){
	scanf("%d", &t);
	int ca = 0;
	while (t--){
		ca++;
		int n;
		scanf("%d", &n);
		v.clear();
		for (int i = 0; i < n; i++){
			double a, b, c;
			cin >> a >> b >> c;
			for (int j = 0; j < b; j++, c += 1.0){
				v.push_back(make_pair(a, 360.0 / c));
			}
		}
		int ans = 1;
		if (v[0].second == v[1].second){
			ans = 0;
		}
		else{
			if (v[1].second > v[0].second){
				swap(v[0], v[1]);
			}
			if (v[0].first < v[1].first){
				ans = 0;
			}
			else{
				double dist = v[0].first - v[1].first;
				dist = 360.0 - dist;
				double s = v[0].second - v[1].second;
				double sec = dist / s;
				double k = v[1].first + v[1].second*sec;
			//	cout << v[0].first << " ";
			//	printf("%.6f\n", v[0].second);
			//	cout << v[1].first << " ";
			//	printf("%.6f\n", v[1].second);
			//	cout << k << endl;
				if (k > 360.0){
					ans = 0;
				}
				else{
					ans = 1;
				}
			}
		}
		cout << "Case #" << ca << ": ";
		printf("%d\n", ans);
	}
	return 0;
}