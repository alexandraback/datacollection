#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <functional>

using namespace std;
int main()
{
	freopen("A-small-attempt0.in" ,"r" ,stdin);
	freopen("test.out" ,"w" ,stdout);
	int T ,N;
	int s[512];
	cin >> T ;
	for (int t = 1 ;t <= T ;t++){
		cin >> N;
		double sum = 0;
		vector<double> v;
		for (int i = 0;i < N ;++i){
			cin >> s[i];
			v.push_back(s[i]);
			sum += s[i];
		}
		double tsum = sum;
		cout << "Case #" << t << ": " ; 
		sort(v.begin() ,v.end());
		double mmin = v[0];
		int k = 1;
		while (k < N && sum > 0.00000000001){
			if (k * (v[k] - mmin) <= sum){
				sum -= (v[k] - mmin) * k;
				mmin = v[k];
			}else{
				mmin += sum / k;
				sum = 0.0;
			}
			++k;
		}
		if (sum > 0.00000000001)
			mmin  += sum / k;
		for (int i = 0 ;i < N ;i++){
			if (s[i] > mmin){
				printf("%.5lf ",0.0);
			}else{
				printf("%.5lf " ,(mmin - s[i]) / tsum * 100.0);
			}
		}
		cout << endl;
	}
	return 0;
}
