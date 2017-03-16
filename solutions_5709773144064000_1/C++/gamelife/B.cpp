/*
 * B.cpp
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
	double C, F ,X ;

	cin >> C >> F >> X ;
//	cout << C << " " << F << " " << X << endl ;

	double speed = 2.0 ;
	double t = C / speed ;
	double ans = -1 ;
	double newt = 0 , oldt = 0 ;
//	printf("%.6f\n" , t );
	do{
		newt = t + X/(speed+F) ;
		oldt = t + (X-C)/speed ;
//		cout << " newt:" << newt << " , oldt:" << oldt  <<endl;
		if(newt < oldt){
			speed = speed + F ;
			t += C/speed ;
		}else{
			ans = oldt ;
		}
	}while(newt < oldt) ;

	printf("%.7f\n" , ans );

}

int main() {
//	    freopen("test.in", "r", stdin);

//	    freopen("B-small-attempt0.in", "r", stdin);
//	    freopen("B-small.out", "w", stdout);

	    freopen("B-large.in", "r", stdin);
	    freopen("B-large.out", "w", stdout);

	    scanf("%d\n" , &tn) ;

	    F1(tt,tn) {
	    	printf("Case #%d: ", tt);
	    	main2();

	    }

	return 0;
}



