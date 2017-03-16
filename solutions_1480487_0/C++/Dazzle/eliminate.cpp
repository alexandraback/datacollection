#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int compare(const void * ele1,const void * ele2){
	return (*(int*)ele1)-(*(int*)ele2);
}
int main(){
	ifstream fin;
	fin.open("E:\\codejam\\input.txt");
	ofstream fout;
	fout.open("E:\\codejam\\output.txt");
	int T;
	const int SIZE=500;
	int judge_score[SIZE];
	int sorted_judge_score[SIZE];
	fin>>T;
	for(int t=1;t<=T;t++){
		int C;
		fin>>C;
		int sum=0;
		for(int i=0;i<C;i++){
			fin>>judge_score[i];
			sum+=judge_score[i];
			sorted_judge_score[i]=judge_score[i];
		}
		qsort(sorted_judge_score,C,sizeof(int),compare);
		int base=sorted_judge_score[0];
		double line=-1;
		for(int i=1;i<C;i++){
			if(sorted_judge_score[i]==sorted_judge_score[i-1]){
			}
			else{
				if(sorted_judge_score[i]*i-base<sum){
				}
				else{
					line=(double)(sum+base)/(double)i;
					break;
				}
			}
			base+=sorted_judge_score[i];
		}
		if(line<0){
			line=(double)(sum+base)/(double)C;
		}
		cout<<line<<endl;
		fout<<"Case #"<<t<<":";
		for(int i=0;i<C;i++){
			double p=((line-judge_score[i])*100)/(double)sum;
			if(p<0){
				p=0.0;
			}
			fout<<" "<<fixed<<setprecision(6)<<p;
		}
		fout<<endl;
	}
	return 0;
}