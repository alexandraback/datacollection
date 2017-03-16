#include<iostream>
using namespace std;
int t,x,y;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x>>y;
		cout<<"Case #"<<i<<": ";
		if(x>0){
			for(int j=0;j<x;j++){
				cout<<"WE";
			}
		}
		else{
			x=-x;
			for(int j=0;j<x;j++){
				cout<<"EW";
			}
		}
		if(y>0){
			for(int j=0;j<y;j++){
				cout<<"SN";
			}
		}
		else{
			y=-y;
			for(int j=0;j<y;j++){
				cout<<"NS";
			}
		
		}
		cout<<"\n";
	}
cout<<endl;
return 0;
}
