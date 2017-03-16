//============================================================================
// Name        : CodeJam_2014_1C_C.cpp
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
	int N, M ,K ;
	cin >> N >> M >> K  ;
//	printf("%d %d %d \n" , N , M , K) ;

	int need ;

	if(K < 5 || N<=2 || M <=2){
		cout << K << endl ;
		return ;
	}else if(N==3 && M==3){
		cout << K-1 << endl;
		return ;
	}else if(K < 8){
		cout << K-1 << endl;
		return ;
	}else if(N==3){
		if(K>=17 && M==6)
			cout << K-4 << endl;
		else if(K>=14 && M==5)
			cout << K-3 << endl;
		else if(K>=11 && M==4)
			cout << K-2 << endl;
		else
			cout << K-2 << endl;
		return ;
	}else if(M==3){
		if(K>=17 && N==6)
					cout << K-4 << endl;
				else if(K>=14 && N==5)
					cout << K-3 << endl;
				else if(K>=11 && N==4)
					cout << K-2 << endl;
				else
					cout << K-2 << endl;
				return ;
	}else if(N==4 && M==4){
		if(K<9){
					cout << K-2 << endl;
					return;
				}
		cout << K-4 << endl;
		return;

	}else{


		if(K<9)
			cout << K-2 << endl;
		else if(K<16)
			cout << K-4 << endl;
		else
			cout << K-6 << endl;
		return;
	}


}

int main() {
//	    freopen("test.in", "r", stdin);

	    freopen("C-small-attempt2.in", "r", stdin);
	    freopen("C-small-2-1.out", "w", stdout);

//	    freopen("C-large-practice.in", "r", stdin);
//	    freopen("C-large.out", "w", stdout);

	    scanf("%d\n" , &tn) ;

	    F1(tt,tn) {
	    	printf("Case #%d: ", tt);
	    	main2();

	    }

	return 0;
}



