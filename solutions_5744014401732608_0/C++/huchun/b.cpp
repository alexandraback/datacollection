#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main(){
	ofstream myfile;
  	myfile.open ("outputb.txt");
  	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;++i){
		long long b, m;
		cin>>b>>m;
		myfile<<"Case #"<<i<<": ";
		if ((1<<(b-2)) < m) myfile<<"IMPOSSIBLE"<<endl;
		else{
			myfile<<"POSSIBLE"<<endl;
			vector<vector<bool>> matrix(b, vector<bool>(b, false));
			for (int i = 0; i < b; ++i){
				for (int j = i+1; j < b; ++j){
					matrix[i][j] = true;
				}
			}
			long long toRemove = (1<<(b-2))-m;
			int edge = b-2;
			while(toRemove > 0){
				if (toRemove&1 == 1) matrix[0][edge] = false;
				toRemove >>= 1;
				edge--;
			}
			for (int i = 0; i < b; ++i){
				for (int j = 0; j < b; ++j){
					myfile<<matrix[i][j]<<' ';
				}
				myfile<<endl;
			}
		}
	}
  	myfile.close();
  	return 0;
}
