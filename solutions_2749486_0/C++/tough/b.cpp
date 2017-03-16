#include <cmath>
#include <string>
#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	int x,y;
	int ca= 0;
	char ew,sn;
	while(t--){
		string s;
		ca ++ ;
		cin >> x >> y;
		for(int i = 0 ;i < abs(x) ;i++){
			if(x>0)
				s+="WE";
			else
				s+="EW";
		}
		for(int i = 0 ;i < abs(y);i++){
			if(y>0)
				s+="SN";
			else 
				s+="NS";
		}
		cout<<"Case #"<<ca<<": "<<s<<endl;
	}

}
