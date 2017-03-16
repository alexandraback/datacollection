#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std ;

int T, K,C, S ;
int main(){
	freopen("D-small-attempt0.in","r",stdin) ;
	freopen("D-small-attempt0.out","w",stdout) ;
	cin >> T ;
	for(int t=1; t<=T ;t++){
		cin >> K >> C >> S ;
		//assume K==S for small data
		cout << "Case #" << t << ":" ;
		long long kc = 1 ;
		for(int i=0 ;i<C-1 ;i++)
			kc = kc*K ;
		for(int k=0 ;k<K ;k++){
			long long r = k*kc+1 ;
			cout << " " << r ;
		}
		cout << endl ;
	}
	return 0 ;
}