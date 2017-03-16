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
class attack {
	public:
		int di, wi, ei, si;
		attack(int d, int w, int e, int s){
			di = d;
			wi = w;
			ei = e;
			si = s;
		}
		bool operator<(const attack& r) const { return di < r.di; }

};
bool compare(attack &a, attack &b){
	return a.di < b.di;
}

int wall[2001];
bool issuccess(int wi, int ei, int si){
	bool success = false;
	wi+= 1000;
	ei+=1000;
	for(int i=wi;i<ei;i++){
		if(wall[i] < si){
			success = true;
		}
	}
	return success;
}
void apply(int wi, int ei, int si){
	wi+= 1000;
	ei+=1000;
	for(int i=wi;i<ei;i++){
		if(wall[i] < si){
			wall[i] = si;
		}
	}

}
int process(){
	int N;
	cin >> N;
	vector<attack> r;
	for(int i=0;i<N;i++){
		int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
		cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;
		int d=di,w=wi,e=ei,s=si;
		attack a(d,w,e,s);
		r.push_back(a);
		for(int c=0;c<ni-1;c++){
			d+=delta_di;
			w+=delta_pi;
			e+=delta_pi;
			s+=delta_si;
			attack a(d,w,e,s);
			r.push_back(a);
		}
	}
	sort(r.begin(), r.end());
	N=r.size();
	int res = 0;
	memset(wall, 0, sizeof(wall));
	vector<attack> pending;
	for(int i=0;i<N;i++){
		attack t = r[i];
		int sz = pending.size();
		if(sz > 0){
			attack last = pending[sz-1];
			if(t.di > last.di){
				for(int j=0;j<sz;j++) {
					attack c = pending[j];
					//cerr << "applying" << c.wi << "," << c.ei << "," << c.si << endl;
					apply(c.wi, c.ei, c.si);
				}
				pending.clear();
			}
		}
		cerr << t.di << "," << t.wi << "," << t.ei << "," << t.si << endl;
		if(issuccess(t.wi, t.ei, t.si)){
		res++;
		//cerr <<"sucess" << endl;
		}
		if(i < N -1) pending.push_back(t);
		else {
			//cerr << "applying" << t.wi << "," << t.ei << "," << t.si << endl;
			apply(t.wi, t.ei, t.si);
		}
	}

	return res;
}
int main(){
	int T;
	cin >> T;
	for(int test=0;test<T;test++){
		int res = process();
		cout << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
