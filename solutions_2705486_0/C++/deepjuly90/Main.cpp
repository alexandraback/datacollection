#include <iostream>
#include <cstring>
#include <fstream>
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
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define pb push_back
#define FOREACH(x,y) for(typeof(y.begin()) x = y.begin() ; x != y.end() ; x++)

#define LL long long

LL MOD = 1000000007;

vector <string> dict(521200);
int dp[102];

int findMinEditDist(string a, string b, int index, int n) {
	int dist = 0;
	for(int i = index ; i < n ; i++) {
		if(a[i] != b[i-index]) dist++;
	}
	return dist;
}

int find(int index, int n, string text, int count) {
	if(dp[index] != -1) return dp[index];
	if(index >= n) return 0;
	else {
		int dist;
		string txt;
		dp[index] = n - index;
		for(int i = index + 1 ; i <= n ; i++) {
			dist = i - index;
			if(dist <= 10) {
				for(int j = 0 ; j < count ; j++) {
					if(i-index == dict[j].length()) {
						dist = min(dist,findMinEditDist(text, dict[j], index, i));
					}
				}
			} else {
				break;
			}
			dp[index] = min(dp[index], dist + find(i,n,text,count));
		}
		return dp[index];
	}
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	cin >> tc;
	string str;
	int count = 0;
	ifstream file;
	file.open("garbled_email_dictionary.txt");
	while(!file.eof()) {
		file >> str;
		dict[count++] = str;
	}
	for(int t = 1 ; t <= tc ; t++) {
		string text;
		memset(dp,-1,sizeof(dp));
		cin >> text;
		int n = text.length();
		cout << "Case #" << t << ": " << find(0,n,text,count) << endl;
	}
	return (0);
}