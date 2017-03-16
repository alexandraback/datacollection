#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;

lint gcd(lint a,lint b){
	return a%b==0 ? b : gcd(b,a%b);
}

int main(){
	int z; scanf("%d",&z);
	int casenr=0;
	while(z--){
		casenr++;
		printf("Case #%d: ",casenr);
		char s[1000];
		scanf("%s\n",s);
		int u = strlen(s);
		FOR(i,0,u) if(s[i]=='/') s[i]=' ';
		
		lint a,b;
		sscanf(s,"%lld %lld\n",&a,&b);
		
		lint d = gcd(a,b);
		a = a/d; b = b/d;

		lint p = 1;
		int licz = 0;
		while(p<b){
			p=p*2;
			licz++;
		}
		if(p!=b){
			printf("impossible\n");
		}
		else{
			int res = 0;
			while(a<b){
				a*=2;
				res++;
			}
			printf("%d\n",res);
		}
		
		
		
	}
	return 0;
}
  

