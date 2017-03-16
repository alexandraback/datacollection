#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<locale>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(a) (int((a).size()))
typedef istringstream iss; typedef ostringstream oss; typedef long long lli;
const double TOLL=1e-9;
int scored[2000],N;
int A[2000],B[2000];

map<vector<int>,int> memo;

int recur(vector<int> v)
{
    int star=v[N]; if(star>2100) star=2010; v[N]=star;
    if(memo.count(v)) return memo[v];
    int rv=100000000; int cnt=0;
    for(int i=0;i<N;i++)
    {
        if(v[i]<2)
        {
            cnt++;

            if(star>=B[i])
            {
                int now=v[i];
                v[i]=2;
                v[N]=min(star+2-now,2010);
                rv=min(rv,recur(v)+1);
                v[i]=now; v[N]=star;
            }
            else if(star>=A[i] && v[i]==0)
            {
                int now=v[i];
                v[i]=1;
                v[N]=min(star+1,2010);
                rv=min(rv,recur(v)+1);
                v[i]=now; v[N]=star;
            }
        }
    }
    if(cnt==0) return 0;
    return memo[v]=rv;

}

int main()
{
    int T; cin>>T; int cn=0;
    while(T--)
    {
        cin>>N; for(int i=0;i<N;i++) cin>>A[i]>>B[i];
        vector<int> v; memo.clear();
        for(int i=0;i<=N;i++) v.push_back(0);
        int rv=recur(v);
        printf("Case #%d: ",++cn);
        if(rv<100000000) printf("%d\n",rv);
        else printf("Too Bad\n");

    }

}



/*
for(int i=0;i<N;i++) for(int j=i+1;j<N;j++)
        {
            if(B[j]<B[i] ||(B[j]==B[i] && A[j]<A[i]))
            {
                swap(A[i],A[j]); swap(B[i],B[j]);
            }
        }
        memset(scored,0,sizeof scored);
        bool competing=true; int rv=0; int myStar=0;
        while(competing)
        {
            competing=false;
            for(int i=0;i<N;i++)
            {
                if(scored[i]>=2) continue;
                else if(scored[i]==0)
                {
                    if(myStar>=B[i])
                    {
                        myStar+=2;
                        scored[i]=2;
                        competing=true;
                    }
                    else if(myStar>=A[i])
                    {
                        myStar+=1;
                        scored[i]=1;
                        competing=true;
                    }
                }
                else if(scored[i]==1)
                {
                    if(myStar>=B[i])
                    {
                        myStar+=1;
                        scored[i]=2;
                        competing=true;
                    }
                }
            }
        }
        */
