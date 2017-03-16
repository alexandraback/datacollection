#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int n;  
string s[100] ; 
int list[100] ; 

int main(){
	
	int T; 
	scanf("%d",&T); 
	int CASE  = 0 ; 
	while( T-- ){
		scanf("%d",&n) ; 
		for(int i=0;i<n;++i){	
			list[i] = i ; 
			cin >> s[i] ; 
		}
		
		int cnt = 0; 
	//	printf("print : \n");
	//	for(int i=0;i<n;i++)
	//		cout << s[i] << endl ; 
	//	printf("-------\n");
		map < char , int > h ; 
		do{
			bool ok = 1;
			string tmp = s[list[0]]  ;  
			for(int i=1;i<n;++i){
				//int x = list[i-1] ; 
				int y = list[i] ; 
				//char a = s[x][s[x].length()-1] ;
				//char b = s[y][0] ;
				tmp += s[y] ; 
				
				//if( a != b ) ok = 0 ;
			}
			//printf("The string is = ");
			//cout << tmp << endl ; 
			/*
			if( ok ){ 	
				cnt++ ; 
				continue; 
			}
			*/
			ok = 1; 
			h.clear() ; 
			
			int len = (int)tmp.length() ; 
			char now = tmp[0] ; 
			h[now] = 1; 
			
			for(int i=1;i<len;++i){
				if( now != tmp[i] ){
					now = tmp[i] ; 
					if( h.find( now ) != h.end() ){
						ok  = 0 ;
						break ; 
					}
					h[now] = 1 ; 
				}
			}	  		
			if( ok ) cnt++ ; 
		} while( next_permutation( list , list + n ) ) ;  
		printf("Case #%d: %d\n",++CASE,cnt);
	}
 //1000000007
	return 0; 
} 
