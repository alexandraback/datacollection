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
#include <cmath>
#include <bitset>

using namespace std;

vector<int> prime;

void generatePrime()
{
    prime.push_back(2);
    prime.push_back(3);
    int upper = 1 << 16;
    for(int num = 5; num < upper; num+=2)
    {
        int t = sqrt(num);
        int index = 0;
        bool flag = true;
        while(prime[index] <= t)
        {
            index++;
            if(num % prime[index] == 0){
                flag = false;
                break;
            }
        }
        if(flag)prime.push_back(num);
    }
}

int findCom(unsigned long long num)
{
    unsigned long t = sqrt(num);
    for(auto & a : prime)
    {
        if(a > t)
            break;
        if(num % a == 0)
            return a;
    }
    return 0;
}

std::string validCoin(const int N, int J)
{
    int cnt = 0;
    string res;
    unsigned int cur = (1 << (N - 1)) + 1;
    while(cnt < J)
    {
        unsigned int abc = 1 << (N - 1);
        string str;
        while(abc > 0){
            if(cur & abc)
                str += '1';
            else
                str += '0';
            abc >>= 1;
        }
        
       // std::cout << str << std::endl;
        
            bool flag = true;
            vector<int> tmp;
            for(int j = 2; j <= 10; j++){
                auto basen = stoull(str, nullptr, j);
                int val = findCom(basen);
                
                //std::cout << basen << ' ' << val << std::endl;
                tmp.push_back(val);
                if(val == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                res += '\n';
                res += str;
                for(auto & a : tmp)
                    res += (' ' + std::to_string(a));
                cnt++;
            }
        cur += 2;
    }
    return res;
    
}

int main() {
    int t, N, J;
    generatePrime();
    std::string str;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> N >> J;
        cout << "Case #" << i << ": " << validCoin(N, J) << endl;
    }
}
