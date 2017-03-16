#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;

typedef long long LL;

int R, N, M, K;
int v[9];
int d[9];
map<string,double>ans;

void calc() {
    string s=string(N,'_');
    for (int i=0; i<N; i++) s[i]=d[i]+'0';

    sort(s.begin(), s.end());
    vector<int>r;
    for (int mask=0; mask<(1<<N); mask++) {
	int p=1;
	for (int i=0; i<N; i++) if (mask&(1<<i)) p*=d[i];
	r.push_back(p);
    }
    sort(r.begin(), r.end());
    double pp=1.0;
    for (int i=0; i<K; i++) {
	pp *= upper_bound(r.begin(), r.end(), v[i]) - lower_bound(r.begin(), r.end(), v[i]);
    }
    ans[s]=pp;
    
}

void rec(int cnt) {
    if (cnt==N) {
	d[cnt]=0;
	return calc();
    }
    for (int i=2; i<=M; i++) {
	d[cnt]=i;
	rec(cnt+1);
    }
}
	
int main() {
    int T;
    scanf("%d", &T);
    puts("Case #1:");
    scanf("%d%d%d%d", &R, &N, &M, &K);
    
    for (;R--;) {
	for (int i=0; i<K; i++) scanf("%d", v+i);
	rec(0);

	string s; double x=0;
	for (map<string,double>::iterator it=ans.begin(); it!=ans.end(); it++) {
	    //cout<<it->first<<' '<<it->second<<endl;
	    if (it->second>x) {
		x=it->second;
		s=it->first;
	    }
	}
	cout<<s<<endl;
	ans.clear();
    }
    return 0;
}
