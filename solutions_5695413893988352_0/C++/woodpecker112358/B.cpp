#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <limits>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define PI (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=((n)-1);i>=0;i--)
#define rrep(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
bool dprint;
inline bool match(char *s,int val,const int n)
{
	int cur=n-1;
	//cout<<cur<<endl;
	while(cur>=0)
	{
		//if(dprint)
			//cout<<s[cur]<<" "<<val%10<<endl;
		if(s[cur]=='?')
		{
			cur--;
			val/=10;
			continue;
		}
		if((s[cur]-'0')!=val%10)
		{
			return false;
		}
		cur--;
		val/=10;
	}
	return true;
}
void print(int val,const int n)
{
	int tmp[3];
	//cout<<val<<endl;
	for(int i=n-1;i>=0;i--)
	{
		tmp[i]=val%10;
		val/=10;
	}
	Rep(i,n)
	{
		printf("%d",tmp[i]);
	}
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("bout.txt","w",stdout);
    int t,T;
    cin>>T;
    char c[5],m[5];
    for(t=1;t<=T;t++)
    {
    	cin>>c>>m;
    	int n=strlen(c);
    	int tnp=1;
    	int nn=n;
    	while(nn--)
    	{
    		tnp*=10;
    	}
    	int mnd=1000000,x,y;
    	//cout<<c<<" "<<m<<endl;
    	for(int i=0;i<tnp;i++)
    	{
    		for(int j=0;j<tnp;j++)
    		{
    			if(match(c,i,n)&&match(m,j,n))
    			{
    				if(Abs(i-j)<mnd)
    				{
    					mnd=Abs(i-j);
    					x=i;
    					y=j;
    				}
    			}
    		}
    	}
    	//cout<<c<<endl;
    	//dprint=true;
    	//cout<<match(c,0,n)<<endl;
    	printf("Case #%d: ",t);
    	print(x,n);
    	printf(" ");
    	print(y,n);
    	printf("\n");
    }
    return 0;
}