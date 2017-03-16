#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
pair<ll,ll> solve(string one, string two){
    pair<ll,ll> best;
    bool has_best = false;
    for(int a = 0; a<=9; ++a){
        for(int b=0; b<=9; ++b){
            for(int c=0; c<=9; ++c){
                for(int d=0; d<=9; ++d){
                    for(int e=0; e<=9; ++e){
                        for(int f=0; f<=9; ++f){
                          //  cout << b << " " << e << endl;
                            string one_cpy = one;
                            string two_cpy = two;
                            if(one[0] == '?'){
                                one_cpy[0] = '0' + a;
                            }
                            if(one.size() > 1 && one[1] == '?'){
                                one_cpy[1] = '0' + b;
                            }
                            if(one.size() >2 && one[2] == '?'){
                                one_cpy[2] = '0' + c;
                            }

                            if(two[0] == '?'){
                                two_cpy[0] = '0' + d;
                            }
                            if(two.size() > 1 && two[1] == '?'){
                                two_cpy[1] = '0' + e;
                            }
                            if(two.size() > 2 && two[2]=='?'){
                                two_cpy[2] = '0' + f;
                            }
                            //stringstream ss1(one_cpy);
                           // stringstream ss2(two_cpy);
                            ll res1 = atoi(one_cpy.c_str()),res2 = atoi(two_cpy.c_str());
                           // ss1 >> res1;
                            //ss2 >> res2;
                         //   if(b==9 && e==0){
                               // cout << res1 << "   " << res2 << endl;
                          //  }
                           // cout << "ASD ";
                          //  cout << one << " " << two << endl;
                           // cout << res1 << " " << res2 << endl;
                            pair<ll,ll> tmp = make_pair(res1, res2);
                            if(!has_best || abs(best.first - best.second) > abs(tmp.first - tmp.second) || (abs(best.first - best.second) == abs(tmp.first - tmp.second) && tmp.first < best.first) || (abs(best.first - best.second) == abs(tmp.first - tmp.second) && tmp.first == best.first && tmp.second < best.second)){
                                best = tmp;
                                has_best = true;
                            }

                        }
                    }
                }
            }
        }
    }
    return best;

}
int main () {
    ios_base::sync_with_stdio(false);
    freopen("C:\\in.txt","r", stdin);
    freopen("C:\\GCJ_2016_b\\out.txt","w", stdout);
    int TC;
    cin >> TC;
    int cas = 1;

    while(TC--){
         string c,j;
         cin >> c >> j;
         ll a =0, b=0;
         for(int i=0; i<c.size(); ++i){
            if(c[i] != '?'){
                a*=10;
                a+= (c[i]-'0');
            }
            if(j[i] != '?'){
                b*=10;
                b+= (j[i]-'0');
            }
            bool added = false;
            ll best_a;
            ll best_b;
            for(int d1_l=0; d1_l<=9; ++d1_l){
                for(int d2_l=0; d2_l<=9; ++d2_l){
                    ll tmp1 = a;
                    ll tmp2 = b;
                    int d1 = d1_l;
                    int d2 = d2_l;
                        if(i!=c.size()-1 && c[i+1] != '?' && j[i+1]!='?'){
                            if(c[i+1]-'0' - (j[i+1] -'0') > 5 && d1 != 0 && c[i]=='?'){
                                d1--;
                            }
                            if((j[i+1] -'0') - c[i+1]-'0'  > 5 && d1 < 9 && c[i]=='?'){
                                d1++;
                            }
                        }
                    if(c[i] == '?'){
                        tmp1*=10;
                        tmp1+= d1;
                    }
                    if(j[i] == '?'){
                        tmp2*=10;
                        tmp2+= d2;
                    }
                //    cout << "asd " << tmp1 << " " << tmp2 << endl;
                    if(!added || abs(tmp1-tmp2) < abs(best_a-best_b)){
                        added = true;




                        best_a = tmp1;
                        best_b = tmp2;
                    }
                }
            }
            if(added){

                a = best_a;
                b = best_b;
            }
         }

     //   pair<ll,ll> res = solve(c, j);
      //  a = res.first;
      //  b = res.second;

        cout << "Case #" << cas++ << ": ";
        int len_a = 0;
        ll tmp = a;
        while(tmp){
            tmp/=10;
            len_a++;
        }
        if(a==0){
            len_a++;
        }
        for(int i=0; i<c.size()-len_a; ++i){
            cout << 0;
          //  cout << " for " << cas << " " << c << " " << j << endl;
        }
        cout << a;
        cout << " ";

        len_a = 0;
        tmp = b;
        while(tmp){
            tmp/=10;
            len_a++;
        }
        if(b==0){
            len_a++;
        }
        for(int i=0; i<j.size()-len_a; ++i){
            cout << 0;
        }
        cout << b << endl;


    }
    return 0;
}
