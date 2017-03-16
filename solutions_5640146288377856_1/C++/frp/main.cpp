/* 
 * File:   main.cpp
 * Author: roman
 *
 * Created on 10 травня 2015, 11:45
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

void test(int i)
{
    int r, c, w;
    cin >> r >> c >> w;
    int result = (c / w) * r + (w-1) + (c%w ? 1 : 0);
    cout << "Case #" << i << ": " << result << endl;
}

int main(int argc, char** argv) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        test(i);
    return 0;
}

