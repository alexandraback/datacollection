#include<bits/stdc++.h>

using namespace std;

int lft, rght;
int T;
int N;
string A, B;
map<string, int> map1;
map<string, int> map2;
bool mat[1010][1010];
int ans;
bool v[1010];
int lnk[1010];
int pnt[1010];

bool find(int x) {
    for(int i=1;i<=rght;i++) {
        if(mat[x][i] && !v[i]) {
            v[i]=1;
            if(lnk[i]==0 || find(lnk[i])) {
                lnk[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> N;
        map1.clear();
        map2.clear();
        lft = rght = 0;
        ans = 0;
        memset(mat, 0, sizeof(mat));
        memset(lnk, 0, sizeof(lnk));
        memset(pnt, 0, sizeof(pnt));
        for(int i = 0;i < N;i ++) {
            cin >> A >> B;
            if (map1.find(A) == map1.end()) {
                map1[A] = ++lft;
            }
            if (map2.find(B) == map2.end()) {
                map2[B] = ++rght;
            }
            mat[map1[A]][map2[B]] = 1;
        }
        for(int i=1;i<=lft;i++) {
            memset(v,0,sizeof(v));
            if(find(i)) ans++;
        }
        for(int i = 1;i <= rght;i ++) {
            if (lnk[i] == 0) ans ++;
            else pnt[lnk[i]] = i;
        }
        for(int i = 1;i <= lft;i ++) {
            if (pnt[i] == 0) ans ++;
        }
        cout << "Case #" << testcase << ": " << N - ans << endl;
    }
    return 0;
}
