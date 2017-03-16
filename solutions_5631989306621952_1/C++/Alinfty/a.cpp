#include <iostream>
#include <string>

using namespace std;

int main(){
	int T;
	cin>>T;
	string input;
	string output;
	getline(cin, input);
	for(int i=1;i<=T;i++){
		getline(cin, input);
		output=input[0];
		for(int j=1;j<input.length();j++){
			for(int k=0;k<j;k++){
//				cout<<output[k]<<' '<<input[j]<<endl;
				if(output[k]>input[j]){
					output=output+input[j];
//					cout<<1<<output<<endl;
					break;
				}
				else if(output[k]<input[j]){
					output=input[j]+output;
//					cout<<2<<output<<endl;
					break;
				}
				else{
					if(k==j-1) output=input[j]+output;
				}
			}
		}
		cout<<"Case #"<<i<<": "<<output<<endl;
	}
	return 0;
}
