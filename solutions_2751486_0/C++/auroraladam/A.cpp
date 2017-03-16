#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <cstring>
#include <cmath>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <numeric>
#include <queue>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

#define pb push_back
#define SZ(c) (c).size()
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))

int main(){
	ifstream input;
	ofstream output;
	input.open("input.in");
	output.open("output.out");
	if(!input.is_open() || !output.is_open()){
		exit(0);	
	}
	int tt, t;
	input >> tt;
	for(t = 0; t < tt; t ++)
	{
		int n;
		string line;
		input >> line;
		vector<char> name;
		int r = 0;
		input >> r;
		int i, j, k;
		int result = 0;
		for(i = 0; i < SZ(line); i ++){
			if(line[i] >= 'a' && line[i] <= 'z'){
				name.pb(line[i]);
			}
		}
		for(i = 0; i < SZ(name); i ++){
			for(j = i; j < SZ(name); j ++){
				int c = 0; 
				for(k = i; k < j + 1; k ++){
					if(name[k] != 'a' && name[k] != 'e' && name[k] != 'i' && name[k] != 'o' && name[k] != 'u'){
						c ++;
						if(c >= r){
							result ++;
							break;
						}
					}
					else{
						c = 0;
					}
				}
			}
		}
		//cout << "Case #" << t + 1 << ": " << result << endl;
		output << "Case #" << t + 1 << ": " << result << endl;
	}
	input.close();
	output.close();
	return 0;
}
