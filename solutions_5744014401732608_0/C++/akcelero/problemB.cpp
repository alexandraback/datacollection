#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int b, m;

int tab[10];
int odw[10];



void print(int a){
	vector<int> result;
	while(a!=0){
		result.push_back(a%2);
		a/=2;
	}
	while(result.size()<b){
		result.push_back(0);
	}
	for(int i=result.size()-1;i>=0;i--){
		cout<<result[i];
	}
}

int main(){
	int t;
	cin >> t;
	for(int k = 0; k < t; k++){
		cin >> b >> m;
		for(int i=0;i<b;i++){
			odw[i] = 0;
			tab[i] = 0;
		}
		cout<<"Case #"<<(k+1)<<": ";
		if((1<<(b-2)) >= m){
			cout<<"POSSIBLE"<<endl;
			print(m);
			cout<<endl;
			for(int i=0;i<b-1;i++){
				for(int j=0;j<b;j++)
					cout<<(j-1>i);
				cout<<endl;
			}
		}else{
			cout<<"IMPOSSIBLE"<<endl;
		}

	}
	return 0;
}