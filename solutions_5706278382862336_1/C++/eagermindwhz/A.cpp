#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
char s;
long long p,q;
long long gcd(long long a,long long b){
    if (b==0)return a;
    else return gcd(b, a%b);
}
int main()
{
    freopen("A2.in","r",stdin);
    freopen("A2.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        cin>>p>>s>>q;
        //cout<<p<<' '<<q;
        long long g = gcd(p,q);
        p = p/g; q = q/g;
        long long t = (q & (-q));
        cout<<"Case #"<<cas<<": ";
        if (p>q || t != q) cout<<"impossible"<<endl;
        else {
            int len = 0;t = 1;
            while (t!=q){
                len++;
                t = (long long)1<<len;
            }
            int ans = 0;
            long long p1;
            while(true){
                p1 = (long long)1<<(len-ans);
                if (p1<=p) break;
                ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
