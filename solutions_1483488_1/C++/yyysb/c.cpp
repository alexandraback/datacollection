#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int a[2010000][10],T,A,B;
int main(){
    freopen("C-large.in","r",stdin);
    freopen("c.out","w",stdout);
    for(int i=1; i<=2000000; ++i){
        int t = i,p = i,r=1;
        while(p/10>0){ p/=10;r*=10;}
        for(int j=1; j<=9; ++j){
            t = t/10 + t%10*r;
            if(t>i)
                a[i][j] = t;
            else a[i][j] = 2010000;
        }
        sort(&a[i][1],&a[i][10]);
        a[i][0] = unique(&a[i][1],&a[i][10]) - &a[i][1];
        while( a[i][0]>0 && a[i][a[i][0]]==2010000) --a[i][0];
    }
    cin>>T;
    for(int cs=1; cs<=T; ++cs){
        cin>>A>>B;
        long long ans=0;
        for(int i=A; i<B; ++i)
            for(int j=a[i][0]; j>0; --j)
                if(a[i][j]<=B){
                    ans+=j;
                    break;
                }
        cout<<"Case #"<<cs<<": "<<ans<<endl;
    }

    return 0;
}
