//cj1.c
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
int t,r,c,w;
void Readinput()
{
	si(r);si(c);si(w);
}
void solve()
{

}
int main()
{
	int cnt=0;
	si(t);
	while(t--){
		cnt++;
		Readinput();
		int i,j;
		int ans=(ceil((c-w)/(double)w));
		ans+=w;
		printf("Case #%d: %d\n",cnt,ans);
	}
	return 0;
}