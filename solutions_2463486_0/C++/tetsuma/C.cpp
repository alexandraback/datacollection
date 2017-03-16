#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long ll;
#define INF (1<<29)

int main(){
	long long a, b;
	int t;
	cin >> t;
	for(int tc=1;tc<=t;tc++){
		cin >> a >> b;
		int ret=0;
		for(int i=a;i<=b;i++){
			if(i==1)ret++;
			else if(i==4)ret++;
			else if(i==9)ret++;
			else if(i==121)ret++;
			else if(i==484)ret++;
		}
		printf("Case #%d: %d\n",tc,ret);
	}
	return 0;
}

