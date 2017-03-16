#include <bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int has[26];//whether it has alphabet i
char ks[109];//monkey keys
char t[109];//target
char cs[109];

int k,l,s;
int matches=0;

void rback(int x){
	if(x==s){
		cs[x]=0;
		for(int i=0;i<=s-l;i++){//start
			bool legit=true;
			for(int j=0;j<l;j++){//cur match
				if(cs[i+j]!=t[j]){
					legit=false;break;
				}
			}
			if(legit){
				//printf("%s\n",cs);
				matches++;
			}
		}
		return;
	}
	for(int i=0;i<k;i++){
		cs[x]=ks[i];
		rback(x+1);
	}
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		scanf("%d%d%d",&k,&l,&s);// keyboard,length of target, number of keys to type
		scanf("%s %s",ks,t);
		for(int i=0;i<26;i++)has[i]=0;
		for(int i=0;i<k;i++){
			has[ks[i]-'A']++;
		}
		bool legit=true;
		for(int i=0;i<l;i++){
			if(!has[t[i]-'A']){
				legit=false;
			}
		}
		if(!legit){
			printf("Case #%d: 0.0\n",tcno);continue;
		}
		int cmax=0;
		for(int i=1;i<=l;i++){//earliest restart position
			legit=true;
			for(int j=0;i+j<l;j++){
				if(t[i+j]!=t[j]){
					legit=false;break;
				}
			}
			if(legit){//i is earliest restart
				cmax=(s-(l-i))/i;break;
			}
		}
		matches=0;
		rback(0);
		int total=1;
		for(int i=0;i<s;i++){
			total*=k;
		}
		//printf("%d %d %d ",cmax,matches,total);
		double ans=(double)cmax-(double)matches/(double)total;
		printf("Case #%d: %f\n",tcno,ans);
	}
}
