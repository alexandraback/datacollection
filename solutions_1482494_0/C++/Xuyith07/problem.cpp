#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;


int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("B-small-attempt0.in");
	out.open("out.txt");
	in>>CaseNum;
	int a[1001][3],N;
	for(int Case=0;Case<CaseNum;Case++){
		in>>N;
		for(int i=0;i<N;i++)
			{in>>a[i][0]>>a[i][1];
		a[i][2]=0;
		}
		int next=0,max=-1,next1;
		int score=0,step=0;
		while(score<N*2){
			next1=-1;
			next=-1;
			max=-1;
			for(int i=0;i<N;i++){
				if(score>=a[i][1]&&a[i][2]<2){
					next=i;
					break;
				}
				if(score>=a[i][0]&&a[i][2]==0&&max<a[i][1]){
				max=a[i][1];
				next1=i;
				}
			}
			if(next<0)next=next1;
			if(next<0)break;
			if(a[next][2]==0){
				if(score>=a[next][1])
					{score+=2;
					a[next][2]+=2;
				}
				else{
					score+=1;
					a[next][2]+=1;
				}
			}
			else if(a[next][2]==1){
				score+=1;
				a[next][2]+=1;
			}
			step++;
		}
		
		if(score>=N*2)

	out<<"Case #"<<Case+1<<": "<<step<<endl;
		else
	out<<"Case #"<<Case+1<<": "<<"Too Bad"<<endl;
	}
	return 0;
}
