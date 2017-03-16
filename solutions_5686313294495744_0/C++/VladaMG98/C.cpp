#include <bits/stdc++.h>
using namespace std;
string a[16],b[16];
set<string> A,B;
int main()
{
    freopen("C.txt","r",stdin);
    freopen("Cout.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        fprintf(stderr,"LALA\n");
        printf("Case #%d: ",tt);
        int n;
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i] >> b[i];
        int MASK;
        int best=0;
        for(MASK=0;MASK<(1<<n);MASK++)
        {
            A.clear();
            B.clear();
            vector<int> tryfake;
            for(int i=0;i<n;i++)
            {
                if(MASK&(1<<i))
                {
                    A.insert(a[i]);
                    B.insert(b[i]);
                }
                else tryfake.push_back(i);
            }
            if(best>tryfake.size()) continue;
            int ans=0;
            for(int i=0;i<tryfake.size();i++)
            {
                if(A.find(a[tryfake[i]])!=A.end()&&B.find(b[tryfake[i]])!=B.end()) ans++;
            }
            best=max(best,ans);
        }
        printf("%d\n",best);
    }
}
