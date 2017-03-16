//
//  main.cpp
//  GCJQual
//
//  Created by Anton Krasnokutskiy on 11.04.15.
//  Copyright (c) 2015 Anton Krasnokutskiy. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(const string& s) {
    int currentCount = 0, answer = 0;
    for (int i = 0; i < s.length(); i++) {
        int iCount = s[i] - '0';
        if (iCount > 0) {
            answer = max(answer, i - currentCount);
        }
        currentCount += iCount;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n;
        string s;
        cin >> n >> s;
        cout << "Case #" << i << ": " << solve(s) << endl;
    }
    
}

