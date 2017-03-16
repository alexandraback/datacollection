#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cctype>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<map>
#include<set>
#define pi (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
#define SZ 1000006
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
char s[SZ];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("Aout.txt","w",stdout);
	int t,T,i,j,n,l;
	scanf("%d",&T);
	bool isvow[26]={false};
	char vow[]={'a','e','i','o','u'};
	Rep(i,5)
        isvow[vow[i]-'a']=true;
	for(t=1;t<=T;t++)
	{
	    scanf("%s%d",s,&n);
	    l=strlen(s);
	    mint ans=0;
	    int cnt=0,last=-1;
	    rep(i,l)
	    {
	        if(!isvow[s[i]-'a'])
                cnt++;
            else
                cnt=0;
            if(cnt>=n)
                last=i-n+1;
            //cout<<i<<" "<<last<<endl;
            ans+=last+1;
	    }
	    printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}

