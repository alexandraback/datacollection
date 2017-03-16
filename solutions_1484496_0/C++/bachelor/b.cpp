#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const int MAXN = 1010;

ll ary[MAXN];


int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T, n;
	cin>>T;
	for(int tt = 1; tt <= T; ++tt){
		cin>>n;
		for(int i = 0; i < n; ++i){
			cin>>ary[i];
		}
		int flag = 1;
		cout<<"Case #"<<tt<<":"<<endl;
		vll v1, v2;
		for(int s = 1; s < (1<<n); ++s){
			v1.clear(); v2.clear();
			ll sum = 0, ts = 0;
			for(int i = 0; i < n; ++i){
				if((1<<i)&s){
					sum += ary[i];
				}else {
					v1.push_back(ary[i]);
				}
			}
			for(int i = 1; i < (1 << v1.size()); ++i){
				ts = 0;
				v2.clear();
				for(int j = 0; j < v1.size(); ++j){
					if((1<<j) & i){
						ts += v1[j];
						v2.push_back(v1[j]);
					}
				}
				if(ts == sum)break;
			}
			if(ts == sum){
				v1.clear();
				for(int i = 0; i < n; ++i){
					if((1<<i)&s){
						v1.push_back(ary[i]);
					}
				}
				flag = 0; break;
			}				
		}
		if(flag)cout<<"Impossible"<<endl;
		else {
			for(int i = 0; i < v1.size(); ++i)
				cout<<v1[i]<<' ';
			cout<<endl;
			for(int i = 0; i < v2.size(); ++i)
				cout<<v2[i]<<' ';
			cout<<endl;
		}	
	}
	return 0;
}	
