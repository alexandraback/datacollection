/* Nakshatra Maheshwari...!!!
  IIIT Allahabad....!! */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#define ll long long
#define mx7 10000007
#define mx6 1000006

//...........................................//
//input
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%lld",&t)
#define sf(t) scanf("%f",&t)
#define sdb(t) scanf("%lf",&t)
#define schar(c) scanf("%c",&c)
#define sstr(s) scanf("%s",s)
#define ssi(a,b) scanf("%d%d",&a,&b)
#define ssl(a,b) scanf("%lld%lld",&a,&b)
//...........................................//
//Output
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define pf(a) printf("%f\n",a)
#define pdb(a) printf("%lf\n",a)
//...........................................//
using namespace std;
int main()
{
	//freopen("ss.in","r",stdin);
	//freopen("out1.txt","w",stdout);
    int t,i;
    scanf("%d",&t);
    int initial=0,count=0;
 
    int n,m,k;
    int sqr;
    int ans=0;
    while(t--)
    {
        initial++;
        ans=0;
        cin>>n;
        cin>>m;
        cin>>k;
        sqr=sqrt(k);
      
        if((sqr*sqr>k/2) && (sqr<=n)&& (sqr<=m))
        {
            ans=k-(sqr*sqr-(sqr*2+2*(sqr-2)));
      
        ans=ans-(k-(sqr*sqr));
      
        }
        else
        {
int l,b;
 
        l=sqr;
        b=sqr;
        bool con=true;
        do
        {
            if(con)
            {l++;
            con=false;
            }
            else{
            b++;
            con=true;
            }
 
        }while(l*b<=k);
        if(con)
        b--;
        else
        l--;
        ans=k-(l*b-(b*2+2*(l-2)));
        //cout<<endl;
        //cout<<ans<<endl;
 
        ans=ans-(k-(l*b));
        //cout<<ans<<endl;
        }
        printf("Case #%d: %d\n",initial,ans);
 
 
    }
 
 return 0;
}
