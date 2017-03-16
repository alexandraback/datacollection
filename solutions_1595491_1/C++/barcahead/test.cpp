#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;


int main() {
//    freopen("~/Desktop/in", "r", stdin);
//    freopen("~/Desktop/out", "w", stdout);
    ifstream cin("/Users/fengyelei/Desktop/in");
    ofstream cout("/Users/fengyelei/Desktop/out");
    int T;cin>>T;
    for (int c=1; c<=T; c++) {
        int N, S, P;
        int g[100];
        cin>>N>>S>>P;
        for (int i=0; i<N; i++) {
            cin>>g[i];
        }
        sort(g, g+N, greater<int>());
        int ret = 0;
        for (int i=0; i<N; i++) {
            if ((g[i]%3==0&&g[i]/3>=P)||((g[i]+1)%3==0&&(g[i]+1)/3>=P)||((g[i]+2)%3==0&&(g[i]+2)/3>=P)) ret++;
            else if (S>0&&g[i]>1&&(((g[i]+3)%3==0&&(g[i]+3)/3>=P)||((g[i]+4)%3==0&&(g[i]+4)/3>=P))) S--, ret++;
            else break;
        }
        cout<<"Case #"<<c<<": "<<ret<<endl;
    }
}
