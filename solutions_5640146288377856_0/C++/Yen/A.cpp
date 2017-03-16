#include<iostream>
#include<cassert>

using namespace std;

int pin(int C, int W){
	assert(C>=W);
	if(C==W) return W;
	else{	//C>W
		return W+1;
	}
}

int smaller(int R, int C, int W, int score){
	int CC=C;
	if(R!=1){
		score+=(R-1)*(C/W);	//幹掉每一R的可能性最小需要的步數
		return smaller(1,C,W,score);
	}else{
		score+=C/W-1;	//10/3=3 , 3-1=2 <== 10-3-3=4  
		return score+pin(C-W*(C/W-1),W);
	}
}

int main(){
	int cases,R,C,W;
	cin>>cases;
	for(int c=1; c<=cases; c++){
		cin>>R>>C>>W;
		cout<<"Case #"<<c<<": "<<smaller(R,C,W,0)<<endl;
	}
	return 0;
}