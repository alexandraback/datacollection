#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>
#include <map>
#include <cstdio>
#include <queue>


using namespace std;

const int inf = 1000*1000*1000;


string solve(){
	int n;
	cin>>n;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	double t;
	for(int i=0; i<n; i++){
		cin>>t;
		a.push_back((int)(t*100000+0.000001));
	}
	for(int i=0; i<n; i++){
		cin>>t;
		b.push_back((int)(t*100000+0.000001));
		c.push_back((int)(t*100000+0.000001));
	}
	sort(a.begin(), a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i]>b[j]){
				b[j] = inf;
				cnt++;
				break;
			}
		}
	}
	string ans = to_string(cnt)+" ";
	cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=n-1; j>=0; j--){
			if(c[i]>a[j]){
				a[j] = inf;
				cnt++;
				break;
			}
		}
	}
	ans += to_string(n-cnt);
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