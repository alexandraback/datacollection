#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main(){
	int TT;
	cin>>TT;

	int a;
	int b;
	int ans;
	int k;

	for(int T=1;T<=TT;++T){
		
		cin>>a;
		cin>>b;
		cin>>k;
		int count=0;
		for(int i=0;i<a;++i){
			for(int j=0;j<b;++j){
				if((i&j)<k)
					++count;
			}
		}

		
		
		ans=count;
		
		cout<<"Case #"<<T<<": "<<ans<<"\n";



	}
	return 0;
}
