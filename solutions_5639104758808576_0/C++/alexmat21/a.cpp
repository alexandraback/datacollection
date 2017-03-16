// Created by alex_mat21. And it works!

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <string> 
#include <iomanip>
#include <cmath>
#include <utility>
 
#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define vi vector<int>
#define fs first
#define sd second
#define pii pair<int,int>

using namespace std;

int main (){
int t111;
cin >> t111;

for (int i111=0 ; i111<t111; i111++){
	int n;
	string s;
	cin >> n >> s;
	int t=0;
	int k=0;
	FOR(i,n+1){
		//cout << i <<' ' << t <<' ' << k << ' ' << s[i] << endl;
		if (t<i){
			k++;
			t++;
			}
		t+=s[i]-48;
		}
	cout << "Case #"<< i111 +1 << ": " << k << endl;
	}
return 0;
}
