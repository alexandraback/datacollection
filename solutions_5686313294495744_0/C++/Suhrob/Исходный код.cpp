#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<string>
#include<vector>
#include<iomanip>
#define ll long long
//#define for(i,b,n) for(int (i)=(b);(i)<(n);(i)++)
#define endl "\n"
using namespace std;
map<string,int>mymapl;
map<string,int>mymapr;

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ll t, answer = 0;
	//cout<<match("?2",2);
	cin>>t;
	for(ll j = 1; j <= t; j++){
		mymapl.clear();mymapr.clear();
		int n;
		cin>>n;
		int ans=0;
		vector<pair<string, string> >vec;
		for(int i=1;i<=n;i++){
			string a,b;
			cin>>a>>b;
			vec.push_back(make_pair(a,b));
			//if(mymapl[a]!=0 && mymapr[b]!=0)ans++;
			mymapl[a]++;
			mymapr[b]++;
		}
		for(int i=0;i<vec.size();i++){
			if(mymapl[vec[i].first]>1 && mymapr[vec[i].second]>1)ans++;
			mymapl[vec[i].first]--; mymapl[vec[i].second]--;
		}
		cout<<"Case #"<<j<<": "<<ans<<endl;
	}
	
	return  0;
}