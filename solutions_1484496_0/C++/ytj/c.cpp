#include<unordered_map>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int s[1 << 20];
int n;
void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[1 << i];

}

void output(int i) {
    bool fb=true;
    while (i) {
        int lb = i & -i;
        i -= lb;
        if(not fb) cout << " ";
        fb=false;
        cout << s[lb];
    }
    cout << endl;
}

void work() {
    unordered_multimap<int, int> d;
    s[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        int lb = i & -i;
        if (i != lb)
            s[i] = s[i - lb] + s[lb];
    }
    for (int i = 1; i < (1 << n); i++)
        d.emplace(s[i], i);
    for (int i = 0; i < (1 << n); i++) {
        auto p = d.equal_range(s[i]);
        for (auto it = p.first; it != p.second; ++it) {
            auto u = *it;
            if ((u.second & i) == 0) {
                output(i);
                output(u.second);
                return;
            }
        }
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        memset(s,0,sizeof(s));
        cout << "Case #" << i << ":\n" ;
        input();
        work();
    }

}
