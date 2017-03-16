/*
 * =====================================================================================
 *
 *       Filename:  tic-tac.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 13 April 2013 10:08:01  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

typedef long long ll;
ll process(ll r, ll t){
	ll cnt = 0, cur=r+1;
	//cout << "process" << r << " " << t << endl;
	while(true){
		ll area = (cur * cur) - ((cur-1) * (cur-1)) ;
		//cout << "cur" << cur << " area" << area<< " t" << t << endl;
		if(t >= area){
			t -= area;
			cnt++;
		} else {
			break;
		}
		cur += 2;
	}
	return cnt;
}
int main(){
	ll T;
	cin >> T;
	for(int test=0;test<T;test++){
		ll r, t;
		cin >> r >> t;
		ll res = process(r,t);
		cout << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
