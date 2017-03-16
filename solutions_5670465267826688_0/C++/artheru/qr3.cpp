#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const int mat[][4]={
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}
};

const int mat2[][4]={
	{1,2,3,4},
	{-2,1,-4,3},
	{-3,4,1,-2},
	{-4,-3,2,1}
};

int qm(int a, int b){
	return (a*b>0?1:-1)*mat[abs(a)-1][abs(b)-1];
}
int rqm(int a, int b){//a*?=b
	return (a*b>0?1:-1)*mat2[abs(a)-1][abs(b)-1];
}


int arr[10010];

bool run(int l, int x){
	if (l*x<3) return false;
	int whole=1, lw=1;
	for (int i=0; i<l; ++i)
		lw=qm(lw,arr[i]);
	for (int i=0; i<x; ++i)
		whole=qm(whole,lw);
	if (whole!=-1) return false;
	int findi=1;
	for (int i=0; i<l*x; ++i){
		findi=qm(findi,arr[i%l]);
		if (findi==2) {
			//Found I, now find k.
			int findk=1;
			for (int j=l*x-1; j>i+1; --j){
				findk=qm(arr[j%l],findk);
				if (findk==4)
					return true;
			}
			return false;
		}
	}
	return false;
}

int main(){
	ifstream inf("in.txt");
	ofstream of("out.txt");
	int qN;
	inf>>qN;

	const string y="YES";
	const string n="NO";
	for(int q=0; q<qN; ++q){
		int l,x; inf>>l>>x;
		for (int i=0; i<l; ++i){
			char tmp;
			inf>>tmp;
			arr[i]=tmp-'i'+2;
		};
		int whole=0;
		of<<"Case #"<<q+1<<": "<<(run(l,x)?y:n)<<endl;
	}
}