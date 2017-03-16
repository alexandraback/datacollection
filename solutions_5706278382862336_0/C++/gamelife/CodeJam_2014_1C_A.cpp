//============================================================================
// Name        : CodeJam_2014_1C_A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


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
#define all(x) x.begin() , x.end()
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

template <class T>
void printAll(vector<T> vecs){
	for(int i = 0 ; i< SZ(vecs) ; i++){
		cout << vecs[i] << " " ;
	}
	cout << endl;
}
template <class T>
void printAll( T vecs[] , int length){
	for(int i = 0 ; i< length ; i++){
		cout << vecs[i] << " " ;
	}
	cout << endl;
}

void main2(){
	ll P , Q ;

	scanf("%lld/%lld" , &P , &Q ) ;
//	cout << P << "/" << Q <<endl;

	int exp = 0 ;
	bool possible = false ;
	do{
		if((2<<exp)  == Q ){
			possible = true ;
			break;
		}
		exp++ ;
	}while( (2<<exp)  <= Q);

	if(!possible){
		cout << "impossible" << endl ;
		return ;
	}

	int result = 1 ;
	while(P < (Q/2)){
		Q /=2 ;
		result++;
	}

	cout << result << endl;


}

int main() {
//	    freopen("test.in", "r", stdin);

	    freopen("A-small-attempt1.in", "r", stdin);
	    freopen("A-small-1-1.out", "w", stdout);

//	    freopen("A-large-practice.in", "r", stdin);
//	    freopen("A-large.out", "w", stdout);

	    scanf("%d\n" , &tn) ;

	    F1(tt,tn) {
	    	printf("Case #%d: ", tt);
	    	main2();

	    }

	return 0;
}


