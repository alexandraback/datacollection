#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int con=1000000;
char s[con+10];
bool yuan[400];
int l[con+10];
int test,N,t,ll,ans,len;
void read(int &x){char ch=getchar();bool flag=false;while ((ch<'0'||ch>'9')&&ch!='-')ch=getchar();if (ch=='-'){flag=true;ch=getchar();}x=0;while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}if (flag)x=-x;}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&test);yuan['a']=true;yuan['e']=true;yuan['i']=true;yuan['o']=true;yuan['u']=true;
	for (int tt=1;tt<=test;tt++){
		scanf("%s%d",s,&N);
		len=strlen(s);t=0;ll=2e9;
		for (int i=len-1;i>=0;i--){
			if (yuan[int(s[i])])t=0;
			else	t++;
			if (t>=N)ll=i+N-1;
			l[i]=ll;
		}
		ans=0;
		for (int i=0;i<len;i++)
		if (l[i]<2e9)ans+=len-l[i];
		printf("Case #%d: %d\n",tt,ans);
	}
}
