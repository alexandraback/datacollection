#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

//#define cin fin
//#define cout fout
//ifstream fin("D.in");
//ofstream fout("D.out");

int main()
{
	int nCase;
	cin>> nCase;
	for(int m = 0; m < nCase; ++ m){
		int n;
		cin >> n;
		vector<double> a(n, 0), b(n, 0);
		for(int i = 0; i < n; ++ i) cin >> a[i];
		for(int i = 0; i < n; ++ i) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int r1 = 0;
		for(int i = n-1, j = n-1; i >= 0 && j >= 0; -- i){
			if(a[i] > b[j]) ++ r1;
			else --j;
		}

		int r2 = 0;
		for(int i = n-1, j = n-1; i >= 0 && j >= 0; -- j){
			if(a[i] > b[j]){
				++r2; --i;
			}
		}

		cout << "Case #" << m+1 <<": "<<r2<<" "<<r1<<endl;
	}
	return 0;
}


