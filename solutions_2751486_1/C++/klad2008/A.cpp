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
const long long con=1000000;
char s[con+10];
bool yuan[400];
long long l[con+10];
long long test,N,t,ll,ans,len;
void read(long long &x){char ch=getchar();bool flag=false;while ((ch<'0'||ch>'9')&&ch!='-')ch=getchar();if (ch=='-'){flag=true;ch=getchar();}x=0;while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}if (flag)x=-x;}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%I64d",&test);yuan['a']=true;yuan['e']=true;yuan['i']=true;yuan['o']=true;yuan['u']=true;
	for (long long tt=1;tt<=test;tt++){
		scanf("%s%I64d",s,&N);
		len=strlen(s);t=0;ll=2e14;
		for (long long i=len-1;i>=0;i--){
			if (yuan[int(s[i])])t=0;
			else	t++;
			if (t>=N)ll=i+N-1;
			l[i]=ll;
		}
		ans=0;
		for (long long i=0;i<len;i++)
		if (l[i]<2e9)ans+=len-l[i];
		printf("Case #%I64d: %I64d\n",tt,ans);
	}
}
