#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define ll long long

//YOLO
//code by loyolman

using namespace std;

bool cmp(const ll &l, const ll &r) {
	return l<r;
}

int main() {
	ll T;
	cin>>T;
	for (int j=1;j<=T;j++) {
		vector<ll> mince;
		ll C,D,V;
		cin>>C>>D>>V;
		mince.push_back(0);mince.push_back(V+1);
		for (int u=0;u<D;u++) {
			ll o;
			cin>>o;
			mince.push_back(o);
		}
		sort(mince.begin(), mince.end(), cmp);
		
		ll i=0;
		while (mince[i]!=V+1) {
			ll sum=0;
			for (int k=0;k<=i;k++) sum+=mince[k]*C;
			if (sum<mince[i+1]-1) {
				mince.push_back(sum+1);
				sort(mince.begin(), mince.end(), cmp);
			}
			i++;
		}
		
		cout<<"Case #"<<j<<": "<<mince.size()-2-D<<endl;
	}
	return 0;
}
