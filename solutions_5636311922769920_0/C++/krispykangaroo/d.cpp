#include <bits/stdc++.h>
using namespace std;

int k, c;

long long llpow(long long base, int n){
    long long retval = 1;
    while(n--){
        retval *= base;
    }
    return retval;
}

unsigned long long pathToIndex(const vector<long long>& path){
    long long retval = 0;
    long long expo = llpow(k, c);
    for(int i = 0; i < path.size(); i++){
        retval += path[i]*llpow(k, (c-i-1));
    }
    return retval;
}

int main(){
    int n;
    cin >> n;
    vector<long long> path;
    for(int i = 1; i <= n; i++){
        path.clear();
        int s;
        cin >> k >> c >> s;
        cerr << "kcs:" << k << " " << c << " " << s << endl;
        if(s*c < k){
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
            continue;
        }

        vector<long long> solutions;
        int kcount = 0;
        while(kcount < k){
            int curpath = 0;
            path.clear();
            cerr << "curpath: " ;
            for(; curpath < c && kcount < k; curpath++){
                cerr << kcount << " ";
                path.push_back(kcount);
                kcount++;
            }
            cerr << endl;
            solutions.push_back(pathToIndex(path));
        }
        cout << "Case #" << i << ":";
        for(long long ll : solutions){
            cout << " " << ll + 1;
        }
        cout << endl;
    }
}
