#include <bits/stdc++.h>
#define Sort(x) sort(x.begin(),x.end())
typedef long long LL;
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i = 0; i < t; i++) {
	int a, b, k;
	cin>>a>>b>>k;
	int res = 0;
	for(int j = 0; j < a; j++) {
	    for(int l = 0; l < b; l++) {
		int tmp = j;
		tmp &= l;
		if(tmp < k) res++;
	    }
	}
	cout<<endl;
	cout<<"Case #"<<i+1<<": "<<res<<endl;
	
    }
    
}