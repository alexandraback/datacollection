#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
int x,y;
char res[501];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		//todo
		cin>>x>>y;
		res[0]=0;
		if(x<0){
			for(int j=0;j<abs(x);j++) strcat(res,"EW");
		}
		if(x>0){
			for(int j=0;j<abs(x);j++) strcat(res,"WE");
		}
		if(y<0){
			for(int j=0;j<abs(y);j++) strcat(res,"NS");
		}
		if(y>0){
			for(int j=0;j<abs(y);j++) strcat(res,"SN");
		}
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
	return 0;
}