#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>


using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define INF (1<<29)


int main()
{
	int i;
	int numCase;
	int f;
	int m;
	int flavor;
	int customer;


	cin >> numCase;
	string s;
	for (int ii = 1; ii <= numCase; ii++) {

		cout << "Case #" << ii <<":";
 		int h[2501] = {0};


		int n;
		
		cin >> n;

		int fin[n] = {0};
		int counter = 0;
		for (i = 1; i<= 2*n-1; i++) {
			for (int j = 0; j < n; j++) {
				cin >> f;
				h[f]++;
			}
		}

		for (int l=1;l<=2500; l++) {
			if (h[l]%2 != 0) {
				cout << " " << l;
			}
		}

		cout << endl;

		
	}
	

}