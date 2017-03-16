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
	unsigned long long int a, b;
	cin >> nCases;
	unsigned long long int lim = 1e14;
	vector < unsigned long long int> fairnsq;
	vector < unsigned long long int> orig;
	for(unsigned long long i = 0; i*i < lim; ++i){
		stringstream ss1,ss2;
		ss1 << i*i;
		ss2 << i;
		string fns = ss1.str();
		string ori = ss2.str();
		if(checkpalin(fns) && checkpalin(ori)){
			fairnsq.push_back(i*i);
			orig.push_back(i);
		}
	}
	int count;
	for(int i = 1; i <= nCases; ++i){
		count = 0; 
		scanf("%llu %llu", &a, &b);
		for(int j = 0; j < orig.size(); ++j){
			if(fairnsq[j] < a) continue;
			if(fairnsq[j] > b) break;
			count++;
		}
		printf("Case #%d: %d\n", i, count);
	}

}