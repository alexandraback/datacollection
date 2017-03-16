#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

int T,ti;
int a,b;
char s[100];

int check(int t){
	sprintf(s,"%d",t);
	int n=strlen(s);
	int now=t;
	int mo=1;
	for (int i=1;i<n;i++) mo*=10;
	vector<int> ans;ans.clear();
	for (int z=0;z<n;z++){
		now=now%mo*10+s[z]-'0';
		if (now>t&&now<=b) ans.PB(now);
	}
	sort(ans.begin(),ans.end());
	return unique(ans.begin(),ans.end())-ans.begin();
}

int main(){
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		scanf("%d%d",&a,&b);
		int ans=0;
		for (int t=a;t<b;t++) ans+=check(t);
		printf("Case #%d: %d\n",ti,ans);
	}
    return 0;
}
