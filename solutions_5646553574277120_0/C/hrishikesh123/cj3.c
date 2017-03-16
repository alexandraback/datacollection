//cj3.c
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <map>
#include <stack>
using namespace std;
//Input macros
#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n);
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define mem(a,b) memset(a,b,sizeof(a))
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define frev(i,a,b) for(ll i=a;i>=b;i--)
#define maX(a,b) ((a)>(b)?a:b)
#define miN(a,b) ((a)<(b)?a:b)
#define ll long long
#define ld long
#define llu unsigned long long
#define pb push_back
#define gc getchar_unlocked
#define fs first
#define sn second
#define ls (node<<1)
#define rs (node<<1)|1
bool yes[100];
int arr[100];
int c,d,v;
void Readinput()
{
	si(c);si(d);si(v);
	for(int i=1;i<=d;i++) {
		si(arr[i]);
		yes[arr[i]]=true;
	}
}
void solve(int x)
{
	int i,j;
	int cnt=0;
	int temp,tp;
	int maxx=1<<d;
	for(i=0;i<maxx;i++)
	{
		temp=i;
		tp=0;
		for(j=1;j<=d;j++)
		{
			if(temp%2==1) tp+=arr[j];
			temp=temp/2;
		}
		yes[tp]=true;
	}
	for(i=1;i<=v;i++){
		if(!yes[i]){
			cnt++;
			for(j=1;j<=v;j++){
				if(yes[j] && j+i<=v && j!=i) yes[j+i]=true;
			}
			yes[i]=true;
		}
	}
	printf("Case #%d: %d\n",x,cnt);
}
int main()
{
	int t;
	si(t);
	int x=0;
	while(t--){
		x++;
		mem(yes,false);
		Readinput();
		solve(x);
	}
	return 0;
}