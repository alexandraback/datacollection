#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <string>
#include <set>
#include <queue>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <iterator>
#include <bitset>
#include <cctype>
#include <cmath>
#include <functional>
#include <iomanip>
#include <list>
#include <numeric>
#include <stack>
#include <utility>
#include <cassert>
#include <conio.h>
using namespace std;
#define ll long long


ll data[10][8];

struct attack {
	ll w;
	ll e;
	ll s;
	ll d;
	attack(ll a,ll b, ll c, ll d2) { w=a; e=b; s=c; d = d2; }
};

struct Sort {
	bool operator()(attack a, attack b) {
		return a.d<b.d;
	}
};


void main3() {
	ll t;
	scanf("%lld",&t);
	for(ll z=0; z<t; z++) {
		printf("Case #%lld: ",(z+1));
		ll n;
		scanf("%lld",&n);
		vector<attack> arr;
		map<ll,ll> h;
		for(ll i=0; i<n; i++) {
			for(ll j=0; j<8; j++) {
				scanf("%lld",&data[i][j]);
			}
		}
		for(ll i=0; i<n; i++) {
			for(ll j=0; j<data[i][1]; j++) {
				attack temp(data[i][2]+data[i][6]*j,data[i][3]+data[i][6]*j,data[i][4]+data[i][7]*j,data[i][0]*j+data[i][5]);
				arr.push_back(temp);
				
			}
		}
		attack temp(0,0,0,676062);
		arr.push_back(temp);
		sort(arr.begin(),arr.end(),Sort());
		ll ans = 0; ll cur = 0;
		for(ll i=0; i<=676061; i++) {
			if(arr[cur].d!=i) continue;
			map<ll,ll> ha;
			while(arr[cur].d==i) {
				//cout<<arr[cur].d<<" "<<arr[cur].s<<" "<<arr[cur].w<<" "<<arr[cur].e<<endl;


				bool found = false;
				for(ll j=arr[cur].w; j<arr[cur].e; j++) {
					if(h[j]<arr[cur].s) {
						ha[j] = arr[cur].s;
						found = true;
					}
				}
				if(found) ans++;
				cur++;
			}
			for(map<ll,ll>::iterator it = ha.begin(); it!=ha.end(); it++) {
				h[it->first] = it->second;
			}
		}
		printf("%lld\n",ans);
	}
}



int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	main3();




	//prllf("Program End\n");
	//_getch();
	return 0;
}