#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mp make_pair
using namespace std;

string one , two;
int minD , on , tw;
string ans1 , ans2;

void solve(string t , string tt , int k){

    if(k == t.length()){

        int tmp1 = atoi(t.c_str());
        int tmp2 = atoi(tt.c_str());

        if(minD > abs(tmp1 - tmp2)){
            minD = abs(tmp1 - tmp2);
            ans1 = t;
            ans2 = tt;
            on = tmp1;
            tw = tmp2;
            return;

        }

        if(minD == abs(tmp1 - tmp2)){
            if(tmp1 < on){
                ans1 = t;
                ans2 = tt;
                on = tmp1;
                tw = tmp2;
                return;
            }

             if(tmp1 == on){

                if(tmp2 < tw){
                    ans1 = t;
                    ans2 = tt;
                    tw = tmp2;
                    on = tmp1;
                    return;
                }
            }

            return;
        }

        return;

    }

    for(int i = 0; i < 10; ++i){

        for(int j = 0; j < 10; ++j){
            string p1 = t;
            string p2 = tt;
            if(t[k] == '?'){
                p1[k] = '0' + i;
            }

            if(tt[k] == '?'){
                p2[k] = '0' + j;
            }

            solve(p1 , p2 , k+1);

        }

    }

}


int main(){

    freopen("B-small-attempt0.in" , "r" , stdin);
    freopen("dream.out" , "w" , stdout);
    int t , z = 1;
    cin >> t;
    while(t--){
        minD = 1e9;
        on = 1e9;
        tw = 1e9;
        printf("Case #%d: " , z++);
        cin >> one >> two;
        solve(one , two , 0);
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
