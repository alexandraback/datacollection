#include <iostream>
#include <algorithm>
using namespace std;
int n;
string arr[100];
int all[100];
vector<char> vec;
vector<int> pos;
int ans;
bool succ;
void getMin() {
    int meAns = 1000000000;
    for (int qq = 1; qq <= 100; qq++) {
        int now = 0;
        for (int i = 0; i < n; i++) {
            now += abs(qq - all[i]);
        }
        meAns = min(meAns, now);
    }
    ans += meAns;
}
void proc(int le) {
    char lett = vec[le];
    for (int i = 0; i < n; i++) {
        int idx = pos[i];
        if (idx >= arr[i].size() || arr[i][idx] != lett) {
            succ = false;
            return;
        }
        int hwm = 1;
        while (idx + 1 < arr[i].size() && arr[i][idx + 1] == lett) {
            idx++;
            hwm++;
        }
        all[i] = hwm;
        idx++;
        pos[i] = idx;
    }
    getMin();
}
int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for (int test = 1; test <= t; test++) {
        vec.clear();
        pos.clear();
        ans = 0;
        succ = true;
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
            pos.push_back(0);
        }
        vec.push_back(arr[0][0]);
        for (int i = 1; i < arr[0].size(); i++) {
            if (arr[0][i] != arr[0][i - 1]) {
                vec.push_back(arr[0][i]);
            }
        }
        for (int i = 0; i < vec.size(); i++) {
            proc(i);
        }
        for (int i = 0; i < n; i++) {
            if (pos[i] != arr[i].size()) {
                succ = false;
            }
        }
        cout<<"Case #"<<test<<": ";
        if (succ) {
            cout<<ans<<"\n";
        } else {
            cout<<"Fegla Won\n";
        }
    }
    return 0;
}
