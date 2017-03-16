#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>

#define rep(i,n) for(int i=0;i<n;i++)
#define VI vector<int>
#define pb(x) push_back(x)
#define ll long long
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(s) int(s.size())
using namespace std;

int main() {
	int t;
	cin >> t;
	cout << fixed << setprecision(7) ;
	rep(g,t){
		double c,f,x;
		cin >> c >> f >> x;
		double best = x/2;
		double time = 0;
		double rpm = 2;
		while(true){
//		for(int i=0;i<1000000;i++){
			time+=c/rpm;
			rpm+=f;
			if(time+x/rpm < best)
				best = time+x/rpm;
			else
				break;
		}
		cout << "Case #" << g+1 << ": ";
		cout << best << endl;
	}
	return 0;
}
