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
int E, mxgain, R, N;
vector<int> v;
void cal(int avail, int index, int gain){
	if(avail > E) avail = E;
	//cout << "avail" << avail << "index " << index << "gain " << gain << endl;
	if(index == N){
		if(gain > mxgain) mxgain = gain;
		return;
	}
	for(int i=0;i<=avail;i++){
		int ngain = gain + i*v[index];
		//cout << "Choosing " << i << " for index " << index << "v" << i*v[index] << endl;
		cal(avail-i+R, index+1, ngain);
	}
}
void print(vector<int> &v){
	int N = v.size();
	for(int i=0;i<N;i++) cout << v[i] << ",";
	cout << endl;
}
int main(){
	int T;
	cin >> T;
	for(int test=0;test<T;test++){
		cin >> E >> R >> N;
		v.clear();
		mxgain = -1;
		for(int i=0;i<N;i++){
			int t; cin >> t; v.push_back(t);
		}
		//print(v);
		cal(E, 0, 0);
		int res = mxgain;
		cout << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
