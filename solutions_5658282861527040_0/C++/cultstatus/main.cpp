/* 
 * File:   main.cpp
 * Author: warlock
 *
 * Created on May 3, 2014, 1:07 PM
 */

#include <cstdlib>
#include <list>
#include <vector>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    int totalCases;
    int count;
    int bit;
    int a,b,k;
    
//    freopen("log", "w", stderr);
    freopen("s.in", "r", stdin);
    freopen("out", "w", stdout);
//    
    scanf("%d", &totalCases);
    for(int currCase = 1; currCase <= totalCases; currCase++)
    {
        count = 0;
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&k);
        
        
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                bit = i&j;
                if(bit < k)
                    count++;
            }
        }
        cout << "Case #" << currCase << ": ";
        cout << count<<endl;
        

    }
    
    
    return 0;
}