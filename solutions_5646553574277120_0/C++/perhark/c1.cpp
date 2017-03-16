


#include <bits/stdc++.h>

#define REP(i, a) for( int i = 0; i < a; i++ )
#define RFOR(i,x,y) for(int i = x; i>= y; i--)
#define FOR(i,x,y) for (int i = x; i < y; i++)
#define ITFOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define VE vector <int>
#define mset(A,x) memset(A, x, sizeof A)
#define PB push_back
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define LSOne(S) (S&(-S))

using namespace std;

#define ll long long
#define lli long long int
#define PI acos(-1.0)
#define ii pair<int,int>
#define inf_ll (((1LL<<62)-1)<<1)+1
#define inf_i (1<<30)-1

int main(){

   //freopen("inputc.in", "r", stdin);
   //freopen("outc.txt", "w", stdout);

    int test,c,d,v,arr[10],acu[150],band[150];
    scanf("%d",&test);
    REP(t,test)
    {
        scanf("%d %d %d",&c,&d,&v);
        mset(acu,0);
        mset(band,0);
        int ms=0;
        REP(i,d)
            scanf("%d",&arr[i]),ms+=arr[i],band[arr[i]]=1;
        FOR(mask,1,(1<<d))
        {
            int s=0;
            REP(i,d)
            {
                if(mask&(1<<i))
                    s+=arr[i];
            }
            acu[s]=1;
        }
        int r=0;
        RFOR(i,v,1)
        {
            if(acu[i]==0)
            {
                if(i>=16 && band[16]==0)
                    r++,band[16]=1;
                else if(i>=8&& band[8]==0)
                    r++,band[8]=1;
                else if(i>=4&& band[4]==0)
                    r++,band[4]=1;
                else if(i>=2&& band[2]==0)
                    r++,band[2]=1;
                else if(i>=1&& band[1]==0)
                    r++,band[1]=1;
            }
        }
        printf("Case #%d: %d\n",t+1,r);
    }

    //fclose(stdin);
    //fclose(stdout);


    return 0;
}


