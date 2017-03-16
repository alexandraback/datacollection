#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <unordered_set>
#include <unordered_map>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

#define val const auto
#define var auto

#define all(c) c.begin(), c.end()
#define repeat(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x) 
#endif

typedef complex<double> point;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    for(auto it = v.begin(); it != v.end(); ++it){
        if(it != v.begin()){
            os << ",";
        }
        os << *it;
    }
    return os << "}";
}

template <typename T>
T read_next(){
    T ret; cin >> ret;
    return ret;
}


template<typename T>
void isort(std::vector<T>& v, std::function<bool(T,T)> comp=less<T>()){
    sort(v.begin(), v.end(), comp);
}
template<typename T>
std::vector<T> sort(std::vector<T> v, std::function<bool(T,T)> comp=less<T>()){
    isort(v);
    return v;
}
template<typename T1, typename T2>
std::vector<T2> rmap(const std::vector<T1>& v, std::function<T2(T1)> f){
    std::vector<T2> t; t.reserve(v.size());
    for(const auto& i: v) t.push_back(f(i));
    return t;
}
std::vector<std::string> split(std::string str, char delim){
    std::vector<std::string> res;
    size_t current = 0, found;
    while((found = str.find_first_of(delim, current)) != std::string::npos){
        res.push_back(std::string(str, current, found - current));
        current = found + 1;
    }
    res.push_back(std::string(str, current, str.size() - current));
    return res;
}
string join(const std::vector<string>& v, string delim){
    string ret = "";
    for(auto it = v.begin(); it != v.end(); ++it){
        if(it != v.begin()){
            ret += delim;
        }
        ret += *it;
    }
    return ret;
}

int count_routes(const vector<vector<char> >& r){
    int n = r.size();
    vector<int> memo(n, -1);
    function<int(int, int)> count_way = [&](int h, int t){
        if(t > 10) {
            throw -1;
        }
        if(h == n-1) return 1;
        if(memo[h] != -1) return memo[h];
        int ret = 0;
        for(int i=0;i<n;i++){
            if(r[h][i]) ret += count_way(i, t+1);
        }
        return memo[h] = ret;
    };
    try {
        return count_way(0, 0);
    } catch (int i){
        return -1;
    }

}

vector<vector<char> > extract(int b, int repr){
    vector<vector<char> > ret(b, vector<char>(b, false));
    int z = 0;
    for(int i=0;i<(b-1)*(b-1);i++){
        if(z % (b+1) == 0){
            z++;
        }
        if(z % b == 0){
            z++;
        }
        if(repr & (1 << i)){
            ret[z/b][z%b] = true;
        }
        z++;
    }
    return ret;
}

void display(const vector<vector<char> >& v){
    for(int y=0;y<v.size();y++){
        for(int x=0;x<v[y].size();x++){
            if(v[y][x]){
                cerr << '1';
            } else {
                cerr << '0';
            }
        }
        cerr << endl;
    }
}


void display_cout(const vector<vector<char> >& v){
    for(int y=0;y<v.size();y++){
        for(int x=0;x<v[y].size();x++){
            if(v[y][x]){
                cout << '1';
            } else {
                cout << '0';
            }
        }
        cout << endl;
    }
}



vector<vector<vector<char> > > solve(const int b){
    vector<vector<vector<char> > > ret(21);
    int k = (b-1) * (b-1) - (b-2);
    for(int i=0;i<(1<<(k+1));i++){
        auto v = extract(b, i);
        int h = count_routes(v);
        if(h != -1 and h <= 20){
            ret[h] = v;
        }
    }
    return ret;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<vector<vector<char> > > > memo(7);
    for(int b=2;b<=6;b++){
        auto ans = solve(b);
        for(int m=1;m<=20;m++){
            cerr << b << " " << m << endl;
            if(ans[m].size() == 0){
                cerr << "IMPOSSIBLE" << endl;
            }else{
                cerr << "POSSIBLE" << endl;
                display(ans[m]);
            }
        }
        memo[b] = ans;
    }
    int t; cin >> t;
    for(int k=1;k<=t;k++){
        int b, m; cin >> b >> m;
        if(memo[b][m].size() == 0){
            cout << "Case #" << k << ": IMPOSSIBLE" << endl;
        }else{
            cout << "Case #" << k << ": POSSIBLE" << endl;
            display_cout(memo[b][m]);
        }
    }
    return 0;
}
