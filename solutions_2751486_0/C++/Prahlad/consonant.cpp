/*
 * =====================================================================================
 *
 *       Filename:  tic-tac.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 13 April 2013 10:08:01  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

typedef long long ll;
bool iscons(char ch){
	bool v =  ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
	if(v) return false;
	else return true;
}
int main(){
	int T;
	cin >> T;
	for(int test=0;test<T;test++){
		string s;
		int n;
		cin >> s >> n;
		int N = s.size(), res =0;
		for(int i=0;i<N;i++)
			for(int j=i+1;j<=N;j++){
				int mx = -1, ln=0;
				for(int k=i;k<j;k++){
					if(iscons(s[k])) ln++;
					else {
						if(mx<ln) mx = ln;
						ln=0;
					}
				}
				if(mx <ln) mx=ln;
				if(mx >=n) res++;
			}
		cout << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
