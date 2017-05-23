#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define LIM 9223372036854775807LL
using namespace std;

string s, t;

typedef pair<long long, pair<long long, long long> > tres;

tres minimo(tres a, tres b){
    if(a.first <= b.first){
        if(a.first < b.first)
            return a;
        if(a.second.first <= b.second.first){
            if(a.second.first < b.second.first)
                return a;
            if(a.second.second <= b.second.second)
                return a;
            return b;
        }
        return b;
    }
    return b;
}

tres solve(int n){
    if(n == 0){
        long long a = atoll(s.c_str()), b = atoll(t.c_str());
//        cout << s << " " << t << endl;1? 2?

//        cout << a << " " << b << endl;
        return make_pair(llabs(a-b), make_pair(a, b));
    }
    pair<long long, pair<long long, long long> > resp,
    mini = make_pair(LIM, make_pair(LIM, LIM));
    if(s[n-1] == '?'){
        for(int i = 0; i < 10; i++){
            s[n-1] = i+'0';
            if(t[n-1] == '?'){
                for(int j = 0; j < 10; j++){
                    t[n-1] = j+'0';
                    resp = solve(n-1);
                    mini = minimo(mini, resp);
                }
                t[n-1] = '?';
            }
            else{
                resp = solve(n-1);
                mini = minimo(mini, resp);
            }
        }
        s[n-1] = '?';
    }
    else if(t[n-1] == '?'){
        for(int j = 0; j < 10; j++){
            t[n-1] = j+'0';
            resp = solve(n-1);
            mini = minimo(mini, resp);
        }
        t[n-1] = '?';
    }
    else{
        return solve(n-1);
    }
    return mini;
}

int main(){
    int casos;
    cin >> casos;
    for(int i = 1; i <= casos; i++){
        cin >> s >> t;
        tres resp = solve(s.size());
        int k = s.size();
        printf("Case #%d: %0*lld %0*lld\n", i, k, resp.second.first, k, resp.second.second);
    }
    return 0;
}
