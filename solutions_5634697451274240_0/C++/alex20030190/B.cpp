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

int t,len;
char s[105];

int main(){
	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("Bs.out","w",stdout);
	
	scanf("%d",&t);
	FI(tc,1,t){
		scanf(" %s",s);
		len=strlen(s);
		s[len++]='+';
		
		int cnt=0;
		FI(j,1,len-1) if(s[j]!=s[j-1]) cnt++;
		printf("Case #%d: %d\n",tc,cnt);
	}
	return 0;
}

