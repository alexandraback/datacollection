#include<iostream>
#include<fstream>
using namespace std;

int leftn,rightn;
int mark[10000][10000];
int degree;

int getrn(int d){
	int count=0;	
	int head;
	int tile;
	int newn;
	for(int i=10; i<=degree; i*=10){
		head = d/i;
		tile = d%i;
		newn = tile*(degree/i*10) + head;
		if(newn <= rightn && newn>=leftn && mark[newn-leftn][d-leftn]==0){
			mark[newn-leftn][d-leftn]=mark[d-leftn][newn-leftn]=1;
			count ++;
		}
	}
	return count;
}

void getdegree(int n){
	while(n/=10){
		degree*=10;
	}
}


int main(){
	ifstream ins;
	ofstream outs;
	ins.open("C-small-attempt1.in");
	outs.open("out");
	int n;
	int count;
	int gap;
	ins >> n;
	for(int z=0; z<n; z++){
		 ins >> leftn >> rightn;	
		 gap = rightn - leftn;
		 degree=1;
		 getdegree(leftn);
		 count=0;
		 //for(int i=0; i<=gap; i++)
		 	//mark[i]=new int[gap];
		 for(int i=0; i<= gap; i++)
		 	for(int j=0; j<=gap; j++)
				mark[i][j]=0;
		 for(int i=0; i<=gap; i++){
			mark[i][i]=1;
			count += getrn(leftn+i);
		 }
		 outs << "Case #" << z+1 << ": " << count << endl;
	}
	return 0;
}
