#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int t; cin>>t;
	for(int k = 1; k <= t; k++){
		int r,c,w;
		cin >> r >> c >> w;
		int v = 0;
		int rem = c;
		while(rem >= w+w){
			rem-=w;
			v+=1;
		}
		if(rem > w) v+=1+w;
		else v+=w;
		cout << "Case #" << k << ": " << min(c, v) << endl;
	}
	
	return 0;
}
