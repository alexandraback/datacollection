#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cout<<"Case #"<<t<<": ";
        int n;
        cin>>n;
        vector<double> naomi(n,0.0);
        vector<double> ken(n,0.0);
        for (int i=0;i<n;++i) {
            double a;
            cin>>a;
            naomi[i]=a;
        }
        for (int i=0;i<n;++i) {
            double a;
            cin>>a;
            ken[i]=a;
        }
        //solve
        sort(naomi.begin(),naomi.end());
        sort(ken.begin(), ken.end());
        int dcnt=0;
        int wcnt=0;
        multiset<double> p;
        for (int i=0;i<n;++i) {
            p.insert(ken[i]);
        }
        int head=0;
        for (int i=0;i<n;++i) {
            if (naomi[i]>ken.back()) {
                dcnt+=n-i;
                break;
            } else if (naomi[i] >ken[head]) {
                dcnt++;
                head++;
            } else {
                ken.pop_back();
            }
        }
        for (int i=0;i<n;++i) {
            multiset<double>::iterator it=p.upper_bound(naomi[i]);
            if (it==p.end()) {
                wcnt++;
                p.erase(p.begin());
            } else {
                p.erase(it);
            }
        }
        cout<<dcnt<<" "<<wcnt<<endl;
    }
    return 0;
}
