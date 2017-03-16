#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define p 1000000007
#define pb push_back
#define mp make_pair
typedef long long Int;
typedef pair<Int,Int> pii;
typedef vector<Int> vi;
typedef vector<pii> vii;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    Int T;
    cin>>T;
    for (Int k=1;k<=T;++k)
    {
        Int N,x;
        vector<Int>V;
        map<Int,Int>Map;
        cin>>N;
        for (Int i=1;i<=2*N-1;++i)
        {
            for (Int j=0;j<N;++j)
            {
                cin>>x;
                Map[x]++;
            }
        }
        map<Int,Int>::iterator it;
        for (it=Map.begin();it!=Map.end();++it)
        {
            if ((it->sc)%2)
                V.pb(it->fs);
        }
        sort(V.begin(),V.end());
        cout<<"Case #"<<k<<": ";
        for (Int i=0;i<V.size();++i)
            cout<<V[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
