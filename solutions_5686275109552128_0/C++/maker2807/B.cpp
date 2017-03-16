#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <utility>
#include <set>
#include <map>
#include <cctype>
#include <queue>
#include <functional>

#define FOR(i,n) for(long long int i=0; i<n; i++)
#define MP(a,b) make_pair(a,b)
#define PB(x) push_back(x)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())

#define COND(p,t,f) ((p)?(t):(f))

#define PI 3.14159265

using namespace std;
typedef long long int lint;
typedef unsigned long long int ulint;


lint solve(vector <lint> p) {
    //cerr << "size " << p.size() << endl;
    int maxi=0;
    FOR(i,p.size()) {
        if (p[i]>p[maxi]) maxi=i;
    }
    lint maxv=p[maxi];

    if (maxv<=3) return maxv;

    vector<lint> np, tp;
    FOR(i,p.size()) {
        if (p[i]) np.PB(p[i]-1);
        if (i!=maxi) tp.PB(p[i]);
    }

    lint ret = solve(np);
    for (int i=2; i<=maxv/2; i++) {
        tp.PB(i);
        tp.PB(maxv-i);

        ret = min(ret,solve(tp));

        tp.pop_back();
        tp.pop_back();
    }

    return 1+ret;
}


int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        cerr << t << endl;
        lint D;
        cin >> D;
        vector<lint> p(D);
        cerr << "p: ";
        FOR(i,D) {
            cin >> p[i];
            cerr << p[i] << " ";
        }
        cerr << endl;

        //priority_queue<lint, vector<lint>, less<lint> > q (p.begin(),p.end());
        lint best = solve(p);
        /*
        lint best = q.top();
        lint maxM = q.top()-1;
        FOR(i,maxM+2) {
            lint tmp = q.top();
            //cerr << "tmp is " << tmp << endl;
            best=min(best,i+tmp);

            q.pop();
            if (tmp/2) q.push(tmp/2);
            if (tmp-tmp/2) q.push(tmp-tmp/2);
        }
        */
        cout << "Case #" << t+1 << ": ";
        cout << best << endl;
    }

}
