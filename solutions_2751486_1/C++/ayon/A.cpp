#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);
typedef long long LL;



char in[1200000];
int dp[1200000];
int ok[2000];
int n;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int i,j,k,m,cs,T;

    ok['a']=1;
    ok['e']=1;
    ok['i']=1;
    ok['o']=1;
    ok['u']=1;


    scanf("%d",&T);
    LL ans=0;
    int LAST;




    for(cs=1;cs<=T;cs++)
    {
        printf("Case #%d: ",cs);

        scanf("%s %d",in,&m);

        LAST=-1;
        ans=0;
        n=strlen(in);
        int last=0;



        for(i=0;i<n;i++)
        {

            if( !ok [in[i]])
            {
                last++;
            }
            else
            {
                last=0;
            }
            dp[i]=last;





            if(dp[i]>=m)
            {

                j=i-m+1;
                ans+= ((LL)(j-LAST))*((LL)(n-i));
             //   cout<<j<<" "<<LAST<<" "<<n<<" "<<i;
              //  asdf


                LAST=j;




              //  cout<<i<<" "<<((LL)(j-LAST))*((LL)(n-1-i))<<endl;
            }
        }

       // asdf





        printf("%lld\n",ans);







    }
    return 0;
}

