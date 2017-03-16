#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
#define INF (1LL<<62)
typedef long long int64;

vector <int64> fairpalindromes;

bool ispalindrome(int64 n){
     stringstream ss;  ss << n ; 
     string sn = ss.str();
     string rsn = sn;  reverse(rsn.begin(),rsn.end());
     return sn == rsn;
}

void precompute(){
	 for(int64 i=1; i<=10000000; ++i){
	 	  if(ispalindrome(i) && ispalindrome(i*i)){
	 	  	  fairpalindromes.push_back(i*i);
	 	  }
	 }
	 fairpalindromes.push_back(INF);
}

int tcase, caseNo;
int64 a, b;

int main(){
	 precompute();
     for(scanf("%d",&tcase), caseNo = 1; tcase; tcase -=1){
          cin >> a >> b ;
          cout << "Case #" << caseNo++ << ": "<< lower_bound(fairpalindromes.begin(), fairpalindromes.end(),b+1) - lower_bound(fairpalindromes.begin(), fairpalindromes.end(), a) << endl;
     }
	 return 0;
}