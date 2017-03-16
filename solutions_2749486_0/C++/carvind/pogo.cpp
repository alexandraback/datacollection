#include <iostream>
#include <string>

using namespace std;


int main(){
	int T;
	cin>>T;
	int index = 1;
	while(index <= T){
		int x,y;
		cin>>x>>y;
		string east = "WE";
		string west = "EW";
		string north = "SN";
		string south = "NS";		
		string move = "";
		string vert = north;
		string hori = east;
		if(x<0){
			hori = west;		
			x = -1*x;
		}
		if(y<0){
			vert = south;
			y = -1*y;			
		}
		for(int i=0; i<x; i++){
			move += hori;		
		}			
		for(int i=0; i<y; i++){
			move += vert;		
		}
		cout<<"Case #"<<index<<": "<<move<<endl;
		index++;
	}
	return 0;
}
