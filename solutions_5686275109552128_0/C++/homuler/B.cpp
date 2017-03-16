#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int recur(vector<int> ps){
    int maxi = 0;
    for(int i = 0; i < ps.size(); ++i){
        if(ps[maxi] < ps[i]){
            maxi = i;
        }
    }
    if(ps[maxi] == 0){
        return 0;
    } else if(ps[maxi] == 1){
        return 1;
    }
    int mint = 1001;

    for(int j = 1; j < ps[maxi] && j <= ps[maxi] - j; ++j){
        auto ps2 = vector<int>(ps);
        ps2.push_back(j);
        ps2[maxi] -= j;
        mint = min(mint, recur(ps2)+1);
    }
    //for(int i = 0; i < ps.size(); ++i) cout << ps[i] << ' ';
    //cout << endl;
    //cout << min(ps[maxi], mint) << endl;
    return min(ps[maxi], mint);
}

int solve(vector<int> ps){
    int mint = 1001;
    set<int> ths {};
    for(auto it = ps.begin(); it != ps.end(); ++it){
        int pre = 0;
        int x = *it;
        for(int i = 1; i <= x; ++i){
            if(pre == (x+i-1)/i){
                break;
            }
            pre = (x+i-1)/i;
            ths.insert(pre);
        }
    }

    for(auto it = ths.begin(); it != ths.end(); ++it){
        int time = *it;
        int th = *it;
        //cout << "th = " << th << endl;
        for(auto pit = ps.begin(); pit != ps.end(); ++pit){
            if(*pit > th){
                time += (*pit+th-1)/th - 1;
            }
          //  cout << (*pit+th-1) << th << endl;
        }
        mint = min(mint, time);
    }
    return mint;
}

int main(){
    int t;
    cin >> t;
    int n, x;
    for(int i = 0; i < t; ++i){
        cin >> n;
        auto ps = vector<int>();
        for(int j = 0; j < n; ++j){
            cin >> x;
            ps.push_back(x);
        }
        cout << "Case #" << (i+1) << ": " << solve(ps) << endl;
    }
}
