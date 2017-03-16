#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#define LL long long

using namespace std;

int p[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int mul(int x,int y) {
	int res=1;
	if (x<0) x*=-1,res*=-1;
	if (y<0) y*=-1,res*=-1;
	return p[x-1][y-1]*res;
}

int n;
LL m;
string s;
int tt;

int pow(int a,LL b) {
	int ans=1;
	for (;b;b>>=1) {
		if (b&1) ans=mul(ans,a);
		a=mul(a,a);
	}
	return ans;
}

bool mark[10010][10];

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d: ",ii);
		cin >> n >> m >> s;
		int res=1;
		for (int i=0;i<n;++i)
			res=mul(res,s[i]-'i'+2);
		int ans=pow(res,m);

		if (ans!=-1) {
			puts("NO");
			continue;
		}

		memset(mark,false,sizeof(mark));
		bool flag=false;
		res=0;
		int cur=1;
		for (int i=0;;++i) {
			cur=mul(cur,s[i%n]-'i'+2);
			if (mark[i%n][cur+5])break;
			mark[i%n][cur+5]=true;
			if (cur==2) {
				flag=true;
				res=i+1;
				break;
			}
		}

		if (!flag) {
			puts("NO");
			continue;
		}

		memset(mark,false,sizeof(mark));
		flag=false;
		cur=1;
		for (int i=0;;++i) {
			int ni=n-1-i%n;
			cur=mul(s[ni]-'i'+2,cur);
			if (mark[ni][cur+5]) break;
			mark[ni][cur+5]=true;
			if (cur==4) {
				flag=true;
				res+=i+1;
				break;
			}
		}

		if (flag && (LL)res<=m*n) puts("YES");
		else puts("NO");
	}
}
