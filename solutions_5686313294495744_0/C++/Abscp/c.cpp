#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<list>
#include<string>
#include<map>
using namespace std;
string s[2000], t[2000];
int count(int x){
	int c=0;
	while(x) {
		x-=x&(-x);
		++c;
	}
	return c;
}
int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; ++i){
		int n;
		scanf("%d",&n);
		for(int j=0; j<n; ++j)
			cin >> s[j] >> t[j];
		
		int ans = 0;
		for(int j=0; j<(1<<n)-1; ++j) {
			if(count(j) <= ans) continue;
			map<string,bool> a, b;
			bool ok=1;
			for(int k=0; k<n; ++k)
				if((j&(1<<k)) == 0){
					a[s[k]]=true;
					b[t[k]]=true;
				}
			for(int k=0; k<n; ++k)
				if(j&(1<<k)){
					if(a.count(s[k]) && b.count(t[k]))continue;
					ok = 0;
					break;
				}
			if(ok)	ans = count(j);
		}
		printf("Case #%d: %d\n", i+1, ans);
	}
	
	return 0;
}
