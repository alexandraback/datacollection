#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int k=1; k<=t; k++) {
		int n;
		float sum=0;
		cin >> n;
		vector<float> v;
		for (int i=0; i<n; i++) {
			float s;
			cin >> s;
			v.push_back(s);
			sum += s;
		}
		float esum = ((float)sum)*2;
		float e = esum/((float)n);
		printf("Case #%d: ",k);
		for (int i=0; i<n; i++) {
			float res = (e-v[i])/sum;
			res = res*100;
			cout << res << " ";
		}
		cout << endl;
	}
	return 0;
}
