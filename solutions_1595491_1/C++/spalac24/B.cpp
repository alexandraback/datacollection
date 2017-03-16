#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <stack>
#include <cmath>
#define D(x) cout<<#x "is : "<<x<<" in line "<<__LINE__<<endl;

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	int t,s,p,sup;
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cout<<"Case #"<<cas<<": ";
		cin>>s>>sup>>p;
		int arr [s];
		for (int i = 0; i< s ;++i)
			cin>>arr[i];
		int mat [s][3];
		int res = 0;
		int totsup = 0;
		for (int i = 0; i < s; ++i) {
			mat[i][0] = arr[i]/3;
			mat[i][1] = arr[i]/3+(((arr[i]%3)>1)?1:0);
			mat[i][2] = arr[i]/3+!!(arr[i]%3);
		}
		for (int i = 0; i < s; ++i) {
			if (arr[i] < p){
				continue;
			}
			if (mat[i][2] >= p) {
				++res;
			}
			else {
				if (mat[i][2]== mat[i][0]) {
					if (mat[i][2]+1 >= p && totsup < sup) {
						++res;
						++totsup;
					}
				}
				else if (mat[i][2] == mat[i][1]){
					if (mat[i][2]+1 >= p && totsup < sup){
						++res;
						++totsup;
					}
				}
			}
		}
		cout<<res<<endl;
	}
}
