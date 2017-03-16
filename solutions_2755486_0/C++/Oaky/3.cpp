#include <cstdio>
#include <queue>
#include <map>

using namespace std;

struct T{
    int day, natt, w, e, str, dday, dpos, dstr;
    
    bool operator<(const T& o)const{
        return day > o.day;
    }
    
    T(int _day, int _natt, int _w, int _e, int _str, int _dday, int _dpos, int _dstr){
        day = _day;
        natt = _natt;
        w = _w;
        e = _e;
        str = _str;
        dday = _dday;
        dpos = _dpos;
        dstr = _dstr;
    }
};

map<int,int> arr, arr2;
int lastday = -1;

priority_queue<T> Q;

int attack(int day, int l, int r, int s){
    if(day != lastday){
        for(map<int,int>::iterator x = arr2.begin(); x != arr2.end(); ++x){
            arr[x->first] = x->second;
        }
        arr2.clear();
        lastday = day;
    }
    l *= 2;
    r *= 2;
    bool succ = false;
    for(int i = l; i <= r; ++i){
        if(arr[i] < s){
            arr2[i] = max(arr2[i], s);
            succ = true;
        }
    }
    return succ ? 1 : 0;
}

int calc(){
    lastday = -1;
    arr.clear();
    arr2.clear();
    int n;
    int day, natt, w, e, str, dday, dpos, dstr;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d %d %d %d %d %d %d", &day, &natt, &w, &e, &str, &dday, &dpos, &dstr);
        Q.push(T(day, natt, w, e, str, dday, dpos, dstr));
    }
    int ans = 0;
    while(not Q.empty()){
        T x = Q.top();
        Q.pop();
        //printf("day %d\n", x.day);
        ans += attack(x.day, x.w, x.e, x.str);
        //printf("%d\n", ans);
        if(x.str + x.dstr <= 0) continue;
        if(x.natt - 1 <= 0) continue;
        Q.push(T(x.day + x.dday, x.natt - 1, x.w + x.dpos, x.e + x.dpos, x.str + x.dstr, x.dday, x.dpos, x.dstr));
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        printf("Case #%d: %d\n", i, calc());
    }
    return 0;
}
