#include<iostream>

using namespace std;

int R, C, W;

int main(){
	int T; cin>>T;
	for(int kases = 1; kases <= T; kases++){
		cin>>R>>C>>W;
		int res = (C/W)*R + (W-1) + (W>1&&W<C&&C%W>0?1:0); //first hit + rest of the size of the ship + chance of move the ship and fail
		cout<<"Case #"<<kases<<": "<<res<<endl;
	}
}
