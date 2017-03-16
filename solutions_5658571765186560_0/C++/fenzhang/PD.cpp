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
int X,R,C;
int test(){
	if(X==1)return 1;
	if(X==2)return R*C%2==0;
	if(X==3)return R*C%3==0&&min(R,C)>1;
	if(X==4)return R*C%4==0&&max(R,C)>=4&&min(R,C)>=3;
	return 0;
}
void sol(int uuu){
	RI(X);RII(R,C);
	printf("Case #%d: %s\n",uuu,test()?"GABRIEL":"RICHARD");
}
int main(){
	freopen("D-small-attempt1.in","r",stdin);
	freopen("Dout_s.txt","w",stdout);
	int t;RI(t);
	for(int i=1;i<=t;i++)sol(i);
	return 0;
}

