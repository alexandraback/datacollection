#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int Smax;
char s[1010];

int main()
{
	freopen("A-small-attempt0.in","rb",stdin);
	freopen("test.out","wb",stdout);
	int T;scanf("%d",&T);
	for(int cas = 1; cas <= T; ++cas){
		scanf("%d",&Smax);
		scanf("%s",s);
		int ans = 0, res = 0;
		for(int i=0;i<=Smax;++i){
			if(s[i] == '0') continue;
			if(res < i) ans += i - res, res = i;
			res += s[i] - '0';
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}
