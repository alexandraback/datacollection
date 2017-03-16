//
//  main.cpp
//  p1
//
//  Created by 默默 on 15-4-2.
//  Copyright (c) 2015年 默默. All rights reserved.
//
#include <iostream>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
#define MA 1005
#define ll long long
ll n;
ll ans;
struct Node{
    int dist;
    int value;
};
bool vis[1000005];
ll bfs(ll tar){
    memset(vis, 0, sizeof(vis));
    queue<Node> que;
    Node node;
    node.value = 1;
    node.dist = 1;
    que.push(node);
    vis[1] = 1;
    while (!que.empty()){
        Node no = que.front();
        que.pop();
        //vis[no.value] = 1;
        if (no.value == tar)
            return no.dist;
        Node n1;
        n1.dist = no.dist + 1;
        n1.value = no.value + 1;
        if (!vis[n1.value]){
            que.push(n1);
            vis[n1.value] = 1;
        }
        
        Node n2;
        n2.dist = no.dist + 1;
        int re = 0;
        int t = no.value;
        while (t){
            int x = t % 10;
            t /= 10;
            re = re * 10 + x;
        }
        n2.value = re;
        if (n2.value > tar)
            continue;
        if (!vis[n2.value]){
            //n2.value = re;
            que.push(n2);
            vis[n2.value] = 1;
        }

    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, Worsadld!\n";
    freopen("/Users/momo/Desktop/xcode_data/A-small-attempt2.in", "r", stdin);
    freopen("/Users/momo/Desktop/xcode_data/out.txt", "w", stdout);
    //ifstream fin = ifstream("/Users/momo/Desktop/userProfile/user_profile1.txt");
    int cas;
    cin >> cas;
    int cc = 0;
    while (cc++ < cas){
        ans = 0;
        cin >> n;
        //cout << n << endl;
        /*
        while (n){
            if (n % 10 == 0){
                ans++;
                --n;
            }else{
                ll re = 0;
                ll t = n;
                while (t){
                    int x = t % 10;
                    t /= 10;
                    re = re * 10 + x;
                }
                ans++;
                if (re < n)
                    n = re;
                else
                    --n;
            }
        }*/
        cout << "Case #" << cc <<": ";
        cout << bfs(n) << endl;
        
    }
    
    return 0;
}








