#include <bits/stdc++.h>

#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)

#define LL long long
#define PI 3.141592653589793238

#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define fi first
#define se second

using namespace std;

char s[1005];
bool use[1005];
int tc,len;

int p;
int stk[1005];

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("As.out","w",stdout);
	
	scanf("%d",&tc);
	FI(t,1,tc){
		scanf(" %s",s);
		len=strlen(s);
		
		p=0;
		FD(i,len-1,0){
			while(p && s[i]>s[stk[p-1]]) p--;
			stk[p++]=i;
		}
		
		memset(use,0,sizeof(use));
		FI(i,0,p-1) use[stk[i]]=true;
		printf("Case #%d: ",t);
		FD(i,len-1,0) if(use[i]) printf("%c",s[i]);
		FI(i,0,len-1) if(!use[i]) printf("%c",s[i]);
		printf("\n");
	}
		
	return 0;
}

