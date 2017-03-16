#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
long long t,n,m,a[101];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	//ifstream cin;
	//ofstream cout;
	//cin.open(".in");
	//cout.open(".out");
    scanf("%lld",&t);
    for(long long o=1; o<=t; o++)
    {
        scanf("%lld%lld",&n,&m);
        long long ans=0,ans1=2000000001,e=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+m+1);
        for(int i=1; i<=m; i++)
        {
            if(a[i]<n) n+=a[i];
            else
            {
                int k=n,br=0;
                while(k<=a[i]) {k=k*2-1; if(k==n) {br=201; break;} br++;}
                ans1=min(ans1,ans+m-i+1);
                if(br==201) {ans=201; break;}
                ans+=br;
                n=k+a[i];
            }
        }
        printf("Case #%lld: %lld\n",o,min(ans,ans1));
    }
	//cin.close();
	//cout.close();
	return 0;
}
