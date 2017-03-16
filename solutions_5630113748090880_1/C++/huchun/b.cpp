#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

vector<int> func(int* matrix){
	vector<int> res;
	for (int i=1;i<=2500;++i){
		if (matrix[i]%2!=0) res.push_back(i);
	}
	return res;
}

int main(){
	ofstream myfile;
  	myfile.open ("outputb.txt");
  	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;++i){
		int n;
		cin>>n;
		int matrix[2501]={0};
		for (int i=0;i<n*2-1;++i){
			for (int j=0;j<n;++j){
				int tmp;
				cin>>tmp;
				matrix[tmp]++;
			}
		}
		vector<int> res=func(matrix);
		myfile<<"Case #"<<i<<": ";
		for (int i=0;i<res.size();++i){
			myfile<<res[i]<<' ';
		}
		myfile<<endl;
	}
  	myfile.close();
  	return 0;
}
