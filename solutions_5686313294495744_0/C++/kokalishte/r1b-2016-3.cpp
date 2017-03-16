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
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;



void solve() {
    int n;
    vector< pair<string,string> > MP;
    cin>>n;
    for (int i=0;i<n;++i) {
        pair<string,string> pp;
        cin>>pp.first>>pp.second;
        MP.push_back(pp);
    }
    vector<bool> vis(n,false);
    vector<set<int> > graph(n);
    for (int i=0;i<n;++i) {
        bool f=false,s=false;
        int nextF=0, nextS=0;
        for (int j=0;j<n;++j) {
            if (i==j) continue;
            if (MP[i].first==MP[j].first) f=1,nextF=j;
            if (MP[i].second==MP[j].second) s=1,nextS=j;
        }
        if (f&&s&&!graph[nextF].count(i)&&!graph[nextS].count(i)) {
            graph[i].insert(nextF);
            graph[i].insert(nextS);
            vis[i]=true;
        }
    }
    vector<int> forProcess;
    vector<int> line;
    for (int i=0;i<n;++i) if (!vis[i])forProcess.push_back(i);
    while (forProcess.size()>0) {
        int cur = forProcess[forProcess.size()-1];
        forProcess.pop_back();
        line.push_back(cur);
        for (int i=0;i<n;++i) {
            graph[i].erase(cur);
        }
        for (int i=0;i<n;++i) {
            if (!vis[i]) continue;
            if (graph[i].size()==0) {
                forProcess.push_back(i);
                vis[i]=false;
            }
        }
    }
    int res=0;
    for (int i=0;i<line.size();++i) {
        bool f=false,s=false;
        for (int j=0;j<i;++j) {
            int I=line[i];
            int J=line[j];
            if (MP[J].first==MP[I].first)f=1;
            if (MP[J].second==MP[I].second)s=1;
        }
        if (f&&s)res++;
    }
    cout<<res<<endl;
}

int main(int argc, const char * argv[]) {
    freopen("a.txt", "r", stdin);
    freopen("b.txt", "w", stdout);

    int tests;
    scanf("%d", &tests);
    for (int test=1;test<=tests;++test) {
        printf("Case #%d: ", test);
        solve();
    }

    return 0;
}
