#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
#define VAR(a,b) typeof(b) a=b
#define dout cout
using namespace std;
typedef long long LL;

LL u = 1000LL * 1000LL * 10LL;
vector<LL> fs;
void run(int Case)
{
	LL A,B;
	cin >> A >> B;
	size_t t=upper_bound(fs.begin(), fs.end(), B)-lower_bound(fs.begin(), fs.end(), A);
	cout << "Case #" << Case << ": " << t << endl;
}
LL rev(LL a){
	LL r=0;
	while(a){
		r*=10;
		r+=a%10;
		a/=10;
	}
	return r;
}

bool isFair(LL a){
	return a==rev(a);
}
int main() {
	for (LL i=1;i<10;i++){
		if (isFair(i*i)){
			fs.push_back(i*i);
		}
	}
	LL b=1;
	for (LL i=1;i<=u;i++){
		if (i>=b){
			b*=10;
		}
		LL r=rev(i);
		LL p=i*b+r;
		if (p>u){
			break;
		}
		if (isFair(p*p)){
			fs.push_back(p*p);
		}
		for (LL j=0;j<10;j++){
			p = (i*10+j)*b+r;
			if (p<=u&&isFair(p*p)){
				fs.push_back(p*p);
			}
		}
	}
	sort(fs.begin(),fs.end());
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		run(t);
	}
}
