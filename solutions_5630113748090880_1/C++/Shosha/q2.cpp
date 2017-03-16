#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
typedef pair <int, int> ii;
typedef vector <int> vii;
#define TRvii(c,it) for (vii::iterator it =(c).begin(); it!=(c).end(); it++)
#define pi 3.14159265359

// cout << "Case #" << z << ": " <<    << endl;

int main () {
	FILE* ifile = freopen("B-large (1).in", "r", stdin);
	FILE* ofile = freopen ("ofile.txt", "w", stdout);
	int t;
	cin >> t;
	for (int z=1; z<=t; z++){
		int n;
		cin >> n;
		int hash[2501];
		for (int i=0; i<=2500; i++){
			hash[i] = 0;
		}
		for (int i =1; i<=2*n*n-n; i++){
			int t;
			cin >> t; 
			hash[t] = hash[t]+ 1;
		}
		vector <int> as;
		for (int i=0; i<=2500; i++){
			if (hash[i]%2==1){
				as.push_back(i);
			}
		}
		cout << "Case #" << z << ": ";
		for (int i=0; i<as.size(); i++){
			cout << as[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
