#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;


int K, L, S;

string s, t;
int a[30];


double computekeep() {
	int rep = L;
	for(int i=1;i<L;++i){
		bool ok = true;
		for(int k=0;k+i<L;++k){
			if(t[k] != t[k+i]) ok = false;
		}
		if(ok){
			rep = i;
			break;
		}
	}
	int cnt = 0;
	for(int i=0;i<S;){
		if(i+L>S)break;
		cnt++;
		i += rep;
	}
	return cnt;
}

int main(){

	int TC;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;++tc){
		printf("Case #%d:", tc);

		scanf("%d%d%d",&K,&L,&S);
		cin >> s;
		cin >> t;
		for(int i=0;i<30;++i)a[i] = 0;
		for(int i=0;i<K;++i){
			a[s[i]-'A']++;
		}
		double p = 1;
		bool possible = true;
		for (int i=0;i<L;++i){
			p *= (double)a[t[i]-'A']/(double)K;
			if(a[t[i]-'A'] == 0) possible = false;
		}
		double ans = p * (S-L+1);
		double keep = computekeep() - ans;
		if(possible)printf(" %.12lf\n", keep);
		else printf(" %.12lf\n",0.0);
	}
	return 0;
}