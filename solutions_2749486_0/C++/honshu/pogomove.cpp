#include <iostream>
#include <string>

using namespace std;


int main(){
	int T;
	cin>>T;
	int index = 0;
	for(index=0;index<T;index++){
		int X,Y;
		cin>>X>>Y;
		string east = "WE";
		string west = "EW";
		string north = "SN";
		string south = "NS";		
		string move = "";
		string vert = north;
		string hori = east;
		if(X<0){
			hori = west;		
			X = -1*X;
		}
		if(Y<0){
			vert = south;
			Y = -1*Y;			
		}
		for(int i=0; i<X; i++){
			move += hori;		
		}			
		for(int i=0; i<Y; i++){
			move += vert;		
		}
		cout<<"Case #"<<index+1<<": "<<move<<endl;
	}
	return 0;
}
