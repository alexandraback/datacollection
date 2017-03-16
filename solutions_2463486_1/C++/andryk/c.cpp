#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;


vector<string> v;
vector<string> v2;
const int S_SIZE = 120;
string norm_query(string q) {
    reverse(q.begin(), q.end());
    q.resize(S_SIZE, '0');
    reverse(q.begin(), q.end());
    return q;
}

void run(int t) {

    string q1,q2;
    cin>>q1>>q2;
    std::vector<string>::iterator low,up;
    low= std::lower_bound (v2.begin(), v2.end(), norm_query(q1));
    up= std::upper_bound (v2.begin(), v2.end(), norm_query(q2));
    int res = up - low;
    cout << "Case #"<<t<<": " << res << endl;



}

void gen2(int n, int maxs = 9, string l = "", string r="") {

    if(n == 0) {
        if(maxs>=0) {
            string res = l + r;
            v.push_back(res);
            //cout << res << endl;
        }
    } else if(n==1) {
        gen2(n-1, maxs-9, l+'3', r);
        gen2(n-1, maxs-4, l+'2', r);
        gen2(n-1, maxs-1, l+'1', r);
        if(l.size() > 0) {
            gen2(n-1, maxs-0, l+'0', r);
        }
    } else if(maxs >= 0) {
        gen2(n-2, maxs-2, l+"1", "1" + r);
        gen2(n-2, maxs-8, l+"2", "2" + r);
        if(l.size() > 0) {
            gen2(n-2, maxs, l+"0", "0" + r);
        }
    }
}




int main() {



    for(int i = 1; i <=50; i++) {
        gen2(i);
    }

    //cout << v.size() << endl;


    for(int i = 0; i < v.size(); i++) {
        string r;
        r.resize(v[i].size()*2-1);
        for(int j = 0; j < r.size(); j++) {
            int jj = (j <= r.size() / 2 )? j : r.size() - j -1;
            int q = 0;
            for(int k = 0; k <=jj; k++) {
                q += (v[i][k] - '0')*(v[i][jj-k] - '0');
            }
            r[j] = '0' + q;
        }


        r.resize(S_SIZE, '0');
        reverse(r.begin(), r.end());
        v2.push_back(r);

    }

    sort(v2.begin(), v2.end());


    int t;
    cin>>t;
    for(int i = 0; i < t ; i++) {

        run(i+1);
    }


}
