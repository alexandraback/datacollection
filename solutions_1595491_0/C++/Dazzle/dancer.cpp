#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int T;
	ifstream fin;
	ofstream fout;
	fin.open("E:\\codejam\\input.txt");
	fout.open("E:\\codejam\\output.txt");
	fin>>T;
	for(int t=1;t<=T;t++){
		int N;
		int S;
		int p;
		fin>>N;
		fin>>S;
		fin>>p;
		int swing_lower=(p-1)*3-1;
		int swing_upper=(p-1)*3;
		int possible_qualify=0;
		int score;
		//no swing for p=1;
		if(p==1)
			S=0;
		for(int i=0;i<N;i++){
			fin>>score;
			if(score>swing_upper)
				possible_qualify++;
			else if(score>=swing_lower && score<=swing_upper){
				if(S>0){
					S--;
					possible_qualify++;
				}
			}
		}
		fout<<"Case #"<<t<<": "<<possible_qualify<<endl;
	}
	fout.close();

}