//
//  main.cpp
//  codejam
//
//  Created by Todor Lyubomirov Bonchev on 1/1/16.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <limits>

using namespace std;

typedef unsigned long long ull;
//const ull BIG = 18446744073709551614ULL;

int j,p,s,k;
#define MT(x,y,z) make_pair(make_pair((x),(y)),(z))
typedef pair<pair<int,int>,int> tpl;
void solve() {
    vector<string> res;
    map<tpl,int> numberReps;
    cin>>j>>p>>s>>k;
    for (int i=0;i<j;++i) {
        for (int ii=0;ii<p;++ii) {
            for (int iii=0;iii<s;++iii) {
                tpl jp=MT(i,ii,-1);
                tpl js=MT(i,-1,iii);
                tpl ps=MT(-1,ii,iii);

                if (numberReps.count(jp)) {
                    numberReps[jp]++;
                    if (numberReps[jp]>k) {
                        continue;
                    }
                } else {
                    numberReps[jp]=1;
                }
                if (numberReps.count(js)) {
                    numberReps[js]++;
                    if (numberReps[js]>k) {
                        numberReps[jp]--;
                        continue;
                    }
                } else {
                    numberReps[js]=1;
                }
                if (numberReps.count(ps)) {
                    numberReps[ps]++;
                    if (numberReps[ps]>k) {
                        numberReps[jp]--;
                        numberReps[js]--;
                        continue;
                    }
                } else {
                    numberReps[ps]=1;
                }

                stringstream ss; ss<<i+1<<' '<<ii+1<<' '<<iii+1;
                res.push_back(ss.str());
            }
        }
    }
    cout << res.size()<<'\n';
    for (int i=0;i<res.size();++i) {
        cout<<res[i]<<'\n';
    }
   // putchar('\n');
}

int main(int argc, const char * argv[]) {
    freopen("/XCodeProjects/codejam/codejam/in.txt", "r", stdin);
    freopen("/XCodeProjects/codejam/codejam/out.txt", "w", stdout);

    int tests;
    scanf("%d", &tests);
    for (int test=1;test<=tests;++test) {
        printf("Case #%d: ", test);
        solve();
    }

    return 0;
}
