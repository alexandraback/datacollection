#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <limits.h>
#include <time.h>
#include <iterator>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

int main(){
	ifstream cin("in.txt");
	ofstream cout ("out.txt");
	int T;
	cin >> T;
	for(int t=1; t <= T; t++){
		string s;
		cin >> s;
		int k;
		cin >> k;
		int ans = 0;
		for(int i=0; i<s.length(); i++){
			
			for(int j=i; j<s.length(); j++){
				int kk = 0;
				int cnt = 0;
				for(int p=i; p<=j; p++){
					if(s[p] == 'a' || s[p] == 'i' || s[p] == 'e' || s[p] == 'o' || s[p] == 'u') cnt = max(cnt, kk), kk = 0; else kk++;
				}
				cnt = max(cnt, kk);
				if(cnt >= k)ans++;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
