/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)



//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
	ll y=((((tp*)a)->w)-(((tp*)b)->w));
	if(y>0)return 1;
	else if(y==0)return 0;
	else return -1;
}
bool way(ii x,ii y){
	return x.first<y.first or x.first==y.first and x.second<y.second;
}

ll modpow(ll base, ll exponent,ll modulus){
	if(base==0&&exponent==0)return 0;
	ll result = 1;
	while (exponent > 0){
		if (exponent % 2 == 1)
		    result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

*/


#define MAXN 1000010
#define ls (node<<1)
#define rs ((node<<1)+1)
#define ii pair<int,int>

int table[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};

int add[4][4]={{0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1}};

char str[MAXN];

int arr[MAXN];

ll L,X;

inline void ReadInput(void){
	sl(L); sl(X);
	ss(str);
}

inline void solve(int turn){
	ll magic=min(X,20LL+(X%4));
	for(ll i=0;i<L;i++){
		if(str[i]=='i')arr[i]=1;
		else if(str[i]=='j')arr[i]=2;
		else arr[i]=3;
		for(ll j=1;j<magic;j++){
			arr[L*j+i]=arr[i];
            str[L*j+i]=str[i];
		}
	}
	ll N=L*magic;
    str[N]='\0';
    ll a=-1,b=-1,c=-1;
	int foo=0,bar=0;
	bool stage1=false,stage2=false,stage3=false;
    for(ll i=0;i<N;i++){
		bar^=(add[foo][arr[i]]);
		foo=table[foo][arr[i]];
    	if(!stage1 and foo==1 and !bar)stage1=true;
		if(stage1 and foo==3 and !bar)stage2=true;	
	}
	if(stage1 and stage2 and !foo and bar)stage3=true;
	if(stage3)printf("Case #%d: YES\n",turn);
	else printf("Case #%d: NO\n",turn );
}

inline void Refresh(void){
	
}

int main()
{	
	int t; si(t);
	for(int i=1;i<=t;i++){
		ReadInput();
		solve(i);
	}
    return 0;
}
