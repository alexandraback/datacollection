#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>

#define FI first
#define SE second
#define MP make_pair

using namespace std;

typedef pair<int,int> pii;

char s[1000008];
int tnum, L, n, f[1000008];
long long ans;

int main(){
	scanf("%d", &tnum);
	for (int t=1; t<=tnum; t++){
		scanf("%s%d", s+1, &n);
		L= strlen(s+1);
		ans=0;
		int fur=0;
		for (int i=1; i<=L; i++){
			if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
				f[i]=f[i-1];
				fur=0;
			}
			else {
				if (fur==0) fur=i;
				if (i-fur+1>=n) f[i]=i-n+1;
				else
					if (fur>0) f[i]=f[fur-1];
			}
			
			ans+=f[i];
		}
		
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
