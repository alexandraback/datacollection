#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
	int i,j,k,l;
	int N,T;
	int *board;
	int R, C, W;
	cin>>T;
	for(l = 0 ; l < T ; l++){
		cin>>R>>C>>W;
		cout<<"Case #"<<l+1<<": ";
		N = (C - W)/W;
		if(C % W == 0)
			N = N+W;
		else
			N = N + W +1;
		if(R > 1)
			N += C/W * (R - 1);
		cout<<N<<"\n";
	}
	return 0;
}