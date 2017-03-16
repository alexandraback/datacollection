#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define MAX 200

int dp[200][200];
int memo[200][200];
int arr[200];
int isok( int id , int sur ) {
	if( id < 0 ) {
                if( sur == 0 ) return 1;
		return 0;	
	}
	int &ret = memo[id][sur]; 
        if( ret == -1 ) {
                ret  = 0;       
                int sum = arr[id];
                for( int i = 0; i <= 10; i++ ) for( int j =0; j<= 10; j++ ) for( int k = 0; k <= 10; k++ ) {
                        if( (i+j+k) == sum && (abs(j-i)<=2) && (abs(i-k)<=2) && ( abs(j-k)<=2 )  ) {
                                if( ( abs(j-i) == 2 || (abs(i-k)==2) || ( abs(j-k)==2 ) ) && (sur > 0)  ) {    
					ret = max( ret , isok(id-1 , sur-1 ));               
                                }
                                else if(  abs(j-i) != 2 && (abs(i-k)!=2) && abs(j-k) != 2 ) {
					 ret = max( ret , isok(id-1 , sur ));
                                }
                        }
                }
        }
        return ret;
}
int F( int id , int sur , int &P ) {
	if( id < 0 ) {
		return 0;
	}	
	int &ret = dp[id][sur]; 
	if( ret == -1 ) {
		ret  = 0;	
		int sum = arr[id];
		for( int i = 0; i <= 10; i++ ) for( int j =0; j<= 10; j++ ) for( int k = 0; k <= 10; k++ ) {
			if( (i+j+k) == sum && (abs(j-i)<=2) && (abs(i-k)<=2) && ( abs(j-k)<=2 )  ) {
				int add = 0;if( i >= P || j >= P || k >= P ) add = 1;
				if( ( abs(j-i) == 2 || (abs(i-k)==2) || ( abs(j-k)==2 ) ) && (sur > 0)  ) {	
					if( isok( id-1 , sur-1 ) ) {        
	                      		  	ret = max( ret , F(id-1 , sur-1 , P )+add );
					}		
				}
				else if(  abs(j-i) < 2 && (abs(i-k) < 2) && ( abs(j-k)<2 ) ) {
					if( isok(id-1 , sur) ) {
						ret = max( ret , F(id-1 , sur  ,  P )+add );
					}
				}
			}
		}
	}
	return ret;
}
int main() {
	int testcase;scanf("%d" , &testcase );
	for( int cs = 1; cs <= testcase; cs++ ) {
		int N , S , P;
		scanf("%d %d %d" , &N , &S , &P );	
		for( int i = 0; i < N; i++ ) scanf("%d",&arr[i]);
		CLEAR( dp , -1 );CLEAR( memo , -1 );
		int van = isok( N-1 , S );
		int ans = F( N-1 , S , P );
		cout << "Case #" << cs << ": " <<  ans << "\n";
	}
	return 0;
}
