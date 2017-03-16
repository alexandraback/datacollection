#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>   
#include<deque>
using namespace std;


int main(){
	ifstream cin;
	cin.open("B-small-attempt0 (1).in");
	ofstream cout;

	cout.open("out.txt");




	int T;
	cin>>T;
	for(int k=0;k<T;k++){
		int X,Y;

		cin>>X>>Y;

		string move1="";
		string move2="";

		if(X<0)
			move1="EW";
		if(X>0)
			move1="WE";

		if(Y<0) 
			move2="NS";
		if(Y>0)
			move2="SN";






		cout<<"Case #"<<k+1<<": ";
		for(int i=0;i<abs(X);i++)
			cout<<move1;

		for(int i=0;i<abs(Y);i++)
			cout<<move2;

		
		cout<<endl;





	
	
	

	}


	


	return 0;






}





