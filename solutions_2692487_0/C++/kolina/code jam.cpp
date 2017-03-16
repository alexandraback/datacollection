#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>

#define long long
#define mp make_pair

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	cin >>test;
	for (int t=1; t<=test; ++t){
		int a,n;
		cin >>a >>n;
		vector<int> s(n);
		for (int i=0; i<n; ++i)
			cin >>s[i];
		if (a==1){
			cout <<"Case #" <<t <<": " <<n <<endl;
			continue;
		}
		sort(s.begin(),s.end());
		int need=n;
		for (int i=1; i<=n; ++i){
			int cur_need=0;
			long cur=a;
			for (int j=0; j<i; ++j)
				if (cur>s[j])
					cur+=s[j];
				else{
					while (cur<=s[j]){
						++cur_need;
						cur=2*cur-1;
					}
					cur+=s[j];
				}
			cur_need+=n-i;
			need=min(need,cur_need);
		}
		cout <<"Case #" <<t <<": " <<need <<endl;
	}
	return 0;
}