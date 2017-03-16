#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
#define MAX 10000000

using namespace std;

bool yes[MAX+5];
vector <int> num[MAX+5];

void proses(){
    memset(yes,0,sizeof(yes));
    for(int i = 1; i <= 2000000; i++){
        if(!yes[i]){
            int temp = i;
            vector <int> wow;
            while(temp){
                wow.pb(temp % 10);
                temp /= 10;
            }
            reverse(wow.begin(),wow.end());
            int len = wow.size(), L = 0;
            for(int j = 0; j < len; j++){
                if(wow[j] == 0) continue;
                int c = 0;
                for(int k = j; k < j + len; k++){
                    c *= 10;
                    c += wow[k%len];
                }
                if(c <= 2000000){
                    bool ok = 1;
                    for(int k = 0; k < L && ok; k++)
                        if(num[i][k] == c) ok = 0;
                    if(ok) {
                        num[i].pb(c);
                        L++;
                        yes[c] = 1;
                    }
                }
            }
            for(int j = 1; j < L; j++){
                num[num[i][j]] = num[i];
            }
        }
        
    }
}

int main(){
    freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    proses();
    int T;
    cin >> T;
    for(int ts = 1; ts <= T; ts++){
        memset(yes,0,sizeof(yes));
        int A, B, ans = 0;
        cin >> A >> B;
        for(int i = A; i <= B; i++){
            if(!yes[i]) {
                int L = num[i].size(), temp = 0;
                for(int j = 0; j < L; j++){
                    if(A <= num[i][j] && num[i][j] <= B){
                        temp++;
                        yes[num[i][j]] = 1;
                    }
                }
                temp = ((temp - 1) * temp) / 2;
                ans += temp;
            }
        }
        cout << "Case #" << ts << ": " << ans << endl;
    }
    return 0;
}
