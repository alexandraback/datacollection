#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define LONGMAX 0x7FFFFFFFFFFFFFFF

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		int C,D,V;
		cin>>C>>D>>V;
		vector<int> den;
		for(int j=0; j<D; j++){
			int h;
			cin>>h;
			den.push_back(h);
		}
		int count=0;
		int bound = 0;
		if(den[0]!=1){
			den.insert(den.begin(),1);
			D++;
			count++;
		}
		int j=0;
		while(bound<V){
			if((j<D)&&(bound>=den[j]-1)){
				bound = bound + C*den[j];
				j++;
			}
			else{
				bound = bound + C*(bound+1);
				count++;
			}
		}
		cout<<"Case #"<<i<<": "<<count;
		if(i!=T)
			cout<<"\n";
	}
}