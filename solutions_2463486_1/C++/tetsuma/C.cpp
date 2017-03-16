#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long ll;
#define INF (1<<29)

string itos(long long number){
  stringstream ss;
  ss << number;
  return ss.str();
}

bool check(string s){
	int n=s.length();
	for(int i=0;i<s.length();i++)if(s[i]!=s[n-1-i])return false;
	return true;
}

long long stollint(string s){
	long long ret=0;
	for(int i=0;i<s.length();i++){
		ret*=10;
		ret+=(long long)s[i]-'0';
	}
	return ret;
}

int main(){
	long long a, b;
	vector<long long> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(9);
	for(int i=1;i<10000;i++){
		string s=itos((long long)i), t=s, st;
		reverse(t.begin(),t.end());
		st=s+t;
		long long n=(long long)atoi(st.c_str());
		n=n*n;
		string nn=itos(n);
		if(check(nn))v.push_back(n);
		char x='0';
		for(int j=0;j<10;j++){
			st=s+x+t;
			n=atoi(st.c_str());
			n=n*n;
			string nn=itos(n);
			if(check(nn))v.push_back(n);
			x++;
		}
	}
	sort(v.begin(),v.end());
	int t;
	cin >> t;
	for(int tc=1;tc<=t;tc++){
		cin >> a >> b;
		int ret=0;
		for(int i=0;i<v.size();i++)
			if(v[i]>=a&&v[i]<=b)ret++;		
		printf("Case #%d: %d\n",tc,ret);
	}
	return 0;
}

