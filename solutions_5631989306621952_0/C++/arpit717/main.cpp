#include <bits/stdc++.h>

using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define pull(x) printf("%llu",x)
#define pll(x) printf("%lld",x)

#define pn() printf("\n")
#define loop(i, a, b) for (int i = int(a); i < int(b); i++)
#define MAXN 1000005
typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
freopen("A-small-attempt0.in","r",stdin);
freopen("out0_small.txt","w",stdout);

    int l,t,n;
    string s;
    list<char> ans;
    sd(t);
    loop(k,1,t+1){
        cin>>s;
        cout<<"Case #"<<k<<": ";
        n=s.size();
        l=0;
        loop(i,0,n){
            if(i==0)ans.push_back(s[i]);
            else{
                if(s[i]>=ans.back())ans.push_back(s[i]);
                else ans.push_front(s[i]);
            }
        }
        while(!ans.empty()){
            cout<<ans.back();
            ans.pop_back();
        }
        cout<<endl;
    }





    return 0;
}


