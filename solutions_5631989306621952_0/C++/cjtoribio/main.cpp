#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long Long;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1; tc <= TC; ++tc){
		string S;
		cin >> S;
		set<int> SE;
		int l = S.size();
		while(l > 0){
			int c = 0;
			for(int i = 1; i < l; ++i){
				if(S[i] >= S[c]){
					c = i;
				}
			}
			SE.insert(c);
			l = c;
		}
		string R = "";
		for(int i = 0; i < S.size(); ++i){
			if(SE.count(i))
				R = string(1,S[i]) + R;
			else
				R += S[i];
		}
		cout << "Case #" << tc << ": " << R << endl;
	}
}


/*
 ######
 ######
 ######
 ######
*/
