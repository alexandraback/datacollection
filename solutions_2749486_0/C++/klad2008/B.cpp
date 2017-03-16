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
int test,x,y,res;
void read(long long &x){char ch=getchar();bool flag=false;while ((ch<'0'||ch>'9')&&ch!='-')ch=getchar();if (ch=='-'){flag=true;ch=getchar();}x=0;while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}if (flag)x=-x;}
int main(){
	//small
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&test);
	for (int tt=1;tt<=test;tt++){
		scanf("%d%d",&x,&y);
		res=0;
		printf("Case #%d: ",tt);
		if (x>=0)for (int i=1;i<=x;i++)printf("WE");
		else for (int i=1;i<=-x;i++)printf("EW");
		if (y>=0)for (int i=1;i<=y;i++)printf("SN");
		else for (int i=1;i<=-y;i++)printf("NS");
		printf("\n");
	}
}
