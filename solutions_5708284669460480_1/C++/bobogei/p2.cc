#include<bits/stdc++.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define ALL(x) x.begin(),x.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)

string kb, ip;
int K, L, S;
map<char, int> freq;

void aozora() {
    freq.clear();
}

int main() {
    IOS;
    int T;
    cin >> T;
    for(int _t=1; _t<=T; _t++) {
        aozora();
        cin >> K >> L >> S;
        cin >> kb >> ip;
        for(int i=0; i<(int)kb.length(); i++) {
            freq[kb[i]] = freq[kb[i]] + 1;
        }

        double expect = 1.0 * (S - ip.length() + 1);
        if(S >= (int)ip.length()) {
            for(int i=0; i<(int)ip.length(); i++) {
                expect *= 1.0 * freq[ip[i]] / kb.length();
            }
        } else {
            expect = 0.0;
        }

        int i = 1, len = ip.length();
        for( ; i < len; i++) {
            bool flag = true;
            for(int j=0; j+i<len; j++) {
                if(ip[i+j] != ip[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        int maxi = (S - len) / i + 1;
        for(int j=0; j<len; j++) {
            if(!freq[ip[j]]) {
                maxi = 0; break;
            }
        }
        cout << fixed << setprecision(10) << "Case #" << _t << ": " << (double)maxi - expect << endl;
    }
	return 0;
}

