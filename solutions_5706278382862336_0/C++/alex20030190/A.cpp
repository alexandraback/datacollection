#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<deque>
#include<stack>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define UI unsigned int
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define PB push_back
#define PF push_front
#define _PB pop_back
#define _PF pop_front
#define F first
#define S second
#define PI 3.1415926535897
#define _e 2.718281828
#define FIN(i,a,b) for(int i=a;i<=b;i++)
#define FEX(i,a,b) for(int i=a;i<b ;i++)
#define DIN(i,a,b) for(int i=a;i>=b;i--)
#define DEX(i,a,b) for(int i=a;i>b ;i--)
#define DEBUG printf
bool testing = false;
int t;
char c;
LL x,y,tmp;
LL gcd(LL a,LL b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main(){
	if(!testing){
		freopen("A-small-attempt0.in","r",stdin);
		freopen("A.out","w",stdout);
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		tmp=(1<<20);
		tmp*=(1<<20);
		cin >> x >> c >> y;
		printf("Case #%d: ",i);
		LL g=gcd(x,y);
		x/=g,y/=g;
		if(tmp%y!=0){printf("impossible\n");}
		else{
			x*=(tmp/y);
			for(int i=1;i<=40;i++){
				tmp/=2;
				if(x>=tmp){printf("%d\n",i);break;}
			}
		}
	}
	return 0;
}
