//
//  main.cpp
//  googleJam
//
//  Created by Nguyen Viet Trung on 3/29/16.
//  Copyright © 2016 Nguyen Viet Trung. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>       // std::vector
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>
#include <stack>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <utility>
#include <bitset>
#include <assert.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
using namespace std;

//The Last Word
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream input;
    input.open("input.txt");
    
    ofstream output;
    output.open("output.txt");
    int T;
    input >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        input >> N;
        int count[5000] = {0};
        vector<int> result;
        int maxTemp = -1;
        for (int i = 0; i < 2*N - 1; i++) {
            for (int j = 0; j < N; j++) {
                int temp;
                input >> temp;
                if (temp > maxTemp)
                    maxTemp = temp;
                count[temp]++;
            }
        }
        
        for (int i = 0; i <= maxTemp; i++)
        {
            if (count[i] > 0)
            {
                if (count[i] % 2 != 0)
                {
                    result.push_back(i);
                }
            }
        }
        sort(result.begin(), result.end(), less<int>());
        
        output << "Case #" << t << ": ";
        for (int j = 0; j < N; j++) {
            output << result[j] << " ";
        }
        output << endl;
    }
    
    
    input.close();
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
