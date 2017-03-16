#include <iostream>
#include <string>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		int n;
		cin>>n;
		int stand=0;
		int add=0;
		for(int j=0; j<=n; j++){
			char c;
			cin>>c;
			int now = c - '0';
			if(stand<j){
				add = add + (j - stand);
				stand = j;
			}
			stand = stand + now;
		}
		cout<<"Case #"<<i<<": "<<add;
		if(i!=T)
			cout<<"\n";
	}
}