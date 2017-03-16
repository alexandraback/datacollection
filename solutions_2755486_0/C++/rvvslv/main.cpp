#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ifstream cin("/Users/mac/topcoder/input.txt");
    ofstream cout("/Users/mac/topcoder/output.txt");
    
    int NT;
    cin >> NT;
    
    for (int CT = 0; CT < NT; CT ++) {
        cout << "Case #" << (CT + 1) << ": ";
        
        int N;
        cin >> N;
        vector<int> d, n, w, e, s, dd, dp, ds;
        for (int i = 0; i < N; i ++) {
            int td, tn, tw, te, ts, tdd, tdp, tds;
            cin >> td >> tn >> tw >> te >> ts >> tdd >> tdp >> tds;
            d.push_back(td);
            n.push_back(tn);
            w.push_back(tw);
            e.push_back(te);
            s.push_back(ts);
            dd.push_back(tdd);
            dp.push_back(tdp);
            ds.push_back(tds);
        }
        
        vector<int> h(1000, 0);
        vector<int> hn(1000, 0);
        
        int timep = -1;
        int res = 0;
        while (true) {
            int next = -1;
            for (int i = 0; i < N; i ++)
                if (next == -1 && n[i] > 0)
                    next = i;
            
            if (next == -1)
                break;
            
            for (int i = 0; i < N; i ++)
                if (n[i] > 0 && d[i] + (n[i] - 1) * dd[i] < d[next] + (n[next] - 1) * dd[next])
                    next = i;
            
            int time = d[next] + (n[next] - 1) * dd[next];
            
            if (time > timep) {
                timep = time;
                h = hn;
            }
            
            int str = s[next] + (n[next] - 1) * ds[next];
            
            bool fire = false;
            for (int i = 2 * (w[next] + (n[next] - 1) * dp[next]); i <= 2 * (e[next] + (n[next] - 1) * dp[next]); i ++)
                if (h[i + 500] < str) {
                    fire = true;
                    hn[i + 500] = str;
                }
            
            if (fire)
                res ++;
            n[next] --;
        }
        
        cout << res << endl;
    }
    
    return 0;
} 
