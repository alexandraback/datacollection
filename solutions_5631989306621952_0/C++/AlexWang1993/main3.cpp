//
//  main.cpp
//  Mushroom
//
//  Created by Alex Wang on 2016-04-15.
//  Copyright © 2016 Alex Wang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int test;



int main(int argc, const char * argv[]) {
    cin>>test;
    for (int time = 0; time < test; time++) {
        string str;
        cin>>str;
        string output = "";
        for (int i = 0; i < str.length(); i++) {
            string str1 = str[i] + output;
            string str2 = output + str[i];
            if (str1.compare(str2) < 0) {
                output = str2;
            } else {
                output = str1;
            }
        }

        cout<<"Case #"<<time+1<<": "<<output<<endl;
    }
    return 0;
}
