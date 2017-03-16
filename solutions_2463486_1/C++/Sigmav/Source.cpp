#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <queue>
#include <set>	
#include <cstring>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ii, int>	iii;
typedef vector<ii>		vii;
typedef vector<iii>		viii;
typedef vector<int>		vi;
typedef vector<char>	vc;
typedef vector<vc>		vvc;
typedef vector<string>	vs;
typedef unsigned long long	ull;
typedef vector<ull>		vul;
typedef vector<bool>	vb;
typedef vector<vi>		vvi;
typedef vector<vii>		vvii;
typedef vector<double>	vd;
#define INF 1000000000
#define PI 3.14159265

bool is_palindrome(ull number) {
	ull a = number;
	ull b = 0;
	while (a>0) {
		b *= 10;
		b += a%10;
		a /=10;
	}
	return number==b;
}

int main(int argc, char *argv[]){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	list<ull> precomp;

	for (ull n=1; n*n<=100000000000000; n++) {
		if (is_palindrome(n) && is_palindrome(n*n)) {
			precomp.push_back(n*n);
		}
	}


	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		ull A,B;
		cin >> A >> B;
		ull counter = 0;

		for (list<ull>::iterator it=precomp.begin(); it!=precomp.end(); it++) {
			if (*it >= A && *it <= B) counter++;
		}

		cout << "Case #" << t << ": " << counter << endl;

	}


	return EXIT_SUCCESS;
}