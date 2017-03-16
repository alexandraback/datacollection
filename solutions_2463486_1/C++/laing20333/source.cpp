#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
#include<cmath>
#include<memory.h>
#include<sstream>
#include<queue>
#include<time.h>

using namespace std;


typedef long long ll;

vector<ll> number;
vector<ll> pal;

bool ispa(ll num){
    char s1[101];
    sprintf(s1, "%lld", num);
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    if(s1 == s2){
        return true;
    }else return false;
}

bool issquare_of_pa(ll num){
    if(sqrt(num) * sqrt(num) == num){
        if(ispa(sqrt(num))){
            return true;
        }
    }
    return false;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.csv", "w", stdout);
    freopen("C-large-1.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll i;
    /*
    for(i=1;i<=1e7;i++){
        if(ispa(i) && issquare_of_pa(i) ){
            number.push_back(i);
        }
    }
    */
    for(i=1;i<=1e7;i++){
        if(ispa(i) ){
            pal.push_back(i);
        }
    }
    for(i=0;i<pal.size();i++){
        if( ispa(pal[i]*pal[i]) ){
            number.push_back(pal[i]*pal[i]);
        }
    }


    int ntest;
    while(cin>>ntest){
        for(int tt=1; tt<=ntest; tt++){
            ll snum,fnum;
            cin>>snum>>fnum;

            ll sidx = lower_bound(number.begin(), number.end(), snum) - number.begin();
            ll fidx = upper_bound(number.begin(), number.end(), fnum) - number.begin();
            ll ans = fidx-1 - sidx + 1;


            printf("Case #%d: ", tt);
            cout<<ans<<endl;
        }
    }
    return 0;
}
