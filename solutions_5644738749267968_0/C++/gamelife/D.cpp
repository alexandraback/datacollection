/*
 * D.cpp
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
	cin >> n ;
//	cout << n << endl ;

	double mn[n] , mk[n] ;
	F0(i,n){
		cin >> mn[i] ;
	}
	sort(mn , mn+n);
//	F0(i,n){
//		cout << mn[i] << " " ;
//	}
//	cout << endl ;

	F0(i,n){
		cin >> mk[i] ;
	}
	sort(mk , mk+n);
//	F0(i,n){
//		cout << mk[i] << " " ;
//	}
//	cout << endl ;

	// count D-War lose
	int lose = 0 ;
	int lose2 = 0 ;
	int maxlose = 0 ;
	F0(i,n){
		lose = 0 ;
		for(j = i ; j<n ; j++){
			if(mn[j] < mk[i]){
//				cout << mn[j] << " < " <<  mk[i] << endl;
				lose++;
			}
			else
				break;
		}
		maxlose = max(maxlose , lose) ;
//		cout << "maxlose:" << maxlose << endl;
	}
//	cout << "maxlose:" << maxlose << endl;
	for( i = n-1 ; i>=0 ; i--){
		if(mn[n-1] < mk[i]){
//			cout << mn[n-1] << " < " <<  mk[i] << endl;
			lose2++;
		}
		else
			break;
	}
//	cout << "lose2:" << lose2 << endl;
	maxlose = max(maxlose , lose2);
//	cout << "maxlose:" << maxlose << endl;

	// count War lose
	int dwin = 0 ;
	for( i = 0 , j = 0 ; i<n && j<n ; i++ , j++){
		while( i<n && mn[i] <= mk[j] ){
			i++;
		}
		if( i< n){
//			cout << mn[i] << " > " <<  mk[j] << endl;
			dwin++;
		}
	}
//	cout << "dwin:" << dwin << endl;

	// count War lose
	int wlose = 0 ;
	for( i = 0 , j = 0 ; i<n && j<n ; i++ , j++){
		while( j<n && mn[i] >= mk[j] ){
			j++;
		}
		if( j< n){
//			cout << mn[i] << " < " <<  mk[j] << endl;
			wlose++;
		}
	}
	cout << n - maxlose << " " << n - wlose << endl;
}

int main() {
//	    freopen("D-test.in", "r", stdin);

	    freopen("D-small-attempt2.in", "r", stdin);
	    freopen("D-small2.out", "w", stdout);

//	    freopen("D-large-practice.in", "r", stdin);
//	    freopen("D-large.out", "w", stdout);

	    scanf("%d\n" , &tn) ;

	    F1(tt,tn) {
	    	printf("Case #%d: ", tt);
	    	main2();

	    }

	return 0;
}



