#include<bits/stdc++.h>
using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define sl(n)                       scanf("%ld",&n)
#define sll(n)                      scanf("%lld",&n)
#define sllu(n)                     scanf("%llu",&n)
#define p(n)						printf("%d\n",n)
#define pl(n)						printf("%ld\n",n)
#define pll(n)						printf("%lld\n",n)
#define pllu(n)						printf("%llu\n",n)

typedef long long int ll;

FILE *fin=freopen("B-large (1).in","r",stdin);
FILE *fout=freopen("2_large.txt","w",stdout);

int main()
{
    int t;s(t);
    for(int i=1;i<=t;i++)
    {
        int n;s(n);
        int a[(2*n)-1][n];
        for(int x=0;x<(2*n)-1;x++)
        {
            for(int y=0;y<n;y++)
            {
                s(a[x][y]);
            }
        }
        map<int,int> m;
        for(int x=0;x<(2*n)-1;x++)
        {
            for(int y=0;y<n;y++)
            {
                 if(m.find(a[x][y]) == m.end())
                 {
                     m[a[x][y]]=1;
                 }
                 else
                 {
                     m[a[x][y]]++;
                 }
            }
        }
        vector<int> v;

         for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
               {
                   //cout << it->first << " => " << it->second << '\n';
                   if(it->second &1)
                   {
                       v.push_back(it->first);
                   }
               }

        sort(v.begin(),v.end());
        cout<<"Case #"<<i<<":";
        for(int x=0;x<v.size();x++)
            cout<<" "<<v[x];
        cout<<"\n";

        //printf("Case #%d: %@\n",i,@);
    }
}

