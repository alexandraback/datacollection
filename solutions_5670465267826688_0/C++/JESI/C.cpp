#include <bits/stdc++.h>

using namespace  std;

#define sz(x) (int)x.size()
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pci = pair <char , int>;

#define SZ 10000+10

pci f (char a, char b) {
    if (a == '1') {
        return {b, 1};
    } else if (a == 'i') {
        if (b == '1') return {'i', 1};
        else if (b == 'i') return {'1', -1};
        else if (b == 'j') return {'k', 1};
        else return {'j', -1};
    } else if (a == 'j') {
        if (b == '1') return {'j', 1};
        else if (b == 'i') return {'k', -1};
        else if (b == 'j') return {'1', -1};
        else return {'i', 1};
    } else {
        if (b == '1') return {'k', 1};
        else if (b == 'i') return {'j', 1};
        else if (b == 'j') return {'i', -1};
        else return {'1', -1};
    }
}

pci mp[200][200];
char arr[] = {'1', 'i', 'j', 'k'};
pci sum[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mp[arr[i]][arr[j]] = f(arr[i], arr[j]);
        }
    }

    pci need[2];
    need[0] = {'i', 1};
    need[1] = {'k', 1};

    int t;
    string s;

    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int l, x;
        string tmp;

        cin >> l >> x >> tmp;

        s = "";
        for (int i = 0; i < x; i++) {
            s = s + tmp;
        }

        sum[0] = {s[0], 1};
        int k = sz(s);

        for (int i = 1; i < k; i++) {
            sum[i] = mp[sum[i-1].X][s[i]];
            sum[i].Y *= sum[i-1].Y;
        }

//        cout << "S = " << s << '\n';
//        cout << ">> X = " << sum[k-1].X << " Y = " << sum[k-1].Y << '\n';

        cout << "Case #" << cs + 1 << ": ";

        if (k >= 3 && sum[k-1] == make_pair('1', -1)) {
            int now = 0;
            for (int i = 0; i < k; i++) {
                if (sum[i] == need[now]) {
                    now++;
                    if (now == 2) {
                        break;
                    }
                }
            }
            if (now == 2) cout << "YES";
            else cout << "NO";
        } else {
            cout << "NO";
        }

        cout << '\n';
    }


    return 0;
}






