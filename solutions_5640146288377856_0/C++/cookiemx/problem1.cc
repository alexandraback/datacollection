#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solve(int column,int length){
	if(length == 1 || length == column){
		return column;
	}else if( length * 2 >= column){
		return length + 1;
	}else{
		return solve(column - length, length)+1;
	}
}
int main(){
	int cases;
	cin>>cases;
	for(int t =0;t<cases;t++){
		int row,column,length,answer;
		cin>>row>>column>>length;
		answer = solve(column,length);
		answer = answer * row;
		cout<<"Case #"<<t+1<<": "<<answer<<endl;
	}
	return 0;
}

