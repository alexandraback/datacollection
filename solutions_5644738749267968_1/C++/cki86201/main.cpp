#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int chk[2020];
int ord[2020];

double inp[2020];
bool comp(const int &a, const int &b)
{
	return inp[a] < inp[b];
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tc;
	scanf("%d",&Tc);
	for(int tt=1;tt<=Tc;tt++){
		memset(chk, 0, sizeof chk);
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=2*n;i++)scanf("%lf",inp+i);
		for(i=1;i<=2*n;i++)ord[i] = i;
		sort(ord+1,ord+1+2*n,comp);
		for(i=1;i<=2*n;i++){
			if(ord[i] <= n)chk[i] = 1;
		}
		int ans[2] = {n,0};
		int now = 0;
		for(i=1;i<=2*n;i++){
			if(chk[i])now++;
			else if(now > 0)now--, ans[0]--;
		}
		now = 0;
		for(i=1;i<=2*n;i++){
			if(!chk[i])now++;
			else if(now > 0)now--, ans[1]++;
		}
		printf("Case #%d: %d %d\n",tt, ans[1], ans[0]);
	}
	return 0;
}
