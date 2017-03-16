#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define infin 2147483647
#define pb push_back
#define rs resize
#define mp make_pair
#define sz(x) int((x).size())
#define vv(x) vector<vector<x> >
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

struct hikers{
	int start;
	double speed;
	hikers(int a, double b){
		start = a, speed = b;
	}
};

double cross(hikers a, hikers b){
	if(a.speed == b.speed) return -infin;
	return 1.0*(a.start-b.start)/(b.speed-a.speed);
}

int main(){
	int tests;
	cin>>tests;
	for(int t=1; t<=tests; t++){
		int n;
		cin>>n;
		vector<hikers> hiker;
		for(int i=0; i<n; i++){
			int pos, hik, speed;
			cin>>pos>>hik>>speed;
			hiker.pb(hikers(pos, 360.0/speed));
			if(hik == 2){
				hiker.pb(hikers(pos, 360.0/(speed+1)));
				break;
			}
		}
		if(sz(hiker) <= 1){
			cout<<0<<endl;
			return 0;
		}
		double tm;
		if((tm = cross(hiker[0], hiker[1]) > 0)) {	// den snabbste är först
			hiker[0].start = hiker[0].start + hiker[0].speed*(tm+(1>>12));
			hiker[1].start = hiker[1].start + hiker[1].speed*(tm+(1>>12));

		}
		if(hiker[0].speed > hiker[1].speed) hiker[0].start -= 360;
		else hiker[1].start -= 360;
		tm = cross(hiker[0], hiker[1]);
		tm = hiker[0].start + hiker[0].speed*tm;
		if(tm != -infin && tm <= 360) printf("Case #%d: %d\n", t, 1);
		else printf("Case #%d: %d\n", t, 0);
	}
}