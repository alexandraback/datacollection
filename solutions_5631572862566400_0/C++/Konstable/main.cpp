//
//  main.cpp
//  jamC
//
//  Created by Aleksander Konstantinov on 4/16/16.
//  Copyright © 2016 Aleksander Konstantinov. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool dfs(int k, vector<int> const &BFF, vector<int>& Used, vector<int>& path)
{
    if (Used[k] == 0)
    {
        Used[k] = 1;
        path.push_back(k);
        
        if (path.size() >= 2)
        {
            if ((BFF[path.back()] == path[0]) || (BFF[path.back()] == path[path.size() - 2]))
                return true;
        }
        
        return dfs(BFF[k], BFF, Used, path);
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    std::ifstream infile("C-small-attempt2.in");
    ofstream myfile;
    myfile.open ("result.txt", fstream::out);
    int T;
    infile >> T;
    for (int i = 1; i <= T; ++i)
    {
        int N;
        infile >> N;
        vector<int> BFF(N + 1);
        vector<int> BFF_Reverse(N + 1);
        vector<int> Used(N+1, 0);
        vector<int> path;
        path.reserve(N);
        for (int j = 1; j <= N; ++j)
        {
            int f;
            infile >> f;
            BFF[j] = f;
            BFF_Reverse[f] = j;
        }
        
        int m = -1;
        for(int j = 1; j <= N; ++j)
        {
            Used.clear();
            Used.resize(N+1, 0);
            path.clear();
            if (dfs(j, BFF, Used, path))
            {
                if (path.size() >= 2 && (BFF[path.back()] == path[path.size() - 2]))
                {
                    int last = BFF_Reverse[path.back()];
                    while(true)
                    {
                        if (last == 0)
                            break;
                        
                        if (find(path.begin(), path.end(), last) == path.end())
                        {
                            path.push_back(last);
                            last = BFF_Reverse[last];
                        }
                        else
                        {
                            break;
                        }
                    }
                    
                    last = BFF_Reverse[path[0]];
                    while(true)
                    {
                        if (last == 0)
                            break;
                        
                        if (find(path.begin(), path.end(), last) == path.end())
                        {
                            path.push_back(last);
                            last = BFF_Reverse[last];
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                
                m = max(static_cast<int>(path.size()), m);
            }
            


            
            
        }
        
        myfile << "Case #" << i << ": " << m << endl;
    }
    
    myfile.close();
    infile.close();
    
    return 0;
}
