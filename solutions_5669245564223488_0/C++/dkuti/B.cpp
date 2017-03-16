#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
const int M = (int)(1e9+7);
int id[11];
int pos[26];

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("Bout.txt", "w", stdout);
    int T, n;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        cin >> n;
        vector<string> cars;
        for(int i = 0; i < n; ++i){
            string car;
            cin >> car;
            cars.push_back(car);
            id[i] = i;
        }

        ll ans = 0;
        do{
            bool ok = true;
            string t = "";
            for(int i = 0; i < n; ++i){
                t += cars[id[i]];
            }

            fill(pos, pos+26, -2);
            for(int i = 0; i < t.length(); ++i){
                if(pos[t[i]-'a'] == -2) pos[t[i]-'a'] = i;
                else if((pos[t[i]-'a'] + 1) != i) {
                    ok = false;
                    break;
                } else{
                    pos[t[i]-'a'] = i;
                }
            }

            if(ok) ++ans;
        } while(next_permutation(id,id+n));


        cout << "Case #" << t << ": " << ans;
        if(t < T) cout << "\n";
    }
    return 0;
}
