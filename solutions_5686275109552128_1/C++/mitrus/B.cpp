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

int solve(const vector<int>& a) {
    int answer = 1000000000;
    for (int i = 1; i <= 1000; i++) {
        int toAdd = 0;
        for (int j = 0; j < (int) a.size(); j++)
            toAdd += (a[j] - 1) / i;
        answer = min(answer, i + toAdd);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n;
        vector<int> a;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << "Case #" << i << ": " << solve(a) << endl;
    }
    return 0;
}

