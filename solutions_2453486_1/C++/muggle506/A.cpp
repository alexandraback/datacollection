#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int x[4][4];
int o[4][4];
bool hasEmpty;
char c;
int T;
ofstream output;
bool won(int x[][4]){
	for(int i=0;i<4;i++){
		if((x[i][0]+x[i][1]+x[i][2]+x[i][3])==4) return true;
		if((x[0][i]+x[1][i]+x[2][i]+x[3][i])==4) return true;
	}
	if((x[0][0]+x[1][1]+x[2][2]+x[3][3])==4) return true;	
	if((x[3][0]+x[2][1]+x[1][2]+x[0][3])==4) return true;
	return false;
}
int main(){
	FILE * input=fopen("A-large.in","r");
	output.open("Aoutput.txt");
	fscanf(input,"%i",&T);
	fscanf(input,"%c",&c);
	int ca=0;
	while(ca++<T){
	output<<"Case #"<<ca<<": ";
	memset(x,0,sizeof(x));
	memset(o,0,sizeof(o));
	hasEmpty=false;
	//input
	for(int i=0;i<4;i++){
	 for(int j=0;j<4;j++){
		fscanf(input,"%c",&c);
//		output<<i<<j<<c;
		switch (c){
			case 'X':
				x[j][i]=1;
				break;
			case 'O':
				o[j][i]=1;
				break;
			case 'T':
				x[j][i]=1;
				o[j][i]=1;
				break;
			case '.':
				hasEmpty=true;
				break;
			default: cout<<"extra input:"<<i<<j<<c<<endl;

		}	
	 }
		fscanf(input,"%c",&c);
		//output<<i<<c;
	}
		fscanf(input,"%c",&c);
		//output<<"caseend "<<c;


	//check
    if(won(x)) output<<"X won"<<endl;
	else if(won(o)) output<<"O won"<<endl;	
	else if(hasEmpty) output<<"Game has not completed"<<endl;
			else output<<"Draw"<<endl;
	}
	fclose(input);
	output.close();

}
