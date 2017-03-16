#include <iostream>

typedef long long ll;

ll reverse(ll a) {
    ll b = 0ll;
    while (a) {
        b = b*10ll + a%10ll;
        a /= 10ll;
    }
    return b;
}

bool palin(ll a) {
    return a == reverse(a);
}

ll create_palin(ll a, bool odd) {
    ll tmp = a;
    if (odd) tmp /= 10ll;
    while (tmp) {
        a = a*10ll + tmp % 10ll;
        tmp /= 10ll;
    }
    return a;
}

ll sqr(ll a) {
    return a*a;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        ll a, b;
        std::cin >> a >> b;
        int ans = 0;

        ll i = 0ll, cur;
        while (sqr(create_palin(i, 0)) < a) i++;
        while ((cur = sqr(create_palin(i, 0))) <= b) {
            if (palin(cur)) {
                //std::cout << cur << std::endl;
                ans++;
            }
            i++;
        }
        
        i = 0ll;
        while (sqr(create_palin(i, 1)) < a) i++;
        while ((cur = sqr(create_palin(i, 1))) <= b) {
            if (palin(cur)) {
                //std::cout << cur << std::endl;
                ans++;
            }
            i++;
        }

        std::cout << "Case #" << t << ": " << ans << std::endl;
    }
}
