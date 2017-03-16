#include<bits/stdc++.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define pritnf printf
#define N
using namespace std;
typedef long long int lnt;
typedef double dou;
int n;
char s[1514];
void sol(int uuu){
	RI(n);
	scanf("%s",s);
	int sum=0,ans=0;
	for(int i=0;i<=n;i++){
		while(sum<i){
			sum++;
			ans++;
		}
		sum+=s[i]-'0';
	}
	printf("Case #%d: %d\n",uuu,ans);
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("Aout_l.txt","w",stdout);
	int t;RI(t);
	for(int i=1;i<=t;i++)sol(i);
	return 0;
}

