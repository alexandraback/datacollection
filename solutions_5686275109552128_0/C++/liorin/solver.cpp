#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std::vector;

long long int int_ceil_div(long long int n, long long int k) {
	if (n % k == 0) { 
		return (n/k);
	} else 
		return (n/k) +1;

}


int main() {
	long long int i,j,k, idx, t, d, ans, tmp, prev, max, opt, time, eating_time, num_splits;


	scanf("%lld\n", &t);
	for (i = 1; i <= t; i++) {
		vector<long long int> v;
		vector<long long int> count;
		vector<long long int> values;
		scanf("%lld\n", &d);
		for (j = 0; j < d; j++) {
			scanf("%lld", &tmp);
			v.push_back(tmp);
		}
		std::sort(v.begin(), v.end(), std::greater<long long int>());
		values.push_back(v[0]);
		count.push_back(1);
		prev = v[0];
		idx = 0;
		for (j = 1; j < d; j++ ) {
			if (v[j] != prev) {
				prev = v[j];
				values.push_back(prev);
				count.push_back(1);
				idx += 1;
			} else {
				count[idx] += 1;
			}
		}

		ans = values[0];
		for (j = 1; j < values[0] ; j++) {
			num_splits=0;
			//eating time = j
			for (idx = 0; idx < values.size(); idx++) {
				if (values[idx] > j)
					num_splits += count[idx]*(int_ceil_div(values[idx], j) - 1);
			}
			time = j + num_splits;
			if (time < ans) ans = time;
		}

		/*
		opt = (long long int) (ceil(sqrt((double) values[0]/count[0])));
		idx = values.size()-1;
		for (j = opt; j > 1; j--) { // j means we split highest p_i on j parts
			num_splits = 0;
			eating_time = int_ceil_div(values[0],j); //this is the maximum eating time of one guest, must split everything to this size
			while (eating_time > values[idx] && idx > 0) { //keeping idx between different iterations of j, this loop goes through values only once
				idx--;
			}
			for (k = idx; k > 0; k--) {
				num_splits += count[k] * (int_ceil_div(values[k], eating_time) -1);
			}
			num_splits += count[0]*(j-1);
			time = eating_time + num_splits;
			if (time < ans)
				ans = time;
		}*/
		printf("Case #%lld: %lld\n", i, ans);
	}

	return 0;

}
