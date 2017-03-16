#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;



long long stl(string s){
	long long num = atoll(s.c_str());
	return num;
}

string lts(long long x){
	stringstream ss;
	ss << x;
	string s = ss.str();
	return s;
}

long long inverseNum(long long x){
	string xs = lts(x);
	reverse(xs.begin(), xs.end());
	return stl(xs);
}

long long countMin(long long n){
	if(n <10LL) return n;
	
	string sn = lts(n);
	string sninv = sn;
	reverse(sninv.begin(), sninv.end());
	
	int numOfDigit = sn.length();
	int len = ceil(numOfDigit / 2.0);
	long long firstnum = stl(sninv.substr(numOfDigit-len,len));
	long long lastnum = stl(sn.substr(numOfDigit-len,len));
	
	if (lastnum ==0){
		return 1LL + countMin(n-1LL);
	}
	if (firstnum == 1LL && lastnum == 1LL){
		return 2LL+ countMin(n-2LL);
	}
	if (lastnum > 1LL){
		long long diff = lastnum-1LL;
		return diff + countMin(n-diff);
	}
	return 1LL + countMin(inverseNum(n));
}

int main(){
	int T;
	
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		long long N;
		scanf("%lld", &N);
		printf("Case #%d: %lld\n",t,countMin(N));
	}
	return 0;
}