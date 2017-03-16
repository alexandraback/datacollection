#include <iostream>
#include <cstdio>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,N) for(int i=0;i<N;i++)

using namespace std;
string s;
int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("result.out","w",stdout);
    int t;
    cin >> t;
    foru(test,1,t) {
        int res=0;
        int smax;
        cin >> smax;
        cin >> s;
        int dem=0;
        REP(i,s.size()) {
            if (i<=dem) dem+=s[i]-'0';
            else {
                res++;
                dem+=s[i]-'0'+1;
            }
        }
        cout << "Case #" << test << ": " << res << endl;
    }
}
