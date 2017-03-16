#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
int si[30];
using namespace std;

int main(int argc, char *argv[]){
	string input="input.in";
	string output="output.out";	
	std::ifstream In(input.c_str()); //ifstream file	
	ofstream Out(output.c_str()); //output file
	int t;
	In>>t;
	for(int i=0;i<t;i++){
		int c,d,v;
		In>>c>>d>>v;
		for(int j=0;j<30;j++){
			si[j]=0;
		}
		int coins[d];
		for(int j=0;j<d;j++){
			In>>coins[j];
			vector<int> updatelist;
			updatelist.push_back(coins[j]-1);
			for(int k=0;k<30;k++){
				if(si[k]==1){
					updatelist.push_back(k+coins[j]);
				}
			}
			for(int k=0;k<updatelist.size();k++){
				si[updatelist[k]]=1;
			}
		}
		int required=0;
		for(int j=0;j<v;j++){
			if(si[j]!=1){
			required++;
			vector<int> updatelist;
			updatelist.push_back(j);
			for(int k=0;k<30;k++){
				if(si[k]==1){
					updatelist.push_back(k+j+1);
				}
			}
			for(int k=0;k<updatelist.size();k++){
				si[updatelist[k]]=1;
			}
				
				
				
				
			}
		}
		Out<<"Case #"<<i+1<<": "<<required<<"\n";
		
	}
	return 0;
 }




