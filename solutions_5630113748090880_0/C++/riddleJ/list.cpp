#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,k,var;
	int arr[2501];

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		vector<int> list;

		for(int j=0;j<=2500;j++){
			arr[j]=0;
		}

		for(int j=0;j<(2*k-1);j++){
			for(int l=0;l<k;l++){
				cin>> var;
				arr[var]++;
			}
		}

		/*for(int j=0;j<=2500;j++){
			cout << arr[j];
		}*/


		for(int j=1;j<=2500;j++){
			if(arr[j]%2!=0)
				list.push_back(j);
		}

		sort(list.begin(),list.end());

		cout<<"Case #"<<(i+1)<<": ";

		for(int j=0;j<list.size();j++){
			cout<< list.at(j)<<" ";
		}
		cout<<endl;
	}
}