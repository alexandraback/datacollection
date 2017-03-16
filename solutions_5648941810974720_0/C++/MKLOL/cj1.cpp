#include<bits/stdc++.h>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int N,M;
string dig[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[4400];
int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        string s;
        cin >> s;
        map<char,int> h;
        for(auto c : s) {
                h[c]++;
        }
        for(int i=0;i<=300;++i) cnt[i]=0;
        for(auto c : s) {
            if(c == 'Z') {
                ++cnt[0];
                for(auto mc : dig[0])
                    --h[mc];
            }
            if(c == 'W') {
                ++cnt[2];
                for(auto mc : dig[2])
                    --h[mc];
            }
            if(c == 'U') {
                ++cnt[4];
                for(auto mc : dig[4])
                    --h[mc];
            }
            if(c == 'X') {
                ++cnt[6];
                for(auto mc : dig[6])
                    --h[mc];
            }
            if(c == 'G') {
                ++cnt[8];
                for(auto mc : dig[8])
                    --h[mc];
            }
        }
        for(auto c : h) {
            if(c.fs == 'O') {
                cnt[1] += c.sc;
                for(auto mc : dig[1])
                    h[mc]-=c.sc;
            }
            if(c.fs == 'H') {
                cnt[3] += c.sc;
                for(auto mc : dig[3])
                    h[mc]-=c.sc;
            }
            if(c.fs == 'F') {
                cnt[5] += c.sc;
                for(auto mc : dig[5])
                    h[mc]-=c.sc;
            }
            if(c.fs == 'S') {
                cnt[7] += c.sc;
                for(auto mc : dig[7])
                    h[mc]-=c.sc;
            }
        }
        cnt[9] += h['I'];

        printf("Case #%d: ",tt);
        for(int i=0;i<=9;++i) {
            for(int j=1;j<=cnt[i];++j){
                printf("%d",i);
            }
        }
        cout << endl;
    }
}
