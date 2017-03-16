#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<cstdio>
#include<set>
#include<map>
#include<cstdlib>
#include<cstring>
#include<stack>

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define ABS(a) (a>0?a:-a)

#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define ULL unsigned long long
#define LL long long
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);

using namespace std;

int main()
{
    freopen("alarge.in","r",stdin);
    freopen("alarge.out","w",stdout);

int t;
scanf("%d",&t);
FOR(test,1,t)
{
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    REP(i,n){
        cin>>a[i];
        sum += a[i];
    }

    double totalscore = 2.0*sum;
    double score = totalscore/n;

    printf("Case #%d: ",test);

    bool flag[n];
    memset(flag,false,sizeof(flag));
    int cnt = 0;
    REP(i,n){

        if (score>=a[i])
        {
            flag[i] = true;
            cnt++;
        }

    }

    REP(i,n)
    {
        if (!flag[i])
        totalscore -= a[i];
    }

    //cout<<"score"<<score<<endl;
    score = totalscore/cnt;
    REP(i,n)
    {
        if (!flag[i])
        printf("0 ");
        else
        {
            double ans = (score-a[i])/sum;
            ans *= 100;
            printf("%.8lf ",ans);
        }
    }
    cout<<endl;
}

return 0;
}
