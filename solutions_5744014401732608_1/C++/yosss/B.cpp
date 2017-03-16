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


int T, B;
ll M;
int main(void){
	
	cin >> T;
	for(int num=1;num<=T;num++){
		cin >> B >> M;
		cout << "Case #" << num << ": ";
		
		if ((M-1)>>(B-2)) {cout << "IMPOSSIBLE" << endl; continue;}
		cout << "POSSIBLE" << endl;
		for(int i=0;i<B;i++){
			for(int j=0;j<B;j++){
				if (i>=j) {cout << 0; continue;}
				if (i>0) {cout << 1; continue;}
				if (j==B-1) {cout << 1; continue;}
				if ((M-1)&(1<<(B-2-j))) {cout << 1; continue;}
				cout << 0;
			}
			cout << endl;
		}
		
	}
	
	
	
	
	
	return 0;
}
