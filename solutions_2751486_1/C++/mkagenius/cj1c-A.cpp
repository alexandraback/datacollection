#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
bool conso(char x){
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x=='u') return false;
    return true;
}
int main(){
    freopen("AL.in", "r", stdin);
    freopen("AL.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        string s;
        cin >> s;
        int L;
        cin >> L;

        int n = s.size();
        long long ans = 0;
        long long cnt_of_cont_consonants = 0;
        long long ind = -1;
        for(int i = 0; i < n; i++){
            if(conso(s[i])){
                cnt_of_cont_consonants += 1;
            }else cnt_of_cont_consonants = 0;

            if(cnt_of_cont_consonants >= L){
                ind = i;
            }

            if(ind >= 0){
                ans += (ind - (L-1) + 1);
            }
        }
        cout  << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
