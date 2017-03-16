//
//  main.cpp
//  p3
//
//  Created by 默默 on 15-4-2.
//  Copyright (c) 2015年 默默. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <queue>
using namespace std;
#define MA 100005
#define ll long long

struct Node{
    int id;
    ll start;
    ll value;
}node[MA], tn[MA];
int cmp(Node a, Node b){
    return a.start < b.start;
}
vector<int> edg[MA];
int n,ss;

void search(int u, int pre){
    int sz =  edg[u].size();
    int total = 0;
    for (int i = 0; i < sz; ++i){
        int v = edg[u][i];
        if (v == pre)
            continue;
        search(v, u);
        ++total;
    }
    if (total == 0){
        node[u].start = 0;
        //cout << u << " " << node[u].value << endl;
        return;
    }
    
    if (u == ss){
        ll maxx = 0;
        for (int i = 0; i < sz; ++i){
            int v = edg[u][i];
            if (node[v].start + node[v].value > maxx){
                maxx = node[v].start + node[v].value;
            }
        }
        node[u].start = maxx;
        return;
    }
    total = 0;
    ll total_huowu = node[u].value;
    for (int i = 0; i < sz; ++i){
        int v = edg[u][i];
        if (v == pre){
            continue;
        }
        tn[total] = node[v];
        ++total;
        total_huowu += node[v].value;
    }
    sort(tn, tn + total, cmp);
    ll endtime = node[u].value;
    for (int i = 0; i < total; ++i){
        if (tn[i].start + 1 <= endtime){
            endtime += tn[i].value;
        }
        else{
            endtime = tn[i].start + tn[i].value + 1;
        }
    }
    node[u].start = endtime - total_huowu;
    node[u].value = total_huowu;
    if(u == 3)
    {
        cout << node[u].start << " " << node[u].value << endl;
    }
}

int main(int argc, const char * argv[]) {
    freopen("/Users/momo/Desktop/xcode_data/in.txt", "r", stdin);
    //freopen("/Users/momo/Desktop/xcode_data/C-small-1-attempt0.in", "r", stdin);
    //freopen("/Users/momo/Desktop/xcode_data/out.txt", "w", stdout);
    
    //ifstream fin = ifstream("/Users/momo/Desktop/userProfile/user_profile1.txt");
    int cas;
    cin >> cas;
    int cc = 0;
    int n;
    while (cc++ < cas){
        scanf("%d %d", &n, &ss);
        for (int i = 1; i <= n; ++i)
            edg[i].clear();
        for (int i = 1; i < n; ++i){
            int u,v;
            scanf("%d %d", &u, &v);
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i){
            node[i].id = i;
            cin >> node[i].value;
            //scanf("%d", &node[i].value);
        }
        search(ss, -1);
        printf("Case #%d: ", cc);
        cout << node[ss].start << endl;
    }
    return 0;
}

