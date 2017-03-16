#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#define LL long long
using namespace std;
LL T;
char ch;
LL gcd(LL a,LL b){if (!b)return a;return gcd(b,a%b);}
class flac{
	public:
	LL a,b;
	void weak(){
		LL t=gcd(a,b);
		a=a/t;b=b/t;
	}
	void getdata(const LL &t1,const LL &t2){a=t1;b=t2;}
	bool operator <(const flac &X){return a*X.b<b*X.a;}
	flac operator *(const LL &x){
		flac c;
		c.a=a*2;
		c.b=b;
		c.weak();
		return c;
	}
}X,mid;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%I64d",&T);
	mid.getdata(1,2);
	for (LL tt=1;tt<=T;tt++){
		scanf("%I64d%c%I64d",&X.a,&ch,&X.b);
		X.weak();
		LL step=0;
		while (X<mid){
			X=X*2;step++;
		}
		step++;
		while (!(X.b&1))X.b/=2;
		if (X.b!=1||step>40)printf("Case #%I64d: impossible\n",tt);
		else printf("Case #%I64d: %I64d\n",tt,step);
	}
}
