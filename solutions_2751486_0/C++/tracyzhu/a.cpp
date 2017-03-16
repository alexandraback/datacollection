#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef __int64 LL;
int cal(string a) {
	int cnt = 0,Max = 0;
	for(int i = 0;i < a.length();i++){
		if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
			Max = max(Max,cnt);
			cnt = 0;
		}else cnt++;
	}
	Max = max(Max,cnt);
	return Max;
}
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--){
		int n,L;
		string s;
		cin>>s>>n;
		L = s.length();
		int ans = 0;
		for(int i = 0;i < L;i++)
			for(int j = i;j < L;j++) {
				string cur = "";
				for(int k = i;k <= j;k++)cur+=s[k];
				if(cal(cur) >= n) ans++; 
			//	printf("%d %d\n",i,j);
			}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}