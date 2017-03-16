#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <string>
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
#include <cstring>
#include <fstream>

using namespace std;

int INF = 1E9;
int m,n;
vector <int> res;

void rec(int b, vector <int> p){
	if(b == n-1){
		int dp[6] = {1};
		for(int i = 0; i < p.size(); i++)
			for(int j = 0; j < n; j++)
				if(p[i]&(1<<j))
					dp[i+1] += dp[i];
		if(dp[n-1]==m) res = p;
		return;
	}
	for(int i = 0; i < (1<<n); i++){
		bool can = true;
		for(int j = 0; j < n; j++)
			if(j <= b && (i&(1<<j)))
				can = false;
		vector <int> t = p;
		t.push_back(i);
		if(can) rec(b+1,t);
	}
}


int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	ofstream fout;
	fout.open("answer.out");

	int T;
	cin>>T;
	

	for(int Case = 1; Case <= T; Case++){
		fout<<"Case #"<<Case<<": ";
		//fout<<endl;
		res.clear();
		cin>>n>>m;
		rec(0, vector<int>{});
		if(res.empty()) fout<<"IMPOSSIBLE"<<endl;
		else{
			fout<<"POSSIBLE"<<endl;
			for(int i = 0; i < res.size(); i++){
				string r = "";
				for(int j = 0; j < n; j++){
					if(res[i]&(1<<j))
						r+='1';
					else
						r+='0';
				}
				fout<<r<<endl;
			}
			fout<<string(n,'0')<<endl;
		}
		//fout<<endl;
	}
	
	return 0;
}
