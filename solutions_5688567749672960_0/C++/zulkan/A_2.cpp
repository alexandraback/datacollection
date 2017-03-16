#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll reverse(ll v);
bool mengecil(ll v) {
    if(v < 10) return false;
    ll ori = v;
    vector<int> gg;

    while(v > 0) {
        gg.push_back(v%10);

        v/=10;
    }

    for(int i =0 ; i < (int) gg.size()-1; i++) {
        if(gg[i] >= gg[i+1]) {
            return false;
        }
    }

    ll next = reverse(ori);
    int dg = 0;
    while(next > 0) {
        next/=10;
        dg++;
    }
    if(dg!=(int)gg.size()) return false;
    return true;

}
ll reverse(ll v) {
    ll re = 0;
    vector<int> gg;
    while(v > 0) {
        gg.push_back(v%10);
        v/=10;
    }

    for(int i =0 ; i <(int) gg.size(); i++) {
        re*=10;
        re+=gg[i];
    }
    return re;
}
int digit(int v) {
    int a = 0;
    while(v) {
        v/=10;
        a++;
    }
    return a;
}

void solve() {
    ll v;
    cin >> v;

    ll o =0;

    while(v) {
        bool st = mengecil(v);
        if(!st) {
            o++;
            v--;
        } else {
            ll next = reverse(v);
            if(next < v) {
                o++;
                v = next;
            }
        }

        //cout << "SEKARANG " << v << '\n';
    }
    cout << o << '\n';


}
int memo[1000*1000 + 5];
void precomp() {

    memset(memo,-1,sizeof(memo));
    queue<pair<int,int> > Q;

    Q.push(make_pair(1,1));

    memo[1] = 1;



    while(Q.size()) {

        pair<int,int> t = Q.front();
        Q.pop();

        int v = t.first, l = t.second;
        if(v+1 <= 1000*1000 && memo[v+1]==-1) {
            memo[v+1] = l+1;
            Q.push(make_pair(v+1,l+1));
        }
        int rev = reverse(v);
        if(rev<= 1000*1000 && memo[rev] == -1) {
            memo[rev] = l+1;
            Q.push(make_pair(rev,l+1));
        }
    }
}

void solve2() {
    int x;
    cin >> x;

    cout << memo[x] << '\n';

}

int main() {
    precomp();
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++) {
        printf("Case #%d: ",i);
        solve2();
    }
}