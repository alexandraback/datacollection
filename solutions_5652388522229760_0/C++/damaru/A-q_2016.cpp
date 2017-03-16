#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> //max...
#include <utility> //pair
#include <complex>
#include <climits> //int, ll...
#include <limits> //double...
#include <cmath> //abs, atan...

#include <cstring> //memset
#include <string>

using namespace std;

typedef long long ll;

typedef pair<int,int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

bool nums[10];

void simpl (long long int a){
	while (a != 0){
		if (!nums[a%10]) nums[a%10] = true;
		a/=10;
	}
}

int main (){
	long long int t, n, k;
	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> n;
		if (n == 0){
			cout << "Case #" << i+1 << ": " << "INSOMNIA" << endl;
			continue;
		}
		for (int j=0; j<10; j++) nums[j] = false;
		int j =1;
		while (true){
			simpl(n*j);
			for (k =0; k<10; k++){
				if (!nums[k]) break;
			}
			if (k == 10){
				cout << "Case #" << i+1 << ": " << n*j  << endl;
				break;
			}
			j++;
		}
	}
	return 0;
}
