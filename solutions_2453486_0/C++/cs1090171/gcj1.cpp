#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstring>
using namespace std;

string puzzle[4];
int rowx[4],colx[4],rowo[4],colo[4],diax[2],diao[2],t;

int main(){
	cin>>t;
	for(int k=1;k<=t;k++){
		cout<<"Case #"<<k<<": ";
		memset(rowx,0,sizeof(rowx));
		memset(colx,0,sizeof(colx));
		memset(diax,0,sizeof(diax));
		memset(diao,0,sizeof(diao));
		memset(rowo,0,sizeof(rowo));
		memset(colo,0,sizeof(colo));
		bool draw=true;
		for(int i=0;i<4;i++){
			cin>>puzzle[i];
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(puzzle[i][j]=='X'){
					rowx[i]++;
					colx[j]++;
					if(i==j)
						diax[0]++;
					if(i+j==3)
						diax[1]++;
				}
				if(puzzle[i][j]=='O'){
					if(i==j)
						diao[0]++;
					if(i+j==3)
						diao[1]++;
					rowo[i]++;
					colo[j]++;
				}
				if(puzzle[i][j]=='.'){
					draw=false;
				}
				if(puzzle[i][j]=='T'){
					rowx[i]++;
					colx[j]++;
					rowo[i]++;
					colo[j]++;
					if(i==j){
						diao[0]++;
						diax[0]++;
					}
					if(i+j==3){
						diao[1]++;
						diax[1]++;
					}
				}
			}
		}
		bool finish=false;
		for(int i=0;i<4 && !finish;i++){
			if(rowx[i]==4 || colx[i]==4 || (i<2 && diax[i]==4)){
				finish=true;
				cout<<"X won"<<endl;
			}
			if(rowo[i]==4 || colo[i]==4 || (i<2 && diao[i]==4)){
				finish=true;
				cout<<"O won"<<endl;
			}
		}
		if(!finish){
			if(draw)
				cout<<"Draw"<<endl;
			else
				cout<<"Game has not completed"<<endl;
		}
	}
	return 0;
}

		
