/*
	Author: chnlich
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cctype>
#include<climits>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
#include<list>
#include<deque>
#include<utility>

using namespace std;

typedef long long llint;
typedef unsigned long long ull;
typedef pair<int,int> ipair;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

void read(int &k)
{
	char x=getchar(); k=0;
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int A,B,len,x,st,ed,ans;
char s[20];
set<int> C;

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d",&A,&B);
		len=0;
		ans=0;
		for(x=1;x<=A;x*=10,len++);
		for(int i=A;i<=B;i++)
		{
			sprintf(s,"%d",i);
			C.clear();
			for(int j=0;j+1<len;j++)
			{
				s[j+len]=s[j];
				s[j+len+1]=0;
				sscanf(s+j+1,"%d",&x);
				if (x>=A&&x<=B&&x>i&&C.find(x)==C.end()) 
				{
					C.insert(x);
					ans++;
					//printf("%d %d\n",i,x);
				}
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	
	return 0;
}

