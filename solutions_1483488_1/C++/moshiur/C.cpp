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

#define MAX 2000000

vector<int> all[MAX+5];

void gen(int x){
    int d[10];
    int i=0;
    int p10 = 1;
    int _x = x;

    while(x){
        p10 *= 10;
        d[i++]=x%10;
        x/=10;
    }

    reverse(d,d+i);

    int pref[10];

    for(int j=0;j<i;++j)
        if(j==0)
            pref[j] = d[j];
        else
            pref[j] = pref[j-1]*10 + d[j];

    int n = 0;

    p10/=10;
    int tmp=1;

    set<int> distinct;

    for(int j=i-1;j>0;--j){
        n += d[j]*tmp;
        tmp*=10;

        int y = n*p10 + pref[j-1];
        p10/=10;

        if(y > _x)
            distinct.insert(y);
    }

    for(set<int>::iterator it=distinct.begin();it!=distinct.end();++it)
        all[_x].push_back(*it);
}

void pre(){
    REP(i,1,MAX){
        gen(i);
    }
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C_hard_out.txt","w",stdout);

    pre();

    int T; scanf("%d",&T);

    REP(t,1,T){
        int A,B; scanf("%d%d",&A,&B);

        LL ans = 0;

        for(;A<=B;++A){
            FOR(j,all[A].size())
                if(all[A][j]<=B)
                    ++ans;
                else
                    break;
        }

        printf("Case #%d: ",t); cout<<ans<<"\n";
    }

    return 0;
}
