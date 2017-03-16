#include <iostream>
#include <string>

using namespace std;

int isValid(string name, int i, int j, int n);

int main(){
	int T;
	cin>>T;
	int index = 1;
	while(index <= T){
		string name;
		int n;
		cin>>name>>n;
		int count = 0;
		for(int i=0; i<name.length()-n+1; i++){
			for(int j=i+n-1; j<name.length(); j++){
				if(isValid(name, i, j, n)){
					count += name.length()-j;
					break;
				}
			}
		}
		cout<<"Case #"<<index<<": "<<count<<endl;
		index++;
	}
	return 0;
}

int isValid(string name, int i, int j, int n){
	int count = 0;
	for(int k=i; k<=j; k++){
		char c = name[k];
		if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
			count=0;
		}
		else {
			count++;
			if(count >= n){
				return 1;
			}
		}
	}
	return 0;
}
