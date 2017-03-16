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
    string s;
    cin>>T;
    while (T--) {
        cout<<"Case #"<<id<<": ";
        id++;
        cin>>s;
        string result = "";
        for (auto c: s) {
            if(result == "") result += c;
            else if (c>=result[0]) result = c + result;
            else result += c;
        }
        cout<<result<<endl;
    }
    
    return 0;
}