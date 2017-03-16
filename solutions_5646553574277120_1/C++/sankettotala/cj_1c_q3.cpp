#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int iiii=1; iiii<=t; iiii++){
		int c, d, v;
		cin>>c>>d>>v;
		int arr[d];
		for(int i=0; i<d; i++){
			cin>>arr[i];
		}
		sort(arr, arr+d);
		int cp = 0, max = 0, ans = 0;
		while(max < v){
			if(arr[cp] <= max+1){
				max += c*(arr[cp]);
				cp++;
			}
			else{
				max += c*(max+1);
				ans++;
			}
		}
		cout<<"Case #"<<iiii<<": "<<ans<<endl;
	}
}
