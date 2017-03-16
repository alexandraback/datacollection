#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

string s;
int N;

int main(){
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;++tt){
		printf("Case #%d: ",tt);
		scanf("%d",&N);
		cin >> s;
		int num = 0;
		int ans = 0;
		for(int i=0;i<=N;++i){
			int cur = s[i] - '0';
			if (num >= i) {
				num += cur;
			} else {
				ans += (i-num);
				num = i+cur;
			}
		}
		printf("%d\n",ans);
	}
}