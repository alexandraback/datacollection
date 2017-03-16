#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	for(int p=0; p<t; p++){
		ll a, n, res=0;
		cin>>a>>n;
		vector<ll> arr(n);
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		sort(arr.begin(), arr.end());
		bool ch=false;
		int i;
		for(i=0; i<n; i++){
			int count = 0;
			while(arr[i] >= a){
				a+=(a-1);
				res++;
				count++;
				if(count >= (n-i)){
					ch=true;
					res-=count;
					break;
				}
			}
			if(ch)
				break;
			a+=arr[i];
		}
		res+=(n-i);
		if(res >= n)
			res=n;
		cout<<"Case #"<<p+1<<": "<<res<<"\n";
	}
	return 0;
}