#include<iostream>
#include<string>
#include<set>
#include<cstring>
using namespace std;

set<string> S;
int SZ;
int dp[ 5000 ][ 15 ];
string s;

int go( int pos, int cambio ){
   
   if( pos == SZ ) return 0;
   int &ans = dp[ pos ][ cambio  ];
   if( ans != -1 ) return ans;
   ans = 1<<30;
   for(int i = 1 ; i <= 10 && pos + i <= SZ; ++i){
     string cur = s.substr( pos , i );
	 if( S.count( cur) ) ans = min( ans , go( pos + i ,  ( pos + cambio ) % ( pos + i )   ) );
	 for(int j = cambio ; j < i ; ++j )
	   for( char c = 'a' ; c <= 'z' ; ++c ){
		   cur[j] = c;
		   if( S.count(cur) ) ans = min( ans , 1 + go( pos + i ,  ( pos  + j + 5 ) % ( pos + i )  ) );
		   for( int k = j + 5 ; k < i  ; ++k )
			   for( char d = 'a' ; d <= 'z' ; ++d ){
				   cur[k] = d;
		           if( S.count(cur) ) ans = min( ans , 2 +  go( pos + i ,  ( pos + k + 5 ) % ( pos + i )  ) );
				
			    }

	   }  
	
   }
   return ans;
}

int main(){
 int m = 0 ;
 while( cin >> s ){
   S.insert( s );
   if( s == "zymuznh" ) break;
 }
 int tc;
 cin >> tc;
 cerr << S.size() <<endl;
 for(int cas = 1 ; cas <= tc; ++cas ){
   cout <<"Case "<<"#"<<cas<<": ";
   cin >>s;
   SZ = s.size();
   int ans = 1 <<30;
   memset(dp,-1,sizeof dp);

   for(int i = 1 ; i <= 10 && i <= SZ; ++i){
     
	 string cur = s.substr( 0 , i );
	 if( S.count( cur) ) ans = min( ans , go( i , 0 ) );
	 for(int j = 0 ; j < i ; ++j )
	   for( char c = 'a' ; c <= 'z' ; ++c ){
		   cur[ j ]  = c;
		   if( S.count( cur ) ) ans = min( ans , 1 + go( i , ( j + 5 ) % i   ) );
		   for( int k = j + 5 ; k < i ; ++k )
			   for( char d = 'a' ; d <= 'z' ; ++d ){
				   cur[ k ] = d;
		           if( S.count(cur) ) ans = min( ans , 2 +  go( i , ( k + 5 ) % i   ) );
				
			    }

	   }  
	
   }
   cout << ans <<endl; 
 }
}
