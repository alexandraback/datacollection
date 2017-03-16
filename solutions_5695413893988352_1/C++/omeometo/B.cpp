#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cassert>
using namespace std;
#define INF 1LL<<60

pair<long long,long long> solve(string s,string t){
	int l=s.length();
	
	{
		long long aa=0,bb=0;
		for(int j=0;j<l;j++){
			aa=aa*10+(s[j]=='?'?0:s[j]-'0');
			bb=bb*10+(t[j]=='?'?9:t[j]-'0');
		}
		if(aa>bb)return make_pair(0,INF);
	}
	
	pair<long long,long long> ans=make_pair(0,INF);
	
	for(int i=0;i<=l;i++){
		long long a=0,b=0;
		bool ok=true;
		for(int j=0;j<l;j++){
			int da,db;
			if(j<i){
				if(s[j]=='?' & t[j]=='?')da=db=0;
				if(s[j]=='?' & t[j]!='?')da=db=t[j]-'0';
				if(s[j]!='?' & t[j]=='?')da=db=s[j]-'0';
				if(s[j]!='?' & t[j]!='?'){
					da=s[j]-'0';
					db=t[j]-'0';
					if(da!=db)ok=false;
				}
			}else if(j==i){
				int mda=-1,mdb=99;
				for(int p=0;p<=9;p++){
					for(int q=0;q<=9;q++){
						if(s[j]!='?' && s[j]-'0'!=p)continue;
						if(t[j]!='?' && t[j]-'0'!=q)continue;
						if(p>=q)continue;
						if(q-p<mdb-mda || (q-p==mdb-mda && q<mdb)){mda=p;mdb=q;}
					}
				}
				if(mda==-1)ok=false;
				else {da=mda;db=mdb;}
			}else{
				da=(s[j]=='?'?9:s[j]-'0');
				db=(t[j]=='?'?0:t[j]-'0');
			}
			a=a*10+da;
			b=b*10+db;
		}
		if(!ok)continue;
		if(b-a<ans.second-ans.first || (b-a==ans.second-ans.first&&b<ans.second))ans=make_pair(a,b);
	}
	
	return ans;
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