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

struct sjp{
	int a,b,c;
	sjp(int x,int y,int z):a(x),b(y),c(z){}
};
vector <sjp> vec;
int main() {


	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-sol.out", "w", stdout);
	int t;
	int c = 1;
	int n;
	int B;
	int b[11][11];
	int i, j, k;
	int J, P, S, K;
	
	cin >> t;
	int cmb;
	while(t--){
		cin >> J >> P >> S >> K;
		cmb = 0;
		for(i = 1 ; i <= J ; i++){
			for(j = 1 ; j<=P ; j++){
				cmb = 0;
				for(k = 1 ; k<=S ; k++){
					cmb++;
					vec.push_back(sjp(i,j,k));
					if(cmb == K)
						break;
				}
			}
		}
		cout << "Case #" << c++ <<": ";
		cout<<vec.size()<<"\n";
		for(i = 0 ; i<vec.size() ; i++){
			cout << vec[i].a << " "<<vec[i].b <<" " <<vec[i].c <<"\n";
			
		}
		vec.clear();
	}
			//cout << "Case #" << c++ <<": " << n * mul << "\n";
		
	
	return 0;
}
