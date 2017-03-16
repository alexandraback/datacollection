#include<vector>
#include<cmath>
#include<complex>
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<float.h>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define debug printf("--%d--\n",__LINE__)
#define ll long long int

int T, J, P, S, K;
int main(void){
	cin >> T;
	for(int num=1;num<=T;num++){
		cin >> J >> P >> S >> K;
		cout << "Case #" << num << ": ";
		
		if (S<=K){
			cout << J*P*S << endl;
			for(int i=1;i<=J;i++)for(int j=1;j<=P;j++)for(int k=1;k<=S;k++) cout << i << " " << j << " " << k << endl;
		}else{
			cout << J*P*K << endl;
			for(int i=1;i<=J;i++)for(int j=1;j<=P;j++)for(int k=1;k<=S;k++){
				if ((i+j+k)%S<K){
					cout << i << " " << j << " " << k << endl;
				}
			}
		}
	}
	
	
	
	
	return 0;
}
