/**
*	
*	BY : Rajan Parmar
*/
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;
#pragma warning(disable:4996)
#define N 50
#define fi first
#define se second
#define mp make_pair
#define gc getchar_unlocked
#define mod 1000000007
#define LIM 1000000000000000000

typedef long long int ll;
typedef pair<ll, ll > pi;
typedef pair<ll, pi > pii;


int main() {


	freopen("B-small-attempt3 (1).in", "r", stdin);
	freopen("B-small-sol.out", "w", stdout);
	int t;
	int c = 1;
	int n;
	int B;
	int b[51][51];
	int i, j;
	ll M;
	
	cin >> t;
	while(t--){
		cin >> B >> M;
		memset(b , 0 , sizeof(b));
		for(i = 1 ; i < B ; i++){
		for(j = 0 ; j < B ; j++){
			if(j <= i)
				b[i][j] = 0;
			else
				b[i][j] = 1;
		}
	}
		cout << "Case #" << c++ <<": " ;
		if(M > (1 << ( B-2 ))){
			cout <<"IMPOSSIBLE\n";			
		}
		else{
			cout <<"POSSIBLE\n";
			if(M == (1 << ( B-2 ))){
				b[0][0] = 0;
				for(i = 1 ; i < B ; i++){
					b[0][i] = 1;
				}				
			}
			else{
				
				for(i = B-2 ; i > 0 ; i--){
					b[0][i] = M&1 ;
					M = M>>1;
				}
			}
			for(i = 1 ; i<B ; i++){
				if(b[0][i]==0){
					for(j = 0 ; j < B ; j++){
						b[i][j] = 0;
					}
				}
				else
					break;
			}
			for(i = 0 ; i < B ; i++){
				for(j =0 ; j<B ; j++){
					cout<<b[i][j];
				}
				cout<<"\n";
			}
		}
		
	}
			//cout << "Case #" << c++ <<": " << n * mul << "\n";
		
	
	return 0;
}
