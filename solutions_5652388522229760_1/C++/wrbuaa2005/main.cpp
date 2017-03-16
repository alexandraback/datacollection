//
//  main.cpp
//  try
//
//  Created by Ran Wang on 4/18/15.
//  Copyright (c) 2015 Ran Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int counting_sheep (int num)
{
    if(num == 0)
        return 0;
    else
    {
        std::vector<bool> all(10, false);
        int cnt = 0;
        int multi = 0;
        while (cnt < 10){
            multi++;
            int cur = multi * num;
            auto tmp = std::to_string(cur);
            for(auto & a : tmp)
                if(!all[a - '0'])
                {
                    all[a - '0'] = true;
                    cnt++;
                }
        }
        return num * multi;
    }
}

int main() {
    int t, n, res;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        cout << "Case #" << i << ": " << ((res = counting_sheep(n)) == 0 ? "INSOMNIA" : to_string(res)) << endl;
    }
}
