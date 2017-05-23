/*===============*\
|  ID: TMANDZU    |
|    LANG: C++    |
\*===============*/
//Tornike Mandzulashvili
//#pragma comment(linker,"/STACK:256000000")
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>

#define EPS 0.000000001
#define Pi 3.1415926535897932384626433832795028841971
#define hash1 1000003
#define hash2 1000033
#define md 1000000007
#define INF 1000000500
#define mp make_pair
#define pb push_back
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < int,int >
#define REP(i,a,n) for(i=a;i<n;i++)
#define sc scanf
#define pt printf
#define big long long
#define VI vector <int>
#define DID (long long)


using namespace std;

const int V=1000000;

int str,ans,flag,x,L,R,k,p,q,T,i,j,cons,N,t,maxt;
int H[V],d[V],n[V],w[V],e[V],s[V],delta_d[V],delta_p[V],delta_s[V];
vector <PI> Q,X[V];
VI G;

main()
{
    freopen("text.in","r",stdin);   freopen("text.out","w",stdout);


    cin>>T;
    for (t=1;t<=T;t++)
    {
        //MASIVE NULL

        maxt=0;
        for (i=0;i<=200000;i++)
        {
            X[i].clear();
            H[i]=0;
        }
        ans=0;

        cin>>N;
        for (i=1;i<=N;i++){
        cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>delta_d[i]>>delta_p[i]>>delta_s[i];

        for (j=0;j<n[i];j++)
        X[d[i]+j*delta_d[i]].pb(mp(i,j));

    //    maxt=max(maxt,d[i]+(n[i]-1)*delta_d[i]);
        }

        cons=100000;

        for (i=0;i<=800000;i++){

        G.clear();
        Q.clear();

        for (j=0;j<X[i].S;j++)
        {
            k=X[i][j].fi;
            p=X[i][j].se;

            L=w[k]+delta_p[k]*p;
            R=e[k]+delta_p[k]*p;
            R--;



            str=s[k]+delta_s[k]*p;

            flag=0;

            for (x=L;x<=R;x++)
            if (H[x+cons]<str) flag=1;

            ans+=flag;

            G.pb(str);
            Q.pb(mp(L,R));
        }

        for (q=0;q<G.S;q++)
        for (p=Q[q].fi;p<=Q[q].se;p++)
        H[p+cons]=max(H[p+cons],G[q]);

        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }

}
