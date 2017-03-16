#include<bits/stdc++.h>
using namespace std;

#define in(Kavya) scanf("%lld",&Kavya);

typedef long long int ll;

ll TC,T,Len,i,j,NumberLen;
bool Ex;
char Str[5000];
vector<ll> Ans;

char Numbers[10][10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
	in(TC);
	for(T=1;T<=TC;++T) {
		ll Hash[26]={0};
		memset(Str,0,sizeof Str);
		scanf("%s",Str);
		Len=strlen(Str);
		for(i=0;i<Len;++i) ++Hash[Str[i]-'A'];
		while(Hash['Z'-'A']) {
			Ans.push_back(0);
			--Hash['Z'-'A'];
			--Hash['E'-'A'];
			--Hash['R'-'A'];
			--Hash['O'-'A'];
		}
		while(Hash['W'-'A']) {
			Ans.push_back(2);
			--Hash['T'-'A'];
			--Hash['W'-'A'];
			--Hash['O'-'A'];
		}
		while(Hash['U'-'A']) {
			Ans.push_back(4);
			--Hash['F'-'A'];
			--Hash['O'-'A'];
			--Hash['U'-'A'];
			--Hash['R'-'A'];
		}
		while(Hash['X'-'A']) {
			Ans.push_back(6);
			--Hash['S'-'A'];
			--Hash['I'-'A'];
			--Hash['X'-'A'];
		}
		while(Hash['G'-'A']) {
			Ans.push_back(8);
			--Hash['E'-'A'];
			--Hash['I'-'A'];
			--Hash['G'-'A'];
			--Hash['H'-'A'];
			--Hash['T'-'A'];
		}
		for(i=0;i<10;++i) {
			Ex=true;
			while(Ex) {
				NumberLen=strlen(Numbers[i]);
				for(j=0;j<NumberLen;++j) {
					if(i==3 && Hash['E'-'A']<2) { Ex=false; break; }
					else if(i==7 && Hash['E'-'A']<2) { Ex=false; break; }
					if(i==9 && Hash['N'-'A']<2) { Ex=false; break; }
					if(Hash[Numbers[i][j]-'A']<=0) {
						Ex=false;
						break;
					}
				}
				if(Ex) {
					Ans.push_back(i);
					for(j=0;j<NumberLen;++j) {
						--Hash[Numbers[i][j]-'A'];
					}
				}
			}
		}
		sort(Ans.begin(),Ans.end());
		printf("Case #%lld: ",T);
		for(i=0;i<Ans.size();++i) printf("%lld",Ans[i]);
		printf("\n");
		Ans.clear();
	}
	return 0;
}
