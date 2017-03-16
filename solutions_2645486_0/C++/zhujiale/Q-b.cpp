#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int T,t;
int E,r,n,a[10100];

int max(int a, int b)
{
    if (a>b) return a;
    return b;
}

int work(int x, int e)
{
    int ans = 0;
    if (x>n) return 0;
    if (x>1){
        if (e+r<=E) e += r;
        else e=E;
    }
    for (int i = 0; i<=e; i++){
        ans = max(ans,i*a[x]+work(x+1,e-i));
    }
    return ans;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    cin>>T;
    while (t<T){
        int ans;
        t++;
        cin>>E>>r>>n;
        for (int i = 1; i<=n; i++) cin>>a[i];
        ans = work(1,E);
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
