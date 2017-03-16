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

int fun(int N)
{
    string s[100];
    int con[100][100] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }
    for(int i = 0; i < N; i++)
    {
        string str = s[i];
        if(str.length() > 1)
        {
            for(int j = 1; j < str.length();)
            {
                if(str[j - 1] == str[j])
                {
                    con[i][j]++;
                    str = str.substr(0, j - 1) + str.substr(j, str.length() - j);
                }
                else
                    j++;
            }
            s[i] = str;
        }
    }
    int flag = true;
    for(int i = 1; i < N; i++)
    {
        if(s[i] != s[0])
            flag = false;
    }
    if(flag)
    {
        int scount[100] = {0};
        int sum = 0;
        for(int i = 0; i < 100; i++)
        {
            int count[100] = {0};
            for(int j = 0; j < N; j++)
            {
                count[j] +=con[j][i];
            }
            sort(count, count + N);
            int m = count[N/2];
            int tsum = 0;
            for(int j = 0; j < N; j++)
            {
                tsum += (m<count[j])?count[j] - m: m- count[j];
            }
            scount[i] = tsum;
            
        }
        for(int i = 0; i < 100; i++)
        {
            sum += scount[i];
        }
        return sum;
    }
    else
        return -1;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    for(int i = 1;i <= T; i++)
    {
        int N;
        cin >> N;
        int result = fun(N);
        if(result < 0)
            cout << "Case #" << i << ": Fegla Won" << endl;
        else
            cout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}

