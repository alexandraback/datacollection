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
#include<stack>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
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


//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
	ll y=((((tp*)a)->w)-(((tp*)b)->w));
	if(y>0)return 1;
	else if(y==0)return 0;
	else return -1;
}*/

int K,L,S;

char letter[10];

char str[10];

char temp[10];

int occ(void){
	int ret=0;
	for(int i=0;i<S;i++){
		if(i+L<=S){
			int j;
			for(j=i;j<i+L;j++){
				if(str[j-i]!=temp[j])break;
			}
			if(j==i+L)ret++;
		}
	}
	//cout<<temp<<" "<<ret<<" "<<str<<endl;
	return ret;
}

int a,b;

double go(void){
	a=0; b=0;
	int max_mask=pow(K,S);
	for(int mask=0;mask<max_mask;mask++){
		int mask2=mask;
		for(int i=0;i<S;i++){
			int idx=mask%K;
			mask/=K;
			temp[i]=letter[idx];
		}
		temp[S]='\0';
		int x=occ();
		b=max(b,x);
		a+=x;
		mask=mask2;
		//cout<<temp<<" "<<x<<endl;
		
	}
	//cout<<max_mask-1<<" "<<a<<endl;
	double ans=(b*1LL*(max_mask))-a;
	ans/=(max_mask);
	return ans;
}


inline void ReadInput(void){
	si(K); si(L); si(S);
	cin>>letter;
	cin>>str;
}

inline void solve(int turn){
	printf("Case #%d: %.9lf\n",turn,go() );
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
