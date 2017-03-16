#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;


int main(){

	ifstream in;
	//in.open("test.txt");
	in.open("B-small1.in");
	//in.open("B-large.in");
	
	ofstream out;
	out.open("out2.txt");
	
	int T;
	in>>T;
	
	for(int u=0;u<T;u++){
			
		string s="";	
		
		int xt;
		int yt;
		in>>xt>>yt;
		
		int x = 0;
		int y = 0;
		int i = 1;
		
		if(xt >= 0){
			while(x < xt){
				s += "E";
				x += i++;
				//cout<<x<<endl;
			}
			while(x != xt){
				s += "EW";
				x -= 1;
				i += 2;
				//cout<<x<<endl;
			}
		}
		else{
			while(x > xt){
				s += "W";
				x -= i++;
				//cout<<x<<endl;
			}
			while(x != xt){
				s += "WE";
				x += 1;
				i += 2;
				//cout<<x<<endl;
			}
		}
		
		if( yt >= 0){
			while(y != yt){
				y += 1;
				s += "SN";
				i += 2;
				//cout<<y<<endl;
			}
		}
		else{
			while(y != yt){
				y -= 1;
				s += "NS";
				i += 2;
				//cout<<y<<endl;
			}
		}
		
		cout<<i<<endl;
		out<<"Case #"<<(u+1)<<": "<<s<<endl;
		
    }
	in.close();
	out.close();
	
    return 0;
}