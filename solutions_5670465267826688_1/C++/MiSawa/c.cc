#include <bits/stdc++.h>//{{{
#define all(x) begin(x),end(x)
#define rall(x) (x).rbegin(),(x).rend()
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define repsz(i,v) rep(i,(v).size())
#define aur auto&
#define bit(n) (1LL<<(n))
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;
typedef long long ll;
//#define int long long
template<class C>int size(const C &c){ return c.size(); }
template<class T>bool chmin(T&a,const T&b){if(a<=b)return false;a=b;return true;}
template<class T>bool chmax(T&a,const T&b){if(a>=b)return false;a=b;return true;}//}}}
template<typename T> T s_to(string s){ //{{{
    stringstream ss;
    T res;
    ss << s;
    ss >> res;
    return res;
} //}}}

struct H{//{{{
    typedef array<array<int, 4>, 4> M;
    M m;
    H() : m(){}
    H(const M &m) : m(m){}
    friend bool operator==(const H &a, const H &b){ return a.m == b.m; }
    friend bool operator!=(const H &a, const H &b){ return a.m != b.m; }

    friend H operator*(const H &a, const H &b){
        M res = {};
        rep(i, 4) rep(j, 4) rep(k, 4) res[i][j] += a.m[i][k] * b.m[k][j];
        return H(res);
    }
    friend H operator-(const H &a){
        M res = a.m;
        rep(i, 4) rep(j, 4) res[i][j] *= -1;
        return H(res);
    }
    static const H ONE, I, J, K;
    friend ostream &operator<<(ostream &os, const H &a){//{{{
        if(a == ONE) return os << "1";
        if(a ==-ONE) return os << "-1";
        if(a ==   I) return os << "i";
        if(a ==  -I) return os << "-i";
        if(a ==   J) return os << "j";
        if(a ==  -J) return os << "-j";
        if(a ==   K) return os << "k";
        if(a ==  -K) return os << "-k";
        assert(false); return os;
    }//}}}
};//}}}
//{{{
const H H::ONE(array<array<int, 4>, 4>{{
        array<int, 4>{{ 1, 0, 0, 0}},
        array<int, 4>{{ 0, 1, 0, 0}},
        array<int, 4>{{ 0, 0, 1, 0}},
        array<int, 4>{{ 0, 0, 0, 1}},}});
const H H::I(array<array<int, 4>, 4>{{
        array<int, 4>{{ 0, 1, 0, 0}},
        array<int, 4>{{-1, 0, 0, 0}},
        array<int, 4>{{ 0, 0, 0,-1}},
        array<int, 4>{{ 0, 0, 1, 0}},}});
const H H::J(array<array<int, 4>, 4>{{
        array<int, 4>{{ 0, 0, 1, 0}},
        array<int, 4>{{ 0, 0, 0, 1}},
        array<int, 4>{{-1, 0, 0, 0}},
        array<int, 4>{{ 0,-1, 0, 0}},}});
const H H::K(array<array<int, 4>, 4>{{
        array<int, 4>{{ 0, 0, 0, 1}},
        array<int, 4>{{ 0, 0,-1, 0}},
        array<int, 4>{{ 0, 1, 0, 0}},
        array<int, 4>{{-1, 0, 0, 0}},}});
//}}}

H pow(H b, ll e){
    H res = H::ONE;
    for(; e; e>>=1, b = b*b) if(e&1) res = res * b;
    return res;
}

bool solve(){
    const H I = H::I, IJ = H::I * H::J, IJK = H::I * H::J * H::K;

    ll l, x; cin >> l >> x;
    vector<H> in;
    rep(i, l){
        char c; cin >> c;
        switch(c){
            case 'i': in.emplace_back(H::I); break;
            case 'j': in.emplace_back(H::J); break;
            case 'k': in.emplace_back(H::K); break;
            default: assert(false);
        }
    }
    if(x >= 33){
        H p = H::ONE;
        for(H &h : in) p = p * h;
        rep(i, 5){
            auto tmp = in;
            in.insert(end(in), begin(tmp), end(tmp));
        }
        in.emplace_back(pow(p, x - 32));
    }else{
        vector<H> tmp;
        rep(_, x) tmp.insert(end(tmp), begin(in), end(in));
        in = tmp;
    }
    partial_sum(begin(in), end(in), begin(in), std::multiplies<H>());
    if(in.back() != IJK){ cout << "NO" << endl; return true; }
    int i = 0;
    for(; i < size(in); ++i) if(in[i] == I) break;
    if(i == size(in)){ cout << "NO" << endl; return true; }
    for(; i < size(in); ++i) if(in[i] == IJ) break;
    if(i == size(in)){ cout << "NO" << endl; return true; }
    cout << "YES" << endl;
    return true;
}
signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    string s;
    getline(cin, s);
    int T = s_to<int>(s);
    rep(i, T){
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}
// vim:set foldmethod=marker commentstring=//%s:
