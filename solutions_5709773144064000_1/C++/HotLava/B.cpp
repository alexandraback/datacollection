#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template<typename T>
ostream& operator<<(ostream& str, const vector<T>& v) {
	str << "[";
	for(auto n : v) {
		str << n << ", ";
	}
	str << "]";
	return str;
}

template<typename K, typename V>
ostream& operator<<(ostream& str, const unordered_map<K, V>& v) {
	str << "{";
	for(auto&& p : v) {
		str << p.first << " => " << p.second << ", ";
	}
	str << "}";
	return str;
}


int main() {
	int t;
	cin >> t;

	for (int T = 0; T < t; ++T)
	{
		double c, f, x;
		cin >> c >> f >> x;

		vector<double> factory_times;
		factory_times.push_back(0);
		//factory_times.push_back(c/2);
		int i=0;
		//double min 
		double last_time = numeric_limits<double>::max();
		while(true) {
			double times = factory_times.back() + x / ((i)*f + 2);
			factory_times.push_back( factory_times.back() + c/(2.0 + f*i) );

			if(times > last_time) {
				cout << fixed << setprecision(7) << "Case #" << T+1 << ": " << last_time << endl;
				break;
			}
			else
				last_time = times;


			i++;
		}
	}
}