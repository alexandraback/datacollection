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
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    Int T;
    cin>>T;
    for (Int k=1;k<=T;++k)
    {
        Int maxm=0;
        string A,B;
        cin>>A;
        for (Int i=0;i<A.size();++i)
        {
            if (A[i]>=maxm)
            {
                B=A[i]+B;
                maxm=A[i];
            }
            else
                B.pb(A[i]);
        }
        cout<<"Case #"<<k<<": ";
        cout<<B<<"\n";
    }
    return 0;
}
