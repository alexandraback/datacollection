#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cassert>
#include <set>
#include <ctime>
#include <stack>
#include <cstring>
#include<functional>
#include <sstream>
#include <ctype.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#pragma comment(linker, "/STACK:16777216")
template<typename T> T fac(T a){ return a ? a*fac(a - 1) : 1; }
template<typename T> T power(T a, int p){ return !p ? 1 : (p & 1 ? a*power(a, p - 1) : power(a*a, p >> 1)); }
template<typename T> T gcd(T a, T b){ return b ? gcd(b, a%b) : a; }
template<typename T> T lcm(T a, T b){ return b / gcd(a, b) * a; }
template<typename T> T next(){ T _; cin >> _; return _; }
template<> int next<int>(){ int _; scanf("%d", &_); return _; }
template<> double next<double>(){ double _; scanf("%lf", &_); return _; }
//template<> ll next<ll>(){ ll _; scanf("%I64d", &_); return _; }
template<> char next<char>(){ char _[2]; scanf("%s", _); return _[0]; }
template<typename E> vector<E> next(int n){ vector<E> res(n); for (int i = 0; i < n; i++) res[i] = next<E>(); return res; }
template<class C, class E> int count(const C &c, const E &e){ return count(c.begin(), c.end(), e); }
template<class C, class E> bool has(const C &c, const E &e){ return find(c.begin(), c.end(), e) != c.end(); }
template<class C, class E> int find(const C &c, const E &e){ return find(c.begin(), c.end(), e) - c.begin(); }
template<class E> bool binary_has(const vector<E> &c, const E &e){ return binary_search(c.begin(), c.end(), e); }
template<class E> int binary_find(const vector<E> &c, const E &e){ return lower_bound(c.begin(), c.end(), e) - c.begin(); }
template<typename T> T dist2(T i1, T j1, T i2, T j2){ return (i1 - i2)*(i1 - i2) + (j1 - j2)*(j1 - j2); }
template<typename T> T dist(T i1, T j1, T i2, T j2){ return sqrt((i1 - i2)*(i1 - i2) + (j1 - j2)*(j1 - j2)); }
template <typename T>T qpow(T a, T b, T p){ T res = 1; while (b)if (b & 1)res = res*a%p, --b; else a = a*a%p, b >>= 1; return res; }
template <typename T>T qpow(T a, T b){ T res = 1; while (b)if (b & 1)res = res*a, --b; else a = a*a, b >>= 1; return res; }

template <int cnt> char nextChar()
{
    char s[cnt];
    scanf("%s", s);
    return s[0];
}

inline bool ok(int i, int j, int n, int m){ return 0 <= i&&i<n && 0 <= j&&j<m; }
inline bool ok(int i, int n){ return 0 <= i&&i<n; }

const double PI = acos(-1.0);
const double EPS = 1e-10;

template<typename T> inline bool LE(T a, T b){ return a <= b; }
template<typename T> inline bool BE(T a, T b){ return a >= b; }
template<typename T> inline bool EQ(T a, T b){ return a == b; }
template<typename T> inline bool LESS(T a, T b){ return a < b; }
template<typename T> inline bool BIGG(T a, T b){ return a > b; }

template<> inline bool LE(double a, double b){ return b - a > -EPS; }
template<> inline bool BE(double a, double b){ return a - b > -EPS; }
template<> inline bool EQ(double a, double b){ return fabs(a - b) < EPS; }
template<> inline bool LESS(double a, double b){ return b - a > EPS; }
template<> inline bool BIGG(double a, double b){ return a - b > EPS; }

template <typename T1, typename T2> T1 safemulmod(T2 a, T2 b, T2 mod){return a*b%mod;}

template<typename T>vector<T> shrink(vector<T> v)
{
    vector<T> t = v;
    sort(t.begin(), t.end());
    int sz = unique(t.begin(), t.end()) - t.begin();
    for(int i = 0; i < v.size(); i++)
        v[i] = lower_bound(t.begin(), t.begin()+sz, v[i]) - t.begin();
    return v;
}

template<typename T>class summer
{
public:
    summer(vector<T> &v)
    {
        data1 = v;
        for (int i = 1; i < data1.size(); i++)
            data1[i] += data1[i - 1];
    }
    
    summer(vector<vector<T>> &v)
    {
        data2 = v;
        for (int i = 0; i < data2.size(); i++)
        {
            for(int j = 0; j < data2[i].size(); j++)
            {
                if(i)
                    data2[i][j] += data2[i - 1][j];
                if(j)
                    data2[i][j] += data2[i][j - 1];
                if(i && j)
                    data2[i][j] -= data2[i - 1][j - 1];
            }
        }
    }
    
    T sum(int i0, int i1)
    {
        T res = data1[i1];
        if (i0)
            res -= data1[i0 - 1];
        return res;
    }
    
    T sum(int i0, int j0, int i1, int j1)
    {
        T res = data2[i1][j1];
        if(i0)
            res -= data2[i0-1][j1];
        if(j0)
            res -= data2[i1][j0-1];
        if(i0 && j0)
            res += data2[i0-1][j0-1];
        return res;
    }
    
    vector<T> data1;
    vector<vector<T>> data2;
};

template<typename T>class SegmentTree
{
private:
    int ds;
    vector<T> tree;
    T zero;
    function<T (T, T)> merger;
    
    int getDS(int n)
    {
        n--;n|=n>>1;n|=n>>2;n|=n>>4;n|=n>>8;n|=n>>16;return n+1;
    }
    
public:
    SegmentTree(int n, function<T (T, T)> _merger, T _zero)
    {
        ds = getDS(n);
        tree = vector<T> (2*ds);
        for(int i = 0; i < ds; i++)
            tree[i + ds] = zero;
        merger = _merger;
        zero = _zero;
        for(int i = ds-1; i > 0; i--)
            tree[i] = merger(tree[2*i], tree[2*i+1]);
    }
    
    void set(int i, T val)
    {
        i += ds;
        tree[i] = val;
        i >>= 1;
        while(i > 0)
        {
            tree[i] = merger(tree[2*i], tree[2*i+1]);
            i >>= 1;
        }
    }
    
    T get(int l, int r)
    {
        l += ds;
        r += ds;
        T lRes = zero;
        T rRes = zero;
        while(l <= r)
        {
            if((l&1)!=0) lRes = merger(lRes, tree[l++]);
            if((r&1)==0) rRes = merger(tree[r--], rRes);
            l >>= 1;
            r >>= 1;
        }
        return merger(lRes,rRes);
    }
    
    void print()
    {
        for(int i = 0; i < ds; i++)
            cout << get(i, i) << " ";
        cout << endl;
    }
};

template<typename T>class AdvancedSegmentTree
{
private:
    int ds;
    T neut;
    vector<T> tree;
    vector<T> addTree;
    vector<pair<bool, T> > setTree;
    vector<int> size;
    function<T (T, T)> merger;
    function<T (T, T, bool, T, int)> apply;
    
    T merge(int v1, int v2)
    {
        T a1 = apply(tree[v1], addTree[v1], setTree[v1].first, setTree[v1].second, size[v1]);
        T a2 = apply(tree[v2], addTree[v2], setTree[v2].first, setTree[v2].second, size[v2]);
        return merger(a1, a2);
    }
    
    int getDS(int n)
    {
        n--;n|=n>>1;n|=n>>2;n|=n>>4;n|=n>>8;n|=n>>16;return n+1;
    }
    
    void push(int v)
    {
        if(setTree[v].first)
        {
            setTree[2*v] = setTree[2*v+1] = setTree[v];
            addTree[2*v] = addTree[2*v+1] = {};
        }
        addTree[2*v] += addTree[v];
        addTree[2*v+1] += addTree[v];
        addTree[v] = {};
        setTree[v] = {};
    }
    
    void inner_set(int v, int tl, int tr, int l, int r, T value)
    {
        if(tl > r || l > tr)
            return;
        if(l <= tl && tr <= r)
        {
            addTree[v] = {};
            setTree[v] = {true, value};
        }
        else
        {
            push(v);
            int mid = (tl + tr) / 2;
            inner_set(2*v, tl, mid, l, r, value);
            inner_set(2*v+1, mid+1, tr, l, r, value);
            tree[v] = merge(2*v, 2*v+1);
        }
    }
    
    void inner_add(int v, int tl, int tr, int l, int r, T value)
    {
        if(tl > r || l > tr)
            return;
        if(l <= tl && tr <= r)
            addTree[v] += value;
        else
        {
            push(v);
            int mid = (tl + tr) / 2;
            inner_add(2*v, tl, mid, l, r, value);
            inner_add(2*v+1, mid+1, tr, l, r, value);
            tree[v] = merge(2*v, 2*v+1);
        }
    }
    
    T inner_get(int v, int tl, int tr, int l, int r)
    {
        if(tl > r || l > tr)
            return neut;
        if(l <= tl && tr <= r)
            return apply(tree[v], addTree[v], setTree[v].first, setTree[v].second, size[v]);
        else
        {
            push(v);
            int mid = (tl + tr) / 2;
            T g1 = inner_get(2*v, tl, mid, l, r);
            T g2 = inner_get(2*v+1, mid+1, tr, l, r);
            tree[v] = merge(2*v, 2*v+1);
            return merger(g1, g2);
        }
    }
    
public:
    AdvancedSegmentTree(int n, T _neut, function<T (T, T)> _merger, function<T (T, T, bool, T, int)> _apply)
    {
        ds = getDS(n);
        neut = _neut;
        tree = vector<T> (2*ds, neut);
        addTree = vector<T> (2*ds);
        setTree = vector<pair<bool, T> > (2*ds);
        size = vector<int> (2*ds, 0);
        for(int i = 0; i < n; i++)
            size[i + ds] = 1;
        for(int i = ds-1; i > 0; i--)
            size[i] = size[2*i] + size[2*i+1];
        merger = _merger;
        apply = _apply;
    }
    
    void set(int l, int r, T value)
    {
        inner_set(1, 0, ds-1, l, r, value);
    }
    
    void set(int pos, T value)
    {
        inner_set(1, 0, ds-1, pos, pos, value);
    }
    
    void add(int l, int r, T value)
    {
        inner_add(1, 0, ds-1, l, r, value);
    }
    
    void add(int pos, T value)
    {
        inner_add(1, 0, ds-1, pos, pos, value);
    }
    
    T get(int l, int r)
    {
        return inner_get(1, 0, ds-1, l, r);
    }
    
    T get(int pos)
    {
        return inner_get(1, 0, ds-1, pos, pos);
    }
    
    void print()
    {
        for(int i = 0; i < ds; i++)
            cout << get(i) << " ";
        cout << endl;
    }
    
    static AdvancedSegmentTree<T> getMaxTree(int n, T _neut)
    {
        return
        AdvancedSegmentTree<T> (
                                n,
                                _neut,
                                [] (T a, T b) {return max(a, b);},
                                [] (T value, T add, bool isSet, T set, int size) {if(isSet)value=set;value+=add;return value;}
                                );
    }
    
    static AdvancedSegmentTree<T> getMinTree(int n, T _neut)
    {
        return
        AdvancedSegmentTree<T> (
                                n,
                                _neut,
                                [] (T a, T b) {return min(a, b);},
                                [] (T value, T add, bool isSet, T set, int size) {if(isSet)value=set;value+=add;return value;}
                                );
    }
    
    static AdvancedSegmentTree<T> getSumTree(int n, T _neut)
    {
        return
        AdvancedSegmentTree<T> (
                                n,
                                _neut,
                                [] (T a, T b) {return a + b;},
                                [] (T value, T add, bool isSet, T set, int size) {if(isSet)value=set*size;value+=add*size;return value;}
                                );
    }
};

char kb[18], word[16];
int k, l, s;
int p[1<<10];

int mx;
double sum;
double cnt;

char cur[18];
int curi;

int check()
{
    if(curi < l) return 0;
    
    for(int i = 0; i < l; i++)
        if(word[i] != cur[curi-l+i])
            return 0;
    return 1;
}

void go(int i, int c)
{
    if(i == s)
    {
        mx = max(mx, c);
        sum += c;
        cnt++;
        return;
    }
    
    for(int ii = 0; ii < k; ii++)
    {
        cur[curi++] = kb[ii];
        go(i+1, c+check());
        curi--;
    }
}

int main()
{
    freopen("/Users/ibra/Downloads/B-small-attempt0.in", "r", stdin);
    freopen("/Users/ibra/Downloads/out.txt", "w", stdout);
    int t = next<int>();
    for(int test = 1; test <= t; test++)
    {
        k = next<int>();
        l = next<int>();
        s = next<int>();
        
        scanf("%s", kb);
        scanf("%s", word);
        
        for(int i = 0; i < k; i++)
        {
            double c = 0;
            for(int j = 0; j < k; j++)
                if(kb[j] == kb[i])
                    c++;
            p[kb[i]] = c / k;
        }
        
        mx = 0;
        sum = 0;
        cnt = 0;
        curi = 0;
        
        
        go(0, 0);
        
        printf("Case #%d: %0.12lf\n", test, mx - sum/cnt);
    }
    
    
    return 0;
}














