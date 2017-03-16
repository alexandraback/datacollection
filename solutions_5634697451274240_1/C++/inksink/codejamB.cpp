#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

string s;

int work(int num,string s){
	int len=s.length(),ans=0;
	for (int i = 1; i < len; ++i){
		if (s[i]!=s[i-1]) ans++;
	}
	printf("Case #%d: %d\n", num ,ans);
}

int main(){
	int n;
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for (int i = 1; i <= n; ++i){
		cin>>s;
		s.append(1,'+');
		work(i,s);
	}

	return 0;
}