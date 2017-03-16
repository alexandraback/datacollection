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

typedef long long int LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

#define maxn 1000000

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

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	//printf("%d",reverse(2010));

	init();
	int t,n;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d",&n);
		printf("Case #%d: %d\n",c,cnt[n]);
	}
	
	return 0;
}