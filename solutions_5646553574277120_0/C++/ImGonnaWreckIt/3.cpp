#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

void fillDenomination(int *val, int V, int *coins, int D, int cur, int curVal){
	int i,j;
	if(curVal > V){
		return;
	}
	val[curVal] = 1;
	if(cur == D)
		return;

	fillDenomination(val, V, coins, D, cur+1, curVal);
	fillDenomination(val, V, coins, D, cur+1, curVal + coins[cur]);
}

int main(){
	int i,j,k,l;
	int N,T,C,D,V;
	int *val, *coins;
	cin>>T;
	for(l = 0 ; l < T ; l++){
		cin>>C>>D>>V;
		val = new int[V+1];
		val[0] = 0;
		for(i = 0 ; i <= V ; i++)
			val[i] = 0;
		coins = new int[V+1];
		for(i = 0 ; i < D ; i++)
			cin>>coins[i];
		int count = 0;
	
		fillDenomination(val, V, coins, D, 0, 0);
		
		for(i = 1 ; i <= V ; i++){
			if(val[i] == 1)
				continue;
			count++;
			for(j = 0 ; j <= V - i ; j++)
				val[i+j] = 1;
		}
		cout<<"Case #"<<l+1<<": "<<count<<"\n";
	}	
}