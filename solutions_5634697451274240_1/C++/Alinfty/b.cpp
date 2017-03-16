#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin>>t;
	cin.get();
	int plus[]={'-','+'};
	for(int i=1;i<=t;i++){
		string str;
		getline(cin, str);
		cout<<"Case #"<<i<<": ";
		int flip=0;
		for(int j=str.length()-1;j>=0;j--){
			if(str[j]==plus[flip%2]){
				flip++;
			}
		}
		cout<<flip<<endl;
	}
	return 0;
}
