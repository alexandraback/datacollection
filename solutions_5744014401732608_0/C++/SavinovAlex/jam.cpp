#define  _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <complex>
#include <exception>
#include <list>
#include <stack>
#include <bitset>
#include <csetjmp>
#include <fstream>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <csignal>
#include <functional>
#include <map>
#include <cctype>
#include <cstdarg>
#include <iomanip>
#include <memory>
#include <streambuf>
#include <cerrno>
#include <cstddef>
#include <ios>
#include <new>
#include <string>
#include <cfloat>
#include <cstdio>
#include <iosfwd>
#include <numeric>
#include <typeinfo>
#include <ciso646>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <valarray>
#include <clocale>
#include <ctime>
#include <iterator>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>

typedef long long ll;
typedef unsigned int ui;
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >

#define veceach(v) for(uint i = 0;i < (v).size();i++)
#define veceach2(v,i) for(uint i = 0;i < (v).size();i++)
using namespace std;

vvi arr;


void main () {
	int T, n;
	ll m;

	FILE *f_in, *f_out;
	f_in = fopen("data.txt","r");	
	f_out = fopen("output.txt","w");	
	fscanf(f_in,"%d",&T);

	
	for (int t = 0; t < T; ++t) {
		fscanf(f_in, "%d %lld", &n, &m);
		
		arr.assign(n, vi(n, 0));


		bool found = true;
		for (ll mt = m, k = n - 2; mt > 0; mt >>= 1, k--) {
			bool f = mt & 1;

			if (k < 0) {
				found = false;
				break;
			}

			arr[0][k] = f ? 1 : 0;

			
				for (int i = k; i < n -1; i++) {
					for (int j = i + 1; j < n; j++) {
						arr[i][j] = 1;
					}
				}
			

		}
		

		fprintf(f_out, "Case #%d: ", t+1);

		if (found) {
			fprintf(f_out, "POSSIBLE\n");
			for (int i = 0; i < n ; i++) {
				for (int j = 0; j < n ; j++) {
					fprintf(f_out, "%d", arr[i][j]);
				}
				fprintf(f_out, "\n");
			}
		} else {
			fprintf(f_out, "IMPOSSIBLE\n");
		}
	}
	
}