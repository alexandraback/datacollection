#include<iostream>
#include<set>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<list>
#include<valarray>
#include<numeric>
#include<sstream>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define clr(a,val) memset(a,val,sizeof(a))
#define forn(i,n) for(int i=0;i<n;i++)
#define forv(i,v) forn(i,(v).size())
#define sz(v) v.size()
#define enter printf("\n")
#define space printf(" ")

//typedef _int64 int LL;
//typedef vector<int> VI;
//typedef pair<int,int> pii;

#define maxn 1000000

/*
int cnt[maxn+50];
queue<int> qi;


int reverse(int i){
	int ans=0;
	while(i){
		ans=ans*10+(i%10);
		i/=10;
	}
	return ans;
}

void init() {
	memset(cnt,-1,sizeof(cnt));
	cnt[1]=1;
	qi.push(1);
	while(true){
		int x=qi.front();
		qi.pop();
		if(x>maxn) return;
		int rev=reverse(x);
		if(cnt[rev]==-1){
			cnt[rev]=cnt[x]+1;
			qi.push(rev);
		}
		if(cnt[x+1]==-1){
			cnt[x+1]=cnt[x]+1;
			qi.push(x+1);
		}
	}
}
*/

_int64 getpow(int powcnt){
	int ans=1;
	for(int i=1;i<=powcnt;i++)
		ans*=10;
	return ans;
}

int solve(int n) {
	if(n<10)
		return n;
	char ch[20];
	itoa(n,ch,10);
		int len=strlen(ch);
		int halflen=len/2;
		int ans=0;
		int revert=0;
		if(ch[0]!='1')
			revert=1;
		else{
			for(int i=1;i<=halflen-1;i++)
				if(ch[i]>'0'){
					revert=1;
					break;
				}
		}
		int allzero=1;
		for(int i=len-1;i>=len;i--)
			if(ch[i]!='0')
				allzero=0;
		if(allzero)
			revert=1;
		ans=revert;
		_int64 tenpow=1;
		if(revert){
			for(int i=0;i<=halflen-1;i++) {
				if(i==0)
					ans+=tenpow*(ch[i]-'0')-1;
				else
					ans+=tenpow*(ch[i]-'0');
				tenpow *= 10;
			}
		}
		tenpow=1;
		for(int i=len-1;i>=halflen;i--) {
			ans+=tenpow*(ch[i]-'0');
			tenpow *= 10;
		}
	return ans+1+solve(getpow(len-1)-1);
}

// int solve

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	//printf("%d",reverse(2010));

	int t;
	_int64 n;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		//scanf("%d",&n);
		scanf("%lld",&n);

		
		printf("Case #%d: ",c);
		cout<<solve(n)<<endl;
	}
	
	return 0;
}