#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int height[2501];

int main(){
	int T,N;
	cin >> T;
	for(int k=0; k<T; k++){
		cin >> N;
		for(int i=0; i<2501; i++)
			height[i]=0;
		for(int i=0; i<(2*N-1)*N; i++){
			int h; 
			cin >> h;
			height[h]++;
		}

		vector<int> res;
		for(int i=0; i<2501; i++)
			if( height[i] % 2 == 1 )
				res.push_back(i);
		
		sort(res.begin(), res.end());

		cout << "Case #" << (k+1) << ":";
		
		for(int i=0; i<res.size(); i++)
			cout << " " << res[i];
		cout << "\n";
	}
}
