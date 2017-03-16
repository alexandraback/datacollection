#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#define fou(i,j,k) for (int i=j;i<=k;i++)
#define fod(i,j,k) for (int i=j;i>=k;i--)
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> Pii;

const int maxn=100;
const int inf=0x3f3f3f3f;
const LL infLL=0x3f3f3f3f3f3f3f3fLL;

int n;
char s1[maxn],s2[maxn];

void init(){
	scanf("%s%s",s1,s2);
}

bool ck(int x,char *s)
{
	fod(i,n-1,0){
		if (s[i]!='?' && s[i]-'0'!=x%10) return false;
		x/=10;
	}
	return true;
}

void solve(){
	int x=10000,y=10000,ans,ed;
	n=strlen(s1);
	if (n==1) ed=9; else
	if (n==2) ed=99; else
	if (n==3) ed=999;
	ans=10000;
	fou(i,0,ed) if (ck(i,s1))
		fou(j,0,ed) if (ck(j,s2)){
			if (ans>abs(i-j)){
				ans=abs(i-j);
				x=i;
				y=j;
			}else
			if (ans==abs(i-j)){
				if (x>i){
					x=i;y=j;
				}else
				if (x==i && y>j) y=j;
			}
		}
	if (n==1) printf("%d %d\n",x,y);
	if (n==2) printf("%02d %02d\n",x,y); else
	if (n==3) printf("%03d %03d\n",x,y);
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	fou(i,1,T){
//	while (scanf("",)!=EOF){
		printf("Case #%d: ",i);
		init();
		solve();
	}
	return 0;
}
