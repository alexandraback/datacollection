#include<bits/stdc++.h>
using namespace std;

int cnt[100];
char s[3000], t[5000];


int main(){
	freopen("Al.in", "r", stdin);
	freopen("Al.out", "w", stdout);
	int T, n, m;
	cin>>T;
	for(int o = 1; o <= T; o++){
		printf("Case #%d: ", o);
		scanf("%s", s);
		int l = strlen(s);
		int p = l + 1, q = l + 1;
		t[p] = s[0];
		for(int i = 1; i < l; i++){
			if (s[i] >= t[p]){
				t[--p] = s[i];
			}
			else{
				t[++q] = s[i];
			}
		}
		printf("%s\n", t + p);
		for(int i = max(0, p - 1); i <= q + 1; i++)
			t[i] = 0;
	}
	return 0;
} 

