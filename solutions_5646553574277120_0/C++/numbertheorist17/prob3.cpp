#include <bits/stdc++.h>
#define MAX_VAL 35
using namespace std;

int t, c, d, v;
vector<int> arr;
bool val[MAX_VAL];

void update_val() {
    memset(val,false,sizeof(val));
    val[0]=true;
    for (int i=1; i<(1 << (int)arr.size()); i++) {
        int tot=0;
        for (int j=0; j<(int)arr.size(); j++) if (i & (1 << j)) tot+=arr[j];
        if (tot<=v) val[tot]=true;
    }
}

bool check_done() {
    for (int i=0; i<=v; i++) {
        if (!val[i]) return false;
    }
    return true;
}

bool contains(int asdf) {
    for (int i=0; i<(int)arr.size(); i++) {
        if (asdf==arr[i]) return true;
    }
    return false;
}

int solve(int num, int ind, int low) {
    if (ind==num) {
        update_val();
        if (check_done()) return num;
        return -1;
    }
    int ret=-1;
    for (int i=low+1; i<=v && ret==-1; i++) {
        if (!contains(i)) {
            arr.push_back(i);
            int k=solve(num,ind+1,i);
            if (k!=-1) ret=k;
            arr.erase(arr.end()-1);
        }
    }
    return ret;
}

int main(void) {
    if (fopen("c-small2.in","r")) {
        freopen("c-small2.in","r",stdin);
        freopen("c-small2.out","w",stdout);
    }
    cin >> t;
    for (int ii=1; ii<=t; ii++) {
        arr=vector<int>();
        memset(val,false,sizeof(val));
        cin >> c >> d >> v;
        for (int i=0; i<d; i++) {
            int k; cin >> k; arr.push_back(k);
        }
        cout << "Case #" << ii << ": ";
        if (solve(0,0,0)!=-1) cout << "0\n";
        else if (solve(1,0,0)!=-1) cout << "1\n";
        else if (solve(2,0,0)!=-1) cout << "2\n";
        else if (solve(3,0,0)!=-1) cout << "3\n";
        else if (solve(4,0,0)!=-1) cout << "4\n";
        else cout << "5\n";
    }
    return 0;
}
