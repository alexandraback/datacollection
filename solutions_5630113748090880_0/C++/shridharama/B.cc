#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int T;
	cin>>T;
 
	for(int t=0;t<T;t++){
		int N;
		cin>>N;
		int x;
		unordered_map<int, int> hm;
		for(int i=0;i<2*N-1;i++){
			for(int j=0;j<N;j++){
				cin>>x;
				if(hm.find(x) == hm.end()){
					hm[x] = 1;
				}else{
					hm[x]++;
				}
			}
		}
		vector<int> result;
		
		for(auto kv : hm){
			//cout<<"\ndebug "<<kv.first<<" "<<kv.second<<endl;
			if(kv.second %2 != 0){
				result.push_back(kv.first);
				//cout<<kv.first<<" ";
			}
		}
		sort(result.begin(), result.end());
		cout<<"Case #"<<t+1<<": ";
		for(int i=0;i<result.size();i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}