#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int t;
long long n,m;
int a[1000],b[1000];
vector<int> num[110];
vector<char> v[110];
string s[110];

int main(){
    freopen("A-large(2).in","r",stdin);
    freopen("1.out","w",stdout);
    cin >> t;
    for (int ti=1;ti<=t;ti++){
        char c;
        //scanf("%lld%c%lld",&n,&c,&m);
        cin>>n>>c>>m;
        long long gcd = __gcd(n,m);
        n/=gcd;
        m/=gcd;
        long long x=m;
        long long ans=0;
        while (x%2==0){ x/=2;ans++;}
        cout << "Case #"<<ti<<": ";
        if (x!=1) {cout<<"impossible"<<endl;continue;}
        long long y=1;
        while (ans>1 && y*2<=(long long)n){
              ans--;
              y*=2;
        }
        
          cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
