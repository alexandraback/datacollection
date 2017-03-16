#include <algorithm>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string filename ("input_c");
    string line;
    ifstream file (filename);
    int k;

    //
    getline (file, line);
    k = stoi(line);

    for (int t = 0; t < k; t++) {   //for each test case
        long long c, d, v;
        vector<long long> deno;

        // parsing
        getline (file, line);

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                c = stol(line.substr(0, i));
                line = line.substr(i + 1, line.size() - i - 1);                                                       
                break;                                                                                                
            }                                                                                                         
        }                                                                                                             
        
        for (int i = 0; i < line.size(); i++) {                                                                       
            if (line[i] == ' ') {
                d = stol(line.substr(0, i));
                v = stol(line.substr(i + 1, line.size() - i - 1));                                                    
                break;                                                                                                
            }                                                                                                         
        }                                                                                                             
        
        getline (file, line);                                                                                         
        int pos = -1;
        long long tmp;
        for (int i = 1; i < line.size(); i++) {                                                                       
            if (line[i] == ' ') {
                tmp = stol(line.substr(pos + 1, i - pos - 1));                                                        
                deno.push_back(tmp);                                                                                  
                pos = i;                                                                                              
            }                                                                                                         
        }
        tmp = stol(line.substr(pos + 1, line.size() - pos + 1));
        deno.push_back(tmp);

        // main
        long long cur_max = 0;
        int new_deno = 0;
        int idx = 0;

        if (deno[0] != 1) {
            cur_max = c;
            new_deno = 1;
        }

        while (cur_max < v) {
            if (idx < deno.size() && deno[idx] <= cur_max + 1) {
                cur_max = cur_max + deno[idx] * c;
                idx++;
            } else {
                cur_max = cur_max + (cur_max + 1) * c;
                new_deno++;
            }
        }

        cout << "Case #" << t+1 << ": " << new_deno << "\r\n";
        /*
        for (int i = 0; i < deno.size(); i++) {
            cout << deno[i] << " ";
        }
        */
    }
    return 0;
}