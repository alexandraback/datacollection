#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
	
int main(){
	int TT;
	cin>>TT;
	int ans=0;


	int n;
	int a[3000];
	for(int T=1;T<=TT;++T){
		for(int i=0;i<3000;++i){
			a[i]=0;
		}
		cin>>n;
		for(int i=0;i<2*n-1;++i){
			for(int j=0;j<n;++j){
				int tmp;
				cin>>tmp;
				++a[tmp];
			}
		}
		cout<<"Case #"<<T<<":";
		int count=0;
		for(int i=0;i<3000;++i){
			if(a[i]%2!=0){
				++count;
				cout<<" "<<i;
			}
		}
		if(count!=n)
			cout<<"!!!"<<endl;
		cout<<endl;


	}
	return 0;
}
