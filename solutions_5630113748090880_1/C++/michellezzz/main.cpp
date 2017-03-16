//
//  leetcode_cpp
//
//  Created by Xingying Liu on 4/10/16.
//  Copyright © 2016 Xingying Liu. All rights reserved.
//


# include <iostream>
# include <vector>
# include <unordered_map>
# include <set>
# include <unordered_set>
# include <fstream>

using namespace std;



int main(){
    int T, id = 1;
    cin>>T;
    while (T--) {
        cout<<"Case #"<<id<<": ";
        id++;
        int N, cur;
        cin>>N;
        unordered_map<int, int> count;
        for (int i=0; i<2*N-1; i++) {
            for (int j=0; j<N; j++) {
                cin>>cur;
                count[cur]++;
            }
        }
        vector<int> result;
        for (auto it=count.begin(); it!=count.end(); it++) {
            if (it->second%2!=0)
                result.push_back(it->first);
        }
        sort(result.begin(), result.end());
        for (auto k: result) cout<<k<<" ";
        cout<<endl;
    }
    
    return 0;
}