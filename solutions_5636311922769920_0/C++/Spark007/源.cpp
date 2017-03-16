#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	int t;
	cin >> t;
	int cas = 1;
	int k, c, s;
	while (t--){
		cin >> k >> c >> s;
		printf("Case #%d:",cas++);
		int n = 1;
		for (int i = 0; i < s; i++){
			printf(" %d",i+1);
		}
		printf("\n");
	}
	return 0;
}