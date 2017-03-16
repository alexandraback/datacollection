//
//  main.cpp
//  Mushroom
//
//  Created by Alex Wang on 2016-04-15.
//  Copyright © 2016 Alex Wang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int test;
int f[1000];
int best = 0;

int findCycle(int* part, int* num, int n, int v, int k, int &left, int length, int *a) {
        int u = a[v];
        if (part[u] == k) {
            return length - num[u];
        } else if (part[u] >= 0){
            return 0;
        }
        left--;
        part[u] = k;
        num[u] = length;
        return findCycle(part, num, n, u, k, left, length+1, a);
}

int dfs(bool* visited, int n, vector<int>* h, int* a, int v) {
    if (visited[v]) {
        return f[v];
    }
    visited[v] = true;
    int ans = 1;
    for (int i = 0; i < h[v].size(); i++) {
        int j = h[v][i];
        if (a[v]!=j) {
            ans = max(dfs(visited, n, h, a, j) + 1, ans);
        }
    }
    f[v] = ans;
    return ans;
}

int main(int argc, const char * argv[]) {
    cin>>test;
    for (int time = 0; time < test; time++) {
        int n;
        cin>>n;
        //        string output = "";
        bool visited[n];
        for (int i = 0; i < n; i++) visited[i] = false;
        int part[n];
        for (int i = 0;i < n;i++) part[i] = -1;
        int a[n];
        vector<int>* h;
        h = new vector<int>[n];
        for (int i = 0; i < n;i++) {
            h[i] = vector<int>();
        }
        //        int a[n][n];
        //        for (int i = 0; i < 2*n-1; i++) {
        //            for (int j = 0; j < n; j++) {
        //                cin>>lists[i][j];
        //                visited[lists[i][j]] = !visited[lists[i][j]];
        //            }
        //        }
        for (int i =0; i < n; i++) {
            cin>>a[i];
            h[a[i]-1].push_back(i);
            a[i]--;
        }
        int largest = 0;
        int num[n];
        for (int i = 0; i < n ; i++) {
            num[i]=0;
        }
        int parts = 0;
        int all = n;
        for (int i = 0; i < n; i++) {
            if (part[i] <0) {
                parts++;
                largest = max(largest, findCycle(part, num, n, i, parts, all, 0, a));
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < h[i].size(); j++) {
                int v = h[i][j];
                if ((a[i] == v)&&(i<v)) {
                    int count1 =dfs(visited, n, h, a, i);
                    int count2=dfs(visited, n, h, a, v);
                    ans += dfs(visited, n, h, a, i) +
                    dfs(visited, n, h, a, v);
                }
            }
        }
//        int list[n];
//        for (int i=0;i<n;i++) list[i]=0;
//        bool found = false;
//        int ans = 0;
//        for (int i = n ; i > 0 ; i--) {
//            if (dfs(visited, n, i, list, 0, a)) {
//                found = true;
//                ans = i;
//                break;
//            }
//        }
        
        
        
        
        cout<<"Case #"<<time+1<<": "<<max(ans, largest)<<endl;
        //        for (int i = 0; i < 2500; i++) {
        //            if (visited[i]) {
        //                cout<<" "<<i;
        //            }
        //            
        //        }
        //        cout<<endl;
    }
    return 0;
}
