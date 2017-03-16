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

//bool dfs(bool* visited, int n, int** lists, int k, int** grid) {
//    if (k == n) {
//        
//    }
//}

int main(int argc, const char * argv[]) {
    cin>>test;
    for (int time = 0; time < test; time++) {
        int n;
        cin>>n;
//        string output = "";
        bool visited[2500];
        for (int i = 0; i < 2500; i++) visited[i] = false;
        int lists[2*n-1][n];
//        int a[n][n];
        for (int i = 0; i < 2*n-1; i++) {
            for (int j = 0; j < n; j++) {
                cin>>lists[i][j];
                visited[lists[i][j]] = !visited[lists[i][j]];
            }
        }
        
        
        cout<<"Case #"<<time+1<<":";
        for (int i = 0; i < 2500; i++) {
            if (visited[i]) {
                cout<<" "<<i;
            }

                }
                    cout<<endl;
    }
    return 0;
}
