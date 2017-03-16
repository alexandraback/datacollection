#include <bits/stdc++.h>
using namespace std;
int res=0;
int n;
set<string> fir,sec;
string str[20][2];
bool mark[20];
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for (int run=1;run<=cas;++run)
    {
        scanf("%d",&n);
        for (int i=0;i<n;++i)
            cin>>str[i][0]>>str[i][1];
        int res=0;
        for (int mask=1;mask<1<<n;++mask)
        {
            fir.clear();
            sec.clear();
            int num=0;
            for (int i=0,t=mask;i<n;++i)
            {
                mark[i]=t&1;
                t>>=1;
                if (mark[i])
                {
                    fir.insert(str[i][0]);
                    sec.insert(str[i][1]);
                }
                else
                    ++num;
            }
            bool ok=true;
            for (int i=0;i<n;++i)
                if (!mark[i]&&(fir.count(str[i][0])==0||sec.count(str[i][1])==0))
                    ok=false;
            if (ok&&num>res) res=num;
        }
        printf("Case #%d: %d\n",run,res);
    }
    return 0;
}
