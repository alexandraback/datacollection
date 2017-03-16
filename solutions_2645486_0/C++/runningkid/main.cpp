#include<iostream>
#include <vector>
#include <math.h>
using namespace std;

int e,r,n;
vector<int> v;

int search(int t, int en, int gain){
	if(t == n){
		return gain + v[t-1]*en;
	}
	int m = 0;
	for(int i = 0; i <= en; i++){
		int newen = min (e, en - i + r);
		int newgain = gain + v[t-1]*i;
		int res = search(t+1, newen, newgain);
		if(res > m) m = res;
	}
	return m;
}

int main(){
freopen("input.txt", "r", stdin);
freopen("out.txt","w",stdout);
int ncase;
cin >> ncase;
for(int icase = 1; icase <= ncase; icase++){
	cout << "Case #"<<icase<<": ";
	cin >>e>>r>>n;
	v.clear();
	for(int i = 0; i < n; i++){
		int tmp;
		cin >>tmp;
		v.push_back(tmp);
	}
	int ans = search(1,e,0);
	cout << ans << endl;
}
return 0;
}