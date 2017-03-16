#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ar[26];
int ans[10];

int main(){
	int T; scanf("%d",&T); getchar();
	for(int Case=1; Case<=T; ++Case){
		memset(ar,0,sizeof(ar));
		memset(ans,0,sizeof(ans));
		string s; cin >> s;
		int len = s.length();
		for(int i=0; i<len; ++i)
			++ar[s[i]-'A'];
		while(ar['Z'-'A']) {
			--ar['Z'-'A'];
			--ar['E'-'A'];
			--ar['R'-'A'];
			--ar['O'-'A'];
			++ans[0];
		}
		while(ar['W'-'A']){
			--ar['T'-'A'];
			--ar['W'-'A'];
			--ar['O'-'A'];
			++ans[2];
		}
		while(ar['U'-'A']){
			--ar['F'-'A'];
			--ar['O'-'A'];
			--ar['U'-'A'];
			--ar['R'-'A'];
			++ans[4];
		}
		while(ar['X'-'A']){
			--ar['S'-'A'];
			--ar['I'-'A'];
			--ar['X'-'A'];
			++ans[6];
		}
		while(ar['G'-'A']){
			--ar['E'-'A'];
			--ar['I'-'A'];
			--ar['G'-'A'];
			--ar['H'-'A'];
			--ar['T'-'A'];
			++ans[8];
		}
		while(ar['O'-'A']){
			--ar['O'-'A'];
			--ar['N'-'A'];
			--ar['E'-'A'];
			++ans[1];
		}
		while(ar['S'-'A']){
			--ar['S'-'A'];
			--ar['E'-'A'];
			--ar['V'-'A'];
			--ar['E'-'A'];
			--ar['N'-'A'];
			++ans[7];
		}
		while(ar['F'-'A']){
			--ar['F'-'A'];
			--ar['I'-'A'];
			--ar['V'-'A'];
			--ar['E'-'A'];
			++ans[5];
		}
		while(ar['H'-'A']){
			--ar['T'-'A'];
			--ar['H'-'A'];
			--ar['R'-'A'];
			--ar['E'-'A'];
			--ar['E'-'A'];
			++ans[3];
		}
		while(ar['E'-'A']){
			--ar['N'-'A'];
			--ar['I'-'A'];
			--ar['N'-'A'];
			--ar['E'-'A'];
			++ans[9];
		}
		printf("Case #%d: ",Case);
		for(int i=0; i<10; ++i)
			for(int j=0; j<ans[i]; ++j)
				printf("%d",i);
		puts("");
	}
	return 0;
}
