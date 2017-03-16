/*Santiago Zubieta*/
#include <iostream>
#include <numeric>
#include <fstream>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <iterator>
#include <algorithm>  

using namespace std;

vector <int> fairnsq;
vector <int> orig;

bool checkpalin(string s){
	for(int i = 0; i < s.length(); ++i){
		if(s[i] != s[s.length()-i-1]){
			return false;
		}
	}
	return true;
}

int main(){
	int nCases;
	cin >> nCases;
	for(int j = 1; j*j < 1000; ++j){
		fairnsq.push_back(j*j);
		orig.push_back(j);
	}
	int count, a, b;
	for(int i = 1; i <= nCases; ++i){
		count = 0; 
		cin >> a >> b;
		for(int j = 0; j < orig.size(); ++j){
			if(fairnsq[j] < a) continue;
			if(fairnsq[j] > b) break;
			stringstream ss1, ss2;
			ss1 << fairnsq[j];
			string fns = ss1.str();
			ss2 << orig[j];
			string ori = ss2.str();
			if(checkpalin(fns) && checkpalin(ori)){
				count++;
			}
		}
		printf("Case #%d: %d\n", i, count);
	}
}