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
#include <cstring>
#include <deque>
#include <fstream>

#define deb(x) cout << "> " << #x << " : " << (x) << endl;
#define EPS 0.000000001
#define Pi 3.1415926535897932384626433832795028841971
#define hash1 1000003
#define hash2 1000033
#define md 1000000007
#define INF 1000000500ll
#define mp make_pair
#define pb push_back
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < ll ,ll  >
#define REP(i,a,n) for(i=a;i<n;i++)
#define sc scanf
#define pt prll f
#define big long long
#define VI vector <ll >
#define DID (long long)
#define ll long long
#define AL(a) (a).begin(),(a).end()
#define INFF DID INF*INF

using namespace std;

const int T=32;

ll a[T],b[T],k[T];
ll dp[T][2][2][2][2];

main(){
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);

    int A,B,K;

    int tests;
    cin>>tests;
    for (int t=1;t<=tests;t++){

        for (int i=30;i>=0;i--)
        for (int x=0;x<2;x++)
        for (int y=0;y<2;y++)
        for (int z=0;z<2;z++)
        dp[i][x][y][z][0]=dp[i][x][y][z][1]=0;

        ll ans=0;
        cin>>A>>B>>K;
        A--;
        B--;
        K--;

        for (int i=0;i<30;i++)
            a[i]=(((1<<i)&A)>0) , b[i]=(((1<<i)&B)>0) , k[i]=(((1<<i)&K)>0);

        dp[30][1][1][1][1]=1;
        for (int i=29;i>=0;i--){
            for (int x=0;x<2;x++)
            for (int y=0;y<2;y++)
            for (int z=0;z<2;z++)
            for (int I=0;I<2;I++)
            for (int J=0;J<2;J++){
                if (I && !a[i] && x)
                    continue;
                if (J && !b[i] && y)
                    continue;

                int P=I&J;
                if (P && !k[i] && z)
                    continue;

                int newx=(x && (a[i]==I));
                int newy=(y && (b[i]==J));
                int newz=(z && (k[i]==P));

                if (newz)
                    dp[i][newx][newy][newz][1]+=dp[i+1][x][y][z][1];

                if (!newz){
                    ll h=1;
                    if (newx){
                        int g=0;
                        for (int j=i-1;j>=0;j--)
                        if (a[j])
                            g+=1<<j;
                        g++;
                        h*=g;
                    }else
                    h*=1<<i;

                    if (newy){
                        int g=0;
                        for (int j=i-1;j>=0;j--)
                        if (b[j])
                            g+=1<<j;
                        g++;
                        h*=g;
                    }else
                    h*=1<<i;

                    ans+=dp[i+1][x][y][z][1]*h;
                }
            }

            for (int x=0;x<2;x++)
            for (int y=0;y<2;y++)
            for (int z=0;z<2;z++)
            ans += dp[0][x][y][z][1];
        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}

