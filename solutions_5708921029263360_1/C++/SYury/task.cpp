#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define y1 adjf

int j, t, p, s, k;
list<pair<int, pair<int, int> > > ans;
map<pair<int, int>, int> leftf, lefts, leftw;
vector<int> gen;

void shuffle(int seed){
    mt19937 rg(time(NULL) + seed);
    F(i, 0, (int)gen.size()){
        int id = rg()%(i + 1);
        swap(gen[i], gen[id]);
        rg.discard(rg.state_size);
    }
}

void solve(int testc){
    scanf("%d%d%d%d", &j, &p, &s, &k);
    printf("Case #%d: ", testc);
    k = min(k, s);
    ans.clear();
    gen.rs(s);
    gen.asg(s, 0);
    F(i, 0, k)
        gen[i] = 1;
    int sz = 0;
    F(i, 1, j + 1){
        F(z, 1, p + 1){
            shuffle(i * z + i - 10 * z);
            sz += k;
            F(l, 0, s){
                if(gen[l]){
                    ans.pb(mk(i, mk(z, l + 1)));
                }
            }
        }

    }
    printf("%d\n", sz);
    leftf.clear(); lefts.clear(); leftw.clear();
    F(it, ans.begin(), ans.end()){
        int a = it->X, b = it->Y.X, c = it->Y.Y;
        leftf[mk(a, b)]++; lefts[mk(b, c)]++; leftw[mk(a, c)]++;
        printf("%d %d %d\n", it->X, it->Y.X, it->Y.Y);
        //if(leftf[mk(a, b)] > k || lefts[mk(b, c)] > k || leftw[mk(a, c)] > k)
        //    exit(testc);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &t);
    F(i, 0, t){
        solve(i + 1);
    }
    ret 0;
}
