#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 5;
/**
int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int t, c, d, v, dd[5];

    cin >> t;
    for(int ca = 1; ca <= t; ca ++) {
        cin >> c >> d >> v;
        for(int i = 0; i < d; i ++)
            cin >> dd[i];
        cout << "Case #" << ca << ": ";
        if(v == 1) {
            if(dd[0] == 1) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else if(v <= 3) {
            if(dd[0] == 1 && dd[1] == 2) cout << 0 << endl;
            else if(dd[0] == 1 || dd[0] == 2) cout << 1 << endl;
            else cout << 2 << endl;
        }
        else if(v <= 6) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3) cnt ++;
            }
            cout << 3 - cnt << endl;
        }
        else if(v <= 10) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 4 || dd[i] == 5) cnt ++;
            }
            cout << 4 - cnt << endl;
        }
        else if(v == 11) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 5) cnt ++;
            }
            cout << 4 - cnt << endl;
        }
        else if(v <= 20) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 5 || dd[i] == 9) cnt ++;
            }
            cout << 5 - cnt << endl;
        }
        else if(v == 21) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 5 || dd[i] == 10) cnt ++;
            }
            cout << 5 - cnt << endl;
        }
        else {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 5 || dd[i] == 9 || dd[i] == 10) cnt ++;
            }
            cout << 6 - cnt << endl;
        }
    }

    return 0;
}
*/

vector<int> a;
int t, c, d, v, num[mx];;

bool dfs(int x) {
    if(x == 0) return true;
    bool res = false;
    for(int i = 0; i < a.size(); ++ i) {
        if(x >= a[i] && num[a[i]] >= 1){
            num[a[i]] --;
            res |= dfs(x - a[i]);
            num[a[i]] ++;
        }
    }
    return res;
}

int main () {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> t;
    for(int ca = 1; ca <= t; ca ++) {
        a.clear();
        cin >> c >> d >> v;
        for (int i = 0; i < d; ++ i) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
            num[tmp] = c;
        }

        for (int i = 1; i <= v; ++ i) {
            if(dfs(i));
            else {
                a.push_back(i); num[i] = c;
            }
        }
        printf("Case #%d: ", ca);
        cout << a.size() - d << endl;
    }
    return 0;
}

/**
int k, l, s;
vector <int> vec;
string keys, str, tar;

void dfs(){
    if(str.length() == s) {
        int occ = 0;
        for(int i = 0 ; str[i] ; i++) {
            int j = 0;
            while(tar[j] && str[i + j] && tar[j] == str[i+j]) {
                j++;
            }
            if(j == tar.length()) {
                occ ++;
            }
        }
        vec.push_back(occ);
        str = str.substr(0, str.length() - 1);
        return;
    }
    for(int i = 0 ; keys[i] ; i++) {
        str += keys[i];
        dfs();
    }
    str = str.substr(0, str.length() - 1);
    return;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t ; cas ++) {
        cin >> k >> l >> s;
        cin >> keys;
        cin >> tar;
        vec.clear();
        str = "";
        dfs();
        int maxv = -1;
        for(int i = 0 ; i < vec.size() ; i++)
            maxv = max(maxv, vec[i]);
        double res = 0.0;
        for(int i = 0 ; i < vec.size() ; i++)
            res += maxv - vec[i];

        printf("Case #%d: %.6f\n", cas, res / vec.size() + 1e-9);
    }
    return 0;
}
*/
