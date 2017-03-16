#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int T;
	cin>> T;
	for(int t=1;t<=T;++t){
		int N;
		cin >> N;
		vector<int> arr;
		arr.clear();
		for(int i=0;i<N;++i){
			int k;
			cin >> k;
			arr.push_back(k);
		}
		map<int, int> sum_mask;
		int MAX = (1<<N) - 1;
		int found = -1;
		pair<int,int> maskp;
		for(int mask=1;mask<=MAX;++mask){
			int sum = 0;
			for(int i=0;i<N;++i){
				if((mask&(1<<i)) > 0)	sum += arr[i];
			}
			map<int,int>::iterator it = sum_mask.find(sum);
			if(it != sum_mask.end()){
				maskp = make_pair<int,int>(it->second,mask);
				found = sum;
			} else {
				sum_mask[sum] = mask;
			}
		}
		cout<<"Case #"<<t<<":"<<endl;
		if(found > 0){
			vector<int> a,b;
			for(int i=0;i<N;++i){
				if((maskp.first&(1<<i))>0 && (maskp.second&(1<<i)) == 0){
					a.push_back(arr[i]);
				}
				else if((maskp.first&(1<<i)) == 0 && (maskp.second&(1<<i)) > 0){
					b.push_back(arr[i]);
				}
			}
			for(int i=0;i<a.size();++i){
				if(i > 0)	cout<<" ";
				cout<<a[i];
			}
			cout<<endl;
			for(int i=0;i<b.size();++i){
				if(i > 0)	cout<<" ";
				cout<<b[i];
			}
			cout<<endl;
		} else {
			cout<<"Impossible"<<endl;
		}
	}
}
