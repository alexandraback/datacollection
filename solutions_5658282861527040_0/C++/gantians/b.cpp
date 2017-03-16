#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int t,n;
int a,b,k;
vector<int> num[110];
vector<char> v[110];
string s[110];

int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    cin >> t;
    for (int ti=1;ti<=t;ti++){
        scanf("%d%d%d",&a,&b,&k);
        
        long long ans=0;
        for (int i=0;i<a;i++)
            for (int j=0;j<b;j++)
                if ((i&j)<k) ans++;
        cout << "Case #"<<ti<<": "<<ans<<endl;
    }
    //system("pause");
    return 0;
}
