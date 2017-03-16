#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>

using namespace std;
typedef long long ll;
const double eps = 1e-10;

ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}

set<ll> s;
vector<double> arr;

bool check(double a, double b){
	return fabs(a - b) < eps;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	for(int i=0; i<62; i++){
		ll numb = 1LL << i;
		s.insert(numb);
		if(i != 0){
			double d = 1.0 / numb;
			arr.push_back(d);
		}
	}
	int test_count;
	cin>>test_count;
	for(int test = 0; test < test_count; test++){
		ll a, b;
		char c;
		cin>>a>>c>>b;
		ll g = gcd(a, b);
		a /= g;
		b /= g;
		if(s.find(b) == s.end()){
			cout<<"Case #"<<test+1<<": impossible\n";
			continue;
		}
		double res = (double)a / b;

		cout<<"Case #"<<test+1<<": ";
		for(int i=0; i<arr.size(); i++){
			if(check(res, arr[i]) || (res > arr[i])){
				cout<<i+1;
				break;
			}
		}
		cout<<"\n";
	}

	return 0;
}