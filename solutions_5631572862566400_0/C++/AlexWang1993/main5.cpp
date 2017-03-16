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

using namespace std;

int test;
int sol[100];
int best = 0;

bool dfs(bool* visited, int n, int num, int* list, int k, int* a) {
    if (k == num) {
        for (int i = 0; i < num; i++) {
            if ((a[list[i]] != list[(i-1+num)%num])&&(a[list[i]] != list[(i+1)%num])) {
                return false;
            }
        }
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        list[k] = i;
        if (dfs(visited, n, num, list, k+1, a)) {
            visited[i] = false;
            return true;
        }
        visited[i] = false;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    cin>>test;
    for (int time = 0; time < test; time++) {
        int n;
        cin>>n;
        //        string output = "";
        bool visited[n];
        for (int i = 0; i < n; i++) visited[i] = false;
        int a[n];
        //        int a[n][n];
//        for (int i = 0; i < 2*n-1; i++) {
//            for (int j = 0; j < n; j++) {
//                cin>>lists[i][j];
//                visited[lists[i][j]] = !visited[lists[i][j]];
//            }
//        }
        for (int i =0; i < n; i++) {
            cin>>a[i];
            a[i]--;
        }
        int list[n];
        for (int i=0;i<n;i++) list[i]=0;
        bool found = false;
        int ans = 0;
        for (int i = n ; i > 0 ; i--) {
            if (dfs(visited, n, i, list, 0, a)) {
                found = true;
                ans = i;
                break;
            }
        }
        
        
        
        
        cout<<"Case #"<<time+1<<": "<<ans<<endl;
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
