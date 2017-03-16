#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

vector<int> func(vector<int>& matrix){
	sort(matrix.begin(),matrix.end());
	vector<int> res;
	int n=matrix.size();
	for (int i=0,j=1;i<n;++j){
		if (j==n||matrix[j]!=matrix[i]){
			if ((j-i)%2!=0){
				res.push_back(matrix[i]);
			}
			i=j;
		}
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
		vector<int> matrix;
		for (int i=0;i<n*2-1;++i){
			for (int j=0;j<n;++j){
				int tmp;
				cin>>tmp;
				matrix.push_back(tmp);
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
