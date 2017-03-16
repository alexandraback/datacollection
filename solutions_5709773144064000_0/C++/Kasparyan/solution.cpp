#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>
#include <map>
#include <cstdio>

using namespace std;

const int inf = 1000*1000*1000;


double solve(){
	double c,f,x;
	const double eps = 0.000000001;
	cin>>c>>f>>x;
	double speed = 2.0;
	double ans = 100000000.0;
	double colTime=0.0;
	for(int i=0; i<x; i++){
		ans = min(ans,x/speed+colTime);
		colTime+=c/speed;
		speed+=f;
	}
	return ans;
}


int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		cout.setf(ios::fixed);
		cout.precision(7);
		cout<<"Case #"<<i<<": "<<solve()<<endl;
	}
    return 0;
}