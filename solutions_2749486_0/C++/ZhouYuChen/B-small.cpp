#include<iostream>
using namespace std;


int main(){
	int T,ts=1,x,y;
	for(cin>>T;ts<=T;++ts){
		cin >> x >> y;
		cout << "Case #"<<ts<<": ";
		for(;x>0;x--)cout << "WE";
		for(;x<0;x++)cout << "EW";
		for(;y>0;y--)cout << "SN";
		for(;y<0;y++)cout << "NS";
		cout << endl;
	}
}
