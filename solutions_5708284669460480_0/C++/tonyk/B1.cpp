#include <iostream>
#include <string>
#include <vector>

using namespace std;

string kb, tgt;
int k, l, s;

int check(vector<int> p) {
    int r = 0;
    bool ok;
    for (int i = 0; i <= s-l; i++) {
        ok = true;
        for (int j = 0; j < l; j++) {
            if (tgt[j] != kb[p[i+j]]) {
                ok = false;
                break;
            }
        }
        if (ok) r++;
    }
    return r;
}

int main(){
    int t;
    int i, j, m, max, bn, sum, cr;
    vector<int> p;
    double rr;
    
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> k >> l >> s;
        cin >> kb;
        cin >> tgt;
        
        p.clear();
        max = 1;
        for (j = 0; j < s; j++) {
            p.push_back(0);
            max *= k;
        }
        
        bn = check(p);
        sum = bn;
        for (j = 1; j < max; j++) {
            for (m = s-1; m >= 0; m--){
                p[m] += 1;
                if (p[m] >= k)
                    p[m] = 0;
                else
                    break;
            }
            
            cr = check(p);
            if (cr > bn) bn = cr;
            sum += cr;
        }
        
        rr = (double)bn - (double)sum/(double)max;
        printf("Case #%d: %.7f\n", i+1, rr);
        //cout << "Case #" << i+1 << ": " <<  << endl;
    }

    return 0;
}
