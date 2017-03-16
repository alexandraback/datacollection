/*
 * C.cpp
 *
 *  Created on: 2014/4/12
 *      Author: gamelife
 */



#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define STRLEN(x) (int)(strlen(x))
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }

const int maxn = 1000 ;
char line[maxn] ;
int cnt ;
int i,j,k,m,n,x,y,z;
int tt, tn;

void main2(){
	int R,C,M;

	cin >> R >> C >> M ;
//	cout << R << " " << C << " " << M << endl ;

	int A = R * C ;
	if(A-M-1 < 0){
		cout << "Impossible" << endl ;
		return;
	}else if(M==0){
		F0(i,R){
			F0(j,C){
				if(i==0 && j==0)
					cout << "c" ;
				else
					cout << "." ;
			}
			cout <<endl;
		}
		return ;
	}else if( A - M - 1 ==0){
		F0(i,R){
			F0(j,C){
				if(i==0 && j==0)
					cout << "c" ;
				else
					cout << "*" ;
			}
			cout <<endl;
		}
		return ;
	}else{
		int needspace ;
		if(R < 2 || C <2 )
			needspace = 1 ;
		else
			needspace = 3 ;

		if( A - M - 1  < needspace){
			cout << "Impossible" << endl ;
					return;
		}else{
			int show =  A - M - 1 ;
			char grid[R][C] ;
			F0(i,R){
				F0(j,C){
					if(i==0 && j==0){
						grid[i][j] = 'c' ;
//						cout << "c" ;
						if(R>1 && C>1){
							grid[1][1] = '.' ;
							show--;
						}
						if(R>1){
							grid[1][0] = '.' ;
							show--;
						}
						if(C>1){
							grid[0][1] = '.' ;
							show--;
						}
					}
					else if( (i==1&&j==0) || (i==0&&j==1) || (i==1&&j==1)){
//						cout << "." ;
						;
					}
					else{
						if(show > 0 ){
							grid[i][j] = '.' ;
							show--;
						}else{
							grid[i][j] = '*' ;
						}
//						cout << "*" ;
					}
				}
//				cout <<endl;
			}
			F0(i,R){
				F0(j,C){
					printf("%c" , grid[i][j]) ;
				}
				cout<<endl;
			}
			return ;
		}

	}

}

int main() {
//	    freopen("C-test.in", "r", stdin);

	    freopen("C-small-attempt0.in", "r", stdin);
	    freopen("C-small0.out", "w", stdout);

//	    freopen("C-large-practice.in", "r", stdin);
//	    freopen("C-large.out", "w", stdout);

	    scanf("%d\n" , &tn) ;

	    F1(tt,tn) {
	    	printf("Case #%d:\n", tt);
	    	main2();

	    }

	return 0;
}




