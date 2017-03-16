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

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	int r,c,w;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++) {
		scanf("%d%d%d",&r,&c,&w);
		int ans1 = (c-1)/w+w;
		int ans2 = (r-1) * (c/w);
		int ans = ans1 + ans2;
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}