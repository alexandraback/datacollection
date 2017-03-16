#include <bits/stdc++.h>

using namespace std;

map<int,int> save;
int maxi = 0;



int count(int x, int n, int profondeur) {

    if (x == n) {
        if (profondeur <= maxi) maxi = profondeur;
        return profondeur;
    }

    if (profondeur > maxi) return maxi;

    auto it = save.find(x);
    if (it != save.end()) {
        if (profondeur > save[x]) return save[x];
    }


    // calcul
    ostringstream o;
    o << x;
    string str = o.str();

    reverse(str.begin(), str.end());
    istringstream es(str);
    int y = 0;
    es >> y;

    int res = 0;

    if (y <= n && y > (x+1)) {
        res = min(count(y,n, profondeur + 1), res);
    }

    res = count(x+1,n, profondeur + 1);



    // resultat
    if (it != save.end()) {
        save[x] = min(save[x], res);
    } else {
        save[x] = res;
    }

    return res;
}

int solve() {

    int n;
    cin >> n;

    istringstream is;


    int data[n];
    for (int i = 0; i < n; ++i) data[i] = numeric_limits<int>::max();
    int y;

    data[0] = 1;
    string str;

    int res = 0;
    for (int i = 1; i < n; ++i) {
        ostringstream os;
        os << i;
        str.clear();
        str = os.str();
        reverse(str.begin(), str.end());
        istringstream(str) >> y;


        res = data[i-1]+1;

        if (y < n) {
            data[y] = min(data[y], data[i-1]+2);
        }

        data[i] = min(res,data[i]);
    }


    return data[n-1];
}

int main() {

    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int res = solve();
        cout << "Case #" << (i+1) << ": " << res << endl;
    }

}