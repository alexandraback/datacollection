//
//  main.cpp
//  Standing Ovation
//
//  Created by Liubing Yu on 4/10/15.
//  Copyright (c) 2015 Liubing Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void stand_ovation(int n){
    int j = 0, k = 0;
    int sum = 0;
    char temp;
    for ( int i = 0; i < n+1; i++){
        cin >> temp;
        j = temp -'0';

        if(j > 0){
            k = max(k, i - sum);
            sum = sum + j;
        }
    }
    cout << k;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...

    int n,t;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t;
        cout<< "Case #"<< i + 1 << ": ";
        stand_ovation(t);
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
