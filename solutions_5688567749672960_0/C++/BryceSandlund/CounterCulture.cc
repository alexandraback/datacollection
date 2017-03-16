#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long long ll;

bool stable(string N) {
    if (N[0] != '1')
        return false;
    for (ll i = 1; i < N.size()/2; ++i) {
        if (N[i] != '0')
            return false;
    }
    return true;
}

bool corner(string N) {
    for (ll i = N.size()/2; i < N.size(); ++i) {
        if (N[i] != '0')
            return false;
    }
    return true;
}

ll solve(string N) {
    cerr << N << endl;
    
    if (N.size() == 1) {
        return atoll(N.c_str());
    }
    else if (stable(N)) {
        string pred(N.size()-1, '9');

        ll cont = atoll(N.c_str()) - atoll(pred.c_str());
        return cont + solve(pred);
    }
    else if (corner(N)) {
        ll Nm1 = atoll(N.c_str());
        --Nm1;
        stringstream ss;
        ss << Nm1;
        string Nm1Str;
        ss >> Nm1Str;
        return solve(Nm1Str)+1;
    }
    else {
        string pred(N.size(), '0');
        pred[0] = '1';

        for (ll i = pred.size()-1; i > (pred.size()-1)/2; --i) {
            pred[i] = N[N.size()-i-1];
        }

        string predR(pred.rbegin(), pred.rend());
        ll cont = atoll(N.c_str()) - atoll(predR.c_str()) + 1;
        return cont + solve(pred);
    }
}

int main() {
    ll T;
    cin >> T;
    for (ll cs = 1; cs <= T; ++cs) {
        string N;
        cin >> N;

        printf("Case #%lld: %lld\n", cs, solve(N));
    }
    return 0;
}
