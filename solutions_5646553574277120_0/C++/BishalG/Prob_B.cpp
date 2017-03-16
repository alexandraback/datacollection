/****************************************************************************
 *                                                                          *
 *                    ==>> BG_PeaceMind(BISHAL)                             *
 *                   try=0; while(!success) try++;                          *
 ****************************************************************************/
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
using namespace std;
typedef long long ll;
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/************************************************************************
 * /////////////////////////////////////////////////////////////////////*
 ************************************************************************/
/// [ Look at my code below, My code is so amazing !! :P ]
///  Digit    0123456789
#define MX    100005

int m,MP[155],MPP[155];

int make(int vl){

    int i,j,cnt=0;
    CPY(MPP,MP);
    MPP[vl]=1;
    for(i=1;i<=m;i++) {
        if(MP[i]) {
            MPP[i+vl]=1;
        }
    }
    for(i=1;i<=m;i++) {
        if(MPP[i]) {
            MP[i]=1;
        }
    }
    for(i=1;i<=m;i++) {
        if(MP[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
     freopen("Bishal_Out_CCCC.txt", "w", stdout);
    int c,x,d,v,tc,cs=1,i,j,k;
    S(tc);
    while(tc--) {
        S3(c,d,m);
        CLR(MP);
        vector<int>v;
        fr(i,0,d-1) {
            S(x);
            v.pb(x);
        }

        int lm=(1<<d)-1;

        for( i=0;i<=lm;i++) {
            int sm=0;
            for( j=0;j<d;j++) {

                if( i&(1<<j) ){
                    sm+=v[j];
                }
            }
            MP[sm]=1;
        }
        int ans=0;
        fr(i,1,m){
            if(!MP[i]) {
                int kk=make(i);
                ans++;
                if(kk==m)break;
            }
        }

        printf("Case #%d: %d\n",cs++,ans);
    }
    return 0;
}
