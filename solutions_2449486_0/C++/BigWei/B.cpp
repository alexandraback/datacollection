#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int board[100][100];
int N , M , D , T;
bool check(int r, int c){
	int bigger = 0;
	int biggerr = 0;
	for(int i=0;i< N ; i++){
			if(board[i][c] > board[r][c]){
			  bigger = 1;
			  break;
			}
	}
	for(int i=0;i<M;i++){
		if(board[r][i] > board[r][c] ){
			biggerr = 1;
			break;
		}
	}
//	cout<<r<<" "<<c<<" "<<bigger <<" "<<biggerr<<endl;
	return !(bigger + biggerr == 2);
}
int main(){
	cin >> T;
	for(int C = 1 ; C<=T ; C++){
		int fail = 0;
		cout<<"Case #"<<C<<": ";
		cin>> N >> M;

		for(int r=0;r<N ;r++){
			for(int c = 0; c < M ; c++){
				cin >> board[r][c];
			}	
		}
		
		for(int r=0;r<N ; r++){
			for(int c=0;c<M ; c++){
				if(check(r , c) == false){
					fail = 1;
					break;
				}
			}	
			if(fail)break;
		}
		if(fail) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}

}
