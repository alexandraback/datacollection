#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <hash_map>

using namespace std;
typedef long long ll;

int k, l, s;
string str1, str2;
int cnt = 0, all_cnt = 0;
int mx = -1;

void print(int test, double res){
	cout<<"Case #"<<test<<": ";
	printf("%.10lf\n", res);
}

void check(string str){
	int cur = 0;
	for(int i=0; i<str.size(); i++){
		string buf = str.substr(i, str2.size());
		if(buf == str2){
			cnt++;
			cur++;
		}
	}
	mx = max(mx, cur);
}

void rec(string str){
	if(str.size() == s){
		check(str);
		all_cnt++;
		return;
	}
	for(int i=0; i<str1.size(); i++){
		str += str1[i];
		rec(str);
		str.pop_back();
	}
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int count_test;
	cin>>count_test;
	for(int test = 1; test <= count_test; test++){
		cin>>k>>l>>s;		
		cin>>str1>>str2;

		cnt = 0;
		all_cnt = 0;
		mx = -1;

		string buf;
		rec(buf);

		double res = (double) cnt / all_cnt;
		res = mx - res;
		print(test, res);
 	}

    return 0;
}