//
//  main.cpp
//  try
//
//  Created by Ran Wang on 4/18/15.
//  Copyright (c) 2015 Ran Wang. All rights reserved.
//

#include <iostream>
#include <deque>
#include <string>
#include <cmath>

using namespace std;


int main() {
    int T;
    string str;
    cin >> T;
    
    for(int i = 1; i <= T; i++) {
        cin >> str;
        deque<char> a;
        a.push_back(str[0]);
        for(int j = 1; j<str.size();j++)
        {
            char tmp = a.front();
            if(tmp <= str[j])
                a.push_front(str[j]);
            else
                a.push_back(str[j]);
        }
        
        cout << "Case #" << i << ": ";
        for(auto & b : a)
            cout << b;
        cout << endl;
    }
}
