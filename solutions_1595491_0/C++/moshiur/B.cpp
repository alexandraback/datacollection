#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

int GET_INT(){int ret; scanf("%d",&ret); return ret;}

#define INT GET_INT()

typedef long long LL;
typedef pair<int,int> pii;

const int INF = 10000;

int UNSEEN;
int dp[105][105];
int N,S,P;
int score[105];

int F(int i, int s){
    if(i == N){
        if(s == S)
            return 0;
        return -INF;
    }

    int& ret = dp[i][s];

    if(ret != UNSEEN)
        return ret;

    ret = -INF;

    for(int p1 = 0;p1<=10;++p1)
        for(int p2=p1;p2<=p1+2 && p2<=10; ++p2){
            int p3 = score[i] - p2 - p1;
            if(p3 < 0 || p3 > 10) continue;
            if(abs(p3-p1) > 2 || abs(p3-p2) > 2 || abs(p2-p1) > 2) continue;

            int isSur = (abs(p3-p1)==2) || (abs(p3-p2)==2) || (abs(p2-p1)==2);
            int mx = max(p1, max(p2,p3));

            ret = max(ret, int(mx>=P)+F(i+1,s+isSur));
        }

    return ret;
}

int main()
{
    freopen("B_easy_in.txt","r",stdin);
    freopen("B_easy_out.txt","w",stdout);

    int T; scanf("%d",&T);

    REP(t,1,T){
        scanf("%d%d%d",&N,&S,&P);

        FOR(i,N) scanf("%d",score+i);

        CLR(dp,63);
        UNSEEN = dp[0][0];

        int ans = F(0,0);

        ans = max(ans, 0);

        printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}
