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
		int X, Y;
		int uX = 0, uY = 0;
		input >> X >> Y;
		string p0 = "";
		string p1 = "";
		string result = "";
		if(X > 0){
			uX = X;
			p0 = "WE";
		}
		else if(X < 0){
			p0 = "EW";
			uX = 0 - X;
		}
		if(Y > 0){
			uY = Y;
			p1 = "SN";
		}
		else if(Y < 0){
			uY = 0 - Y;
			p1 = "NS";
		}
		for(int i = 0; i < uX; i ++){
			result = result + p0;
		}
		for(int i = 0; i < uY; i ++){
			result = result + p1;
		}
		int x = 0, y = 0;
		for(int j = 0; j < result.size(); j ++){
			if(result[j] == 'E'){
				x = x + j + 1;
			}
			else if(result[j] == 'W'){
				x = x - j - 1;
			}
			else if(result[j] == 'N'){
				y = y + j + 1;
			}
			else if(result[j] == 'S'){
				y = y - j - 1;
			}
		}
		cout << x << " " << y << endl;
		output << "Case #" << t + 1 << ": " << result << endl;
	}
	input.close();
	output.close();
	return 0;
}
