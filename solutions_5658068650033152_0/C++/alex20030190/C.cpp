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
int n,m,k;
int main(){
	if(!testing){
		freopen("C-small-attempt0.in","r",stdin);
		freopen("C.out","w",stdout);
	}
	int t;
	scanf("%d",&t);
	FIN(i,1,t){
		scanf("%d %d %d",&n,&m,&k);
		printf("Case #%d: ",i);
		if(n>m) swap(n,m);
		if(n<=2) printf("%d\n",k);
		else if(n==3) printf("%d\n",k-max(0,(k-2)/3)+(k>=(n*m-1)));
		else{
			int s_4[17]={0,1,2,3,4,4,5,6,6,7,7,8,8,9,10,11,12};
			int s_5[21]={0,1,2,3,4,4,5,6,6,7,7,8,8,9,9,10,10,11,12,13,14};
			if(m==4) printf("%d\n",s_4[k]);
			else printf("%d\n",s_5[k]);
		}
	}
	return 0;
}
