//                                                  به نام خداوند بخشنده ی مهربان
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <complex>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

# define xx first
# define yy second
# define pb push_back
# define pp pop_back
# define eps 1e-9
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
int a,b,k;
int main(){
    ios_base::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int t;cin>>t;
    for(int q=1 ; q<=t ; q++){
        cin>>a>>b>>k;
        int ans=0;
        cout<<"Case #"<<q<<": ";
        for(int i=0 ; i<a ; i++)
            for(int j=0 ; j<b ; j++)
                if((i&j)<k)
                    ans++;
        cout<<ans<<endl;
    }
    return 0;
}
