#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int t,n,m;
int a[1000],b[1000];
vector<int> num[110];
vector<char> v[110];
string s[110];

int main(){
    freopen("A-small-attempt0 (2).in","r",stdin);
    freopen("1.out","w",stdout);
    cin >> t;
    for (int ti=1;ti<=t;ti++){
        char c;
        scanf("%d%c%d",&n,&c,&m);
        int gcd = __gcd(n,m);
        n/=gcd;
        m/=gcd;
        int flag=1;
        int x=m;
        int ans=0;
        while (x%2==0){ x/=2;ans++;}
        cout << "Case #"<<ti<<": ";
        long long y=1;
        while (ans>1 && y*2<=(long long)n){
              ans--;
              y*=2;
        }
        if (x!=1) cout<<"impossible"<<endl;
           else cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
