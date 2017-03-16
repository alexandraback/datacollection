#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std ;
bool f[10] ;
int l = 10 ;
int T;

int main(){
	freopen("A-small-attempt0.in","r",stdin) ;
	freopen("A-small-attempt0.out","w",stdout) ;
	cin >> T ;
	for(int t=0 ;t<T ;t++){
		int N ;
		cin >> N ;
		l = 10 ;
		memset(f,false,sizeof(f)) ;
		cout << "Case #" << t+1 << ": " ;
		if(N==0){
			cout << "INSOMNIA" << endl ;
			continue ;
		}
		long long x = 0 ;
		while(l>0){
			x += N ;
			long long tmp = x ;
			while(tmp>0 && l>0){
				int tm =tmp%10 ;
				if(!f[tm]){
					f[tm] = true ;
					l-- ;
				}
				tmp = tmp/10 ;
			}
		}
		cout << x << endl ;
	}
	return 0 ;

}