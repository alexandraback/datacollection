#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <locale>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <fstream>
#include <string>
using namespace std;
#define ll long long
 
int main() {
	ll t;
	cin>>t;
 
	for(ll kase = 1; kase <= t; kase++) {
		ll p = 0, q = 0, i, j;
		string s;
		cin>>s;
 
		for(i=0; s[i] != '/'; i++)
			p = (p*10) + s[i] - '0';
 
		for(++i; s[i] != '\0'; i++)
			q = (q*10) + s[i] - '0';
 
		ll ans = 0;
		bool flag = false;
 
		while(1) {
			if(p >= q)
				break;
			if(q&1) {
				flag = true;
				break;
			}
			q /= 2;
			ans++;
		}
 
		if(flag)
			printf("Case #%lld: impossbile\n", kase);
		else
			printf("Case #%lld: %lld\n", kase, ans);
	}
 
	return 0;
}