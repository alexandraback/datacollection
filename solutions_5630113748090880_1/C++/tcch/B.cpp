#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ifstream input;
	input.open("B-large.in");
	freopen("out","w",stdout);
	int T,N,next;

	input>>T;

	for(int t=0; t<T; t++){
		printf("Case #%d: ",t+1);
		input>>N;
		vector<int> num(2501,0);
		for(int i=0; i<2*N-1; i++){
			for(int j=0; j<N; j++){
				input>>next;
				num[next]++;
			}
		}
		for(int i=1; i<2501; i++){
			if(num[i]%2!=0) cout<<i<<' ';
		}
		cout<<endl;
	}
}