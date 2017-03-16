//
//  main.cpp
//  C
//
//  Created by Oleg Petrov on 09/04/2016.
//  Copyright © 2016 Oleg Petrov. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

void test(int t)
{
    string s;
    cin>>s;
    int answ = (s.back() == '-');
    for(int i = 0; i + 1 < s.length(); ++i)
        if(s[i] != s[i+1])
            ++answ;
    printf("Case #%d: %d\n", t, answ);
}

int main(int argc, const char * argv[])
{
    freopen("/Users/olpet/Downloads/gcj16/b.in", "r", stdin);
    freopen("/Users/olpet/Downloads/gcj16/b.out", "w", stdout);
    int t;
    cin>>t;
    for(int i = 1; i <= t; ++i)
        test(i);
    return 0;
}
