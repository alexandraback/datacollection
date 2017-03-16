#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>

using namespace std;

#define MAXVAL 500

string path [MAXVAL][MAXVAL];

void getin(int T){
	ifstream file;
	file.open("what.txt");
	int x, y, power;
	for(int i=0;i<MAXVAL;++i){
		for(int j=0;j<MAXVAL;++j){
			file >> x >> y >> power;
			if(power!=-1){
				if(power==0)
					path[x][y] = "";
				else
					file >> path[x][y];
			}
		}
	}
			
	for(int i=0;i<T;++i){
		
		int x, y;
		cin >> x >> y;
		
		
		string ans = path[x+MAXVAL/2][y+MAXVAL/2];
		
		cout << "Case #" << i+1 <<": " <<  ans << endl;
	}
}

int main(){
	int T;
	cin >> T;
	
	getin(T);
}