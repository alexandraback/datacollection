
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const double pi = acos(-1.0);
const ULL INF = 4223372036854775808L;

LL t, r;

inline ULL getmin(ULL a, ULL b){
	return a < b ? a : b;
}

inline ULL getmax(ULL a, ULL b){
	return a > b ? a : b;
}

ULL getsum(ULL k){
	ULL B = 2*r + 2*k + 1;
	return B;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T, cases, num;
	ULL lft, rgt, mid, tmp, res;
	scanf("%d", &T);
	for(cases=1; cases<=T; ++cases){
		scanf("%lld %lld", &r, &t);
		lft = 0;
		rgt = getmin(INF, t);
		res = 0;
		num = 0;
		while(lft < rgt && num<3){
			mid = (lft + rgt)>>1;
			tmp = getsum(mid);
			if(t/(mid+1) < tmp){
				rgt = mid;
			}else{
				res = mid;
				lft = mid;
			}
			if(rgt-lft==1)num++;
		}
		printf("Case #%d: %lld\n", cases, res+1);
	}
 
	return 0;
}