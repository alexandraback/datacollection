#include<bits/stdc++.h>

using namespace std;

typedef long long L;

L gcd(L p, L q) {
    if(q==0)
        return p;
    else
        return gcd(q, p%q);
}

L log2(L x) {
    if(x<=1)
        return 0;
    else
        return 1+log2(x/2);
}

bool check(L x) {
    if(x!=0 and x%2==0) {
        return check(x/2);
    } else {
        if(x==1)
            return true;
        else
            return false;
    }
}

L func(L p, L q) {
    if(p==1 and q==1) {
        return 0;
    } else if(p > q/2) {
        return 1;
    } else {
        return 1 + func(p,q/2);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("int.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);

    L T;
    cin>>T;

    for(L t=1; t<=T; t++) {
        L p,q;
        char ch;
        cin>>p>>ch>>q;

        L g = gcd(p,q);

        p=p/g;
        q=q/g;

        if(p!=0 && p<=q && check(q)) {
            L ans;

            ans=func(p,q);

            cout<<"Case #"<<t<<": "<<ans<<endl;
        } else {
            cout<<"Case #"<<t<<": "<<"impossible"<<endl;
        }
    }

    return 0;
}
