#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std ;
int T ;
char s[110] ;

int main(){
	freopen("B-large.in","r",stdin) ;
	freopen("B-large.out","w",stdout) ;
	cin >> T ;
	for(int t=0 ;t<T ;t++){
		cin >> s ;
		cout << "Case #" << t+1 << ": " ;
		int res = 0 ;
		int i= 1 ;
		for(;s[i] != '\0' ;i++){
			if(s[i-1] == '-'){
				if(s[i] == '+')
					res++ ;
			}else{
				if(s[i] == '-')
					res++ ;
			}
		}
		if(s[i-1] == '-')
			res++ ;
		cout << res << endl ;
	}
	return 0 ;
}