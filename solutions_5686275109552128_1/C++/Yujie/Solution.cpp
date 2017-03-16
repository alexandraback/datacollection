//
//  Solution.cpp
//  GoogleJam
//
//  Created by LIU YUJIE on 3/25/15.
//  Copyright (c) 2015 刘予杰. All rights reserved.
//

#include "Solution.h"
#include <string>


void doCase(ifstream& file,int index, string &s)
{
    string ans;
    
    int D;
    file >> D;
    vector<int> arr(D);
    
    for (int i = 0; i < D; ++i) {
        file >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int maxTime = arr[arr.size() - 1];
    int bigest = maxTime;
    int maxCut = (maxTime - 1)/3 +1;
    for (int i = 1; i <= maxCut; ++i) {
        int maxCake = bigest / (i+1) + (bigest % (i+1) != 0);
        int t = maxCake;
        int cut = 0;
        for (int j = (int)arr.size() - 1; j >= 0; --j) {
            if (arr[j] > maxCake) {
                t += arr[j]/maxCake - 1 + (arr[j]% maxCake != 0);
                int t1 = arr[j] + cut;
                if (t1 < maxTime) {
                    maxTime = t1;
                }
                cut += arr[j]/maxCake - 1 + (arr[j]% maxCake != 0);
            }
            else
                break;
        }
        if (t < maxTime) {
            maxTime = t;
        }
    }
    
    ans = to_string(maxTime);
    s += "Case #" + to_string(index) + ": " + ans + "\n";
}
