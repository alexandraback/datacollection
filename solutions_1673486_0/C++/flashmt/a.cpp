#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

double prob[100100],correct[100100];

int main()
{
	freopen("asmall.in","r",stdin); freopen("asmall.out","w",stdout);
	int test,typed,total;
	cin >> test;
	fr(it,1,test)
	{
		cin >> typed >> total;
		fr(i,1,typed) cin >> prob[i];
		correct[0]=1.0;
		fr(i,1,typed) correct[i]=correct[i-1]*prob[i];
		
		double ans=total+2;
		fr(del,0,typed)
			ans=min(ans,correct[typed-del]*(del+total-typed+1)+(1-correct[typed-del])*(del+total*2-typed+2)+del);
		
		printf("Case #%d: %.9lf\n",it,ans);
	}
}
