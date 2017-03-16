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
    freopen("csmall.in","r",stdin);
    freopen("cout.out","w",stdout);

int t;
cin>>t;
FOR(test,1,t)
{
    int n;
    cin>>n;

    int a[n];

    REP(i,n)
        cin>>a[i];
    printf("Case #%d:\n",test);
    int limit = 1<<20;

    map<int,vector< vector <int> > > m;
    bool flag = false;
    for (int i=1;i<limit;i++)
    {
        int sum = 0;
        vector <int> temp;
        for (int j=1,k=0;j<limit;j<<=1,k++)
        {
            if (i&j)
            {
                sum += a[k];
                temp.PB(a[k]);
            }
        }

        if (m[sum].size())
        {
            flag = true;
            int pos;
            REP(l,m[sum].size())
            {

                REP(k,m[sum][l].size())
                {
                    vector<int>::iterator it = find(temp.begin(),temp.end(),m[sum][l][k]);
                    if (it!=temp.end())
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    pos = l;
                    break;
                }

            }

            if (flag)
            {
                REP(k,m[sum][pos].size())
                {
                    cout<<m[sum][pos][k]<<' ';
                }
                cout<<endl;
                REP(k,temp.size())
                {
                    cout<<temp[k]<<' ';
                }
                cout<<endl;
            }
            else
            m[sum].PB(temp);
        }
        else
            m[sum].PB(temp);

        if (flag)
        break;
    }
    if (!flag)
    cout<<"Impossible\n";
}

return 0;
}
