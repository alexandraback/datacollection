#include <iostream>

using namespace std;
int solve(int row, int column,int length){
	if(row!=1){
		return solve(row-1, column , length)+(row-1)*(column/length);
	}
	if(length == 1){
		return column;
	}else if(length == column){
		return column;
	}else if( length * 2 >= column){
		return length + 1;
	}else{
		return solve(row,column - length, length)+1;
	}
}
int main(){
	int cases;
	cin>>cases;
	for(int t =0;t<cases;t++){
		int row,column,length,answer;
		cin>>row>>column>>length;
		answer = solve(row, column,length);
		cout<<"Case #"<<t+1<<": "<<answer<<endl;
	}
	return 0;
}

