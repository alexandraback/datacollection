//
//  main.cpp
//  code jam 1b
//
//  Created by Eric Lee on 14-5-3.
//  Copyright (c) 2014年 Eric Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int fun()
{
    int A, B, K;
    cin >> A >> B >> K;
    int count = 0;
    for(int i = 0; i < A; i++)
    {
        for(int j = 0; j < B; j++)
        {
            if((i & j) < K)
                count++;
        }
    }
    return count;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    for(int i = 1;i <= T; i++)
    {
        int result = fun();
        cout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}

