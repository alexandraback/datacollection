#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std ;
int T ;


int main(){
	//freopen("C-large.in","r",stdin) ;
	freopen("C-large.out","w",stdout) ;
	cin >> T ;
	int N, J ;
	for(int t=1 ;t<=T ;t++){
		cin >> N >> J ;
		cout << "Case #" << t << ":" << endl ;
		//assume N>=4 ;
		int l =(N-4)/2 ;
		int m = 1<<l ;;
		for(int mj=0 ;mj<m && mj<J ;mj++){
			cout << "11" ;
			int tmj = mj ;
			for(int j=0 ;j<l ;j++){
				cout << tmj%2 << tmj%2 ;
				tmj = tmj>>1 ;
			}
			cout <<"11 3 4 5 6 7 8 9 10 11" << endl ;
		}
	}
}