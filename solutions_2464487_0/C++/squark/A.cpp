#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

ll chk(ll r, ll t, ll n){
    t = (t/n+1)/2;
    return t>=r+n;
}

int main()
{
    #ifdef __FIO
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int _, __;
    scanf("%d", &__);
    for(_ = 1; _ <=__; _++){
        cout<<"Case #"<<_<<": ";
        ll R, T;
        ll l, r;
        cin>>R>>T;
        l = 1;
        r = T+1;
        while(r-l > 1){
            if(chk(R, T, (r+l)/2))
                l = (r+l)/2;
            else
                r = (r+l)/2;
        }
        cout<<l<<endl;
    }
    return 0;
}
