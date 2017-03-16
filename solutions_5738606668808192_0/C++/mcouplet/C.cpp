#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T, N, J;

ll divisor(ll n) {
    for(ll i = 2; i*i <= n; ++i)
        if(n % i == 0)
            return i;
    return -1;
}

ll to_base_10(string s, int b) {
    ll n = 0;
    ll m = 1;
    for(int i = 0; i < s.size(); ++i) {
        n += m * (s[i] - '0');
        m *= b;
    }
    return n;
}

string from_base_10(ll n, int b) {
    string s = "";
    while(n) {
        s += ('0' + (n%b));
        n /= b;
    }
    return s;
}

void complete_search(string s) {
    if(J == 0) return;
    else if(s.size() == N-2) {
        // cout << s << endl;
        string S = '1' + s + '1';

        vector<ll> divs;
        for(int b = 2; b <= 10; ++b) {
            ll d = divisor(to_base_10(S, b));
            if(d == -1)
                break;
            divs.push_back(d);

            if(divs.size() == 9) {
                reverse(S.begin(), S.end());
                cout << S;
                for(int i = 0; i < divs.size(); ++i)
                    printf(" %lld", divs[i]);
                printf("\n");
                --J;
            }
        }
    } else {
        complete_search(s + '1');
        complete_search(s + '0');
    }
}

int main() {
    scanf("%d", &T);
    for(int t = 0; t < T; ++t) {
        printf("Case #%d:\n", t+1);
        scanf("%d%d", &N, &J);

        complete_search("");

        /*
        for(ll n = (1L << (N-2))-1; n >= 0 && J; --n) {
            string s = '1' + from_base_10(n, 2) + '1';
            cout << s << endl;
            
            vector<ll> divs;
            for(int b = 2; b <= 10; ++b) {
                // printf("%lld\n", to_base_10(s, b));
                ll d = divisor(to_base_10(s, b));
                if(d == -1)
                    break;
                divs.push_back(d);
            }
            
            if(divs.size() == 9) {
                reverse(s.begin(), s.end());
                cout << s;
                for(int i = 0; i < divs.size(); ++i)
                    printf(" %lld", divs[i]);
                --J;
            }
        }
        */
    }
}

