#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int T;
	cin >> T;
	for(int _=1;_<=T;_++){
		int mp[2555]={};
		printf("Case #%d:",_);
		int n;
		cin >> n;
		for(int i=0;i<n*2-1;i++){
			for(int j=0;j<n;j++){
				int m;
				cin >> m;
				mp[m]+=1;
			}
		}
		vector<int>ans;
		for(int i=0;i<2555;i++)
			if(mp[i]%2==1)
				cout << " " << i;
		cout << endl;
	}
	return 0;
}