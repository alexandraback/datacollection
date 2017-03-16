//
//  main.cpp
//  try
//
//  Created by Ran Wang on 4/18/15.
//  Copyright (c) 2015 Ran Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int flip_pancake(const std::string& str)
{
    if(str.empty())return 0;
    else
    {
        int cnt = 0;
        if(str[0] == '-')cnt++;
        for(int i = 1; i < str.size(); i++)
            if(str[i] == '-' && str[i-1] == '+')
                cnt += 2;
        return cnt;
    }
}

int main() {
    int t;
    std::string str;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> str;
        cout << "Case #" << i << ": " << flip_pancake(str) << endl;
    }
}
