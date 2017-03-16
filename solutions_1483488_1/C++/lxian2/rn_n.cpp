#include<iostream>
#include<fstream>
using namespace std;

int leftn,rightn;
int mark[1000000];
int degree;
ifstream ins;
ofstream outs;

int getrn(int d){
	int k[20];
	int idx=0;
	int count=0;	
	int head;
	int tile;
	int newn;
	for(int i=10; i<=degree; i*=10){
		head = d/i;
		tile = d%i;
		newn = tile*(degree/i*10) + head;
		if(newn <= d || newn >rightn || newn < leftn || mark[newn-leftn])
		//if(newn <= d || newn >rightn || newn < leftn )
			continue;
		k[idx++]= newn-leftn;
		mark[newn-leftn]=1;
		//if(degree==1000)
		//cout << d << " " << newn << endl;
		count ++;
	}
	for(int i=0; i<idx; i++)
		mark[k[i]]=0;
	return count;
}

void getdegree(int n){
	while(n/=10){
		degree*=10;
	}
}


int main(){
	//ins.open("C-small-attempt1.in");
	ins.open("C-large.in");
	outs.open("out");
	int n;
	int count;
	int gap;
	ins >> n;
	for(int i=0; i<1000000; i++)
		mark[i]=0;
	for(int z=0; z<n; z++){
		 ins >> leftn >> rightn;	
		 gap = rightn - leftn;
		 degree=1;
		 getdegree(leftn);
		 count=0;
		 //for(int i=0; i<=gap; i++)
		 	//mark[i]=new int[gap];
		 for(int i=0; i<=gap; i++){
			//mark[i]=1;
			count += getrn(leftn+i);
		 }
		 outs << "Case #" << z+1 << ": " << count << endl;
	}
	return 0;
}
