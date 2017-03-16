#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

long long c, d, v;


int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("Ckilargelarge.txt", "w", stdout);
    int t;
    cin >> t;
    for (int tt=1;tt<=t;tt++) {
        cin >>c>>d>>v;
        priority_queue<long long> p;
        for (int i=1;i<=d;i++) {
            long long x;
            cin >> x;
            p.push(-x);
        }

        long long fiz=0;
        long long mo=0;
        while (fiz<v) {
            if (p.size()==0 || -p.top()>fiz+1) {
                mo++;
                p.push(-fiz-1);
            }
            else {
                long long x=-p.top();
                p.pop();
                fiz+=c*x;
            }
        }

        cout << "Case #" << tt<< ": "<<mo<<endl;
    }
    return 0;
}
