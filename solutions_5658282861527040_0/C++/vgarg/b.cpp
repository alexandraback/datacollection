#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int t, T, a,b,c,k;
    cin >> T;
    for (t=1;t<=T;t++){
        cin>>a>>b>>k;
        c=0;
        for (int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if((i&j)<k)c++;
            }
        }
        cout << "Case #" <<t<<": "<<c<<"\n";
    }
}
