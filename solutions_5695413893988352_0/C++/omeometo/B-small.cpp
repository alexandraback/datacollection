#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define INF 1LL<<60

pair<long long,long long> solve(string s,string t){
	int p=1;
	for(int i=0;i<s.length();i++)if(s[i]=='?')p*=10;
	for(int i=0;i<t.length();i++)if(t[i]=='?')p*=10;
	pair<long long,long long> best=make_pair(0LL,INF);
	for(int k=0;k<p;k++){
		int kk=k;
		long long a=0,b=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='?'){
				a=a*10+(kk%10);
				kk/=10;
			}else{
				a=a*10+(s[i]-'0');
			}
		}
		for(int i=0;i<t.length();i++){
			if(t[i]=='?'){
				b=b*10+(kk%10);
				kk/=10;
			}else{
				b=b*10+(t[i]-'0');
			}
		}
		//printf("%lld %lld\n",a,b);
		if(a>b)continue;
		if(b-a>best.second-best.first || (b-a==best.second-best.first && b>best.second))continue;
		best=make_pair(a,b);
	}
	return best;
}

void pf(long long x,int l){
	vector<int> d(l);
	for(int i=0;i<l;i++){d[i]=x%10;x/=10;}
	for(int i=l-1;i>=0;i--)printf("%d",d[i]);
}

main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		char s[100],t[100];
		scanf("%s%s",s,t);
		
		pair<long long,long long> a=solve(string(s),string(t)); //minimize (t-s,s), assuming t>=s
		pair<long long,long long> b=solve(string(t),string(s)); //minimize (s-t,t), assuming s>=t
		if(a.second-a.first<b.second-b.first){
			pf(a.first,strlen(s));
			printf(" ");
			pf(a.second,strlen(t));
			printf("\n");
		}else if(a.second-a.first>b.second-b.first){
			pf(b.second,strlen(t));
			printf(" ");
			pf(b.first,strlen(s));
			printf("\n");
		}else{
			swap(b.second,b.first);
			pair<long long,long long> c=min(a,b);
			
			pf(c.first,strlen(s));
			printf(" ");
			pf(c.second,strlen(t));
			printf("\n");
		}
	}
}