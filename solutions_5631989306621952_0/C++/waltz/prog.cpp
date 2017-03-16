#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

char a[100010],ans[100010];
bool ok[100010];

template <class T>
void read(T &x)
{
	char ch;
	for (ch=getchar();(ch<'0'||ch>'9')&&ch!='-';) ch=getchar();
	x=0;int t=1;if (ch=='-') {ch=getchar();t=-1;}
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	x*=t;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int test;read(test);
	for (int T=1;T<=test;T++)
	{
		scanf("%s",a+1);int l=strlen(a+1);
		char ma=0;
		for (int i=1;i<=l;i++)
			if (a[i]>=ma) {ok[i]=1;ma=a[i];} else ok[i]=0;
		int h=1,t=l;
		for (int i=l;i;i--) if (ok[i]) ans[h++]=a[i]; else ans[t--]=a[i];
		printf("Case #%d: ",T);
		for (int i=1;i<=l;i++) putchar(ans[i]);puts("");
	}
	return 0;
}

