#include<bits/stdc++.h>
using namespace std;

int t;
int n;
string s;

int main(){
    ofstream jwb;
    jwb.open("Standing Ovation.txt");

    cin >> t;
    for (int tc=1; tc<=t; tc++){
        cin >> n >> s;
        int stand = 0;
        int ans = 0;
        for (int i=0; i<=n; i++){
            if (stand < i){
                ans += i - stand;
                stand = i;
            }
            stand += s[i] - '0';
        }
        jwb << "Case #" << tc << ": " << ans << endl;
    }

    jwb.close();
    return 0;
}
