#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <limits>
#include <utility>
#include <functional>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//using namespace boost::multiprecision;

long long gcd(long long P, long long Q){
	if (Q == 0)
		return P;
	return gcd(Q, P%Q);
}

bool isPow2(long long P){
	if (P == 1)
		return true;

	if (P % 2 == 1)
		return false;

	return isPow2(P / 2);
}

void comp(int tc){
	long long P, Q;
	char c;
	cin >> P;
	cin >> c;
	cin >> Q;

	long long g = gcd(P, Q);
	P /= g;
	Q /= g;

	cout << "Case #" << tc << ": ";

	if (!isPow2(Q)){
		cout << "impossible" << endl;
	}
	else{
		int count = 0;
		while (P < Q){
			++count;
			Q /= 2;
		}
		cout << count << endl;
	}
}

int main(){
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc){
		comp(tc);
	}
}