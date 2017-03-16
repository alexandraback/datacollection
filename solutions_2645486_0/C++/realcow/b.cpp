#include <iostream>   
#include <vector>   
#include <algorithm>   
#include <queue>   
#include <string>  
#include <xfunctional>
//#include <boost/multiprecision/cpp_int.hpp>  
//using namespace boost;
//using namespace boost::multiprecision;
using namespace std;   
#define rep(x,n) for(x=0;x<n;x++)   

typedef vector<int> vi;   
typedef long long ll;   
typedef unsigned long long ull;   
typedef pair<int, ull> pil;

struct comp {   
    bool cond1(int l, int r) {return l > r;}
    bool cond2(ull l, ull r) {return l > r;}
    bool operator()(const pil& l, const pil& r) {   
        return cond1(l.first, r.first);   
    }   
};   
bool pushNoInferior(vector<pil>& vec, pil val) {   
    bool ret = false;   
    vector<pil>::iterator it = lower_bound(vec.begin(), vec.end(), val, comp());   
    if (vec.begin() == it)    
        vec.insert(vec.begin(), val), ret = true;   
    else {   
        if (it != vec.end() && comp().cond2(val.second, it->second))   
            *it = val, ret = true;   
        else if (comp().cond2(val.second, (it - 1)->second))   
            vec.insert(it, val), ret = true;   
    }   
    return ret;   
}  
vector<pil> prevd, nxtd; // <E, V>
int main() {
    scanf("%*d");
    int i, j, k, pn = 1;
    int E, R, N;

    prevd.reserve(1000000);
    nxtd.reserve(1000000);
    while (3 == scanf("%d%d%d", &E, &R, &N)) {
        
        prevd.clear();
        prevd.push_back(pil(E, 0));
        
        for (i = 0; i < N; i++) 
        {
            int value;
            scanf("%d", &value);

            nxtd.clear();
            for (j = 0; j < prevd.size(); j++)
            {
                pil& v = prevd[j];
                for (k = 0; k <= v.first; k++) {
                    pil newV = pil(min(v.first - k + R, E), v.second + k * value);

                    pushNoInferior(nxtd, newV);
                } 
            }
            prevd = move(nxtd);
            sort(prevd.begin(), prevd.end(), greater<pil>());
            
            int nxt = min(1, (int)prevd.size());   
            for (int i = 1; i < prevd.size(); i++) {   
                if (prevd[i].second > prevd[nxt - 1].second) 
                    prevd[nxt++] = prevd[i];   
            }   
            prevd.resize(nxt);
        }

        ull sol = 0;
        for (auto e : prevd) {
            sol = max(sol, e.second);
        }

        printf("Case #%d: %llu\n", pn++, sol);
    }

}