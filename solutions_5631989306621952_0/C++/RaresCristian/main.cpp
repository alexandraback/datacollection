
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <stack>
#include <set>
#include <map>
#include <vector>
using namespace std;
typedef long long int lli;

int main() {

    ifstream fin ("input.txt");
    ofstream fout ("ans.txt");
    
    lli T; fin >> T;
    for (lli t = 0; t < T; t++) {
        
        string str; fin >> str;
        string ans = "";
        ans = ans + str[0];
        char first = str[0];
        for (int i = 1; i < str.length(); i++) {
            if (str[i] < first)
                ans = ans + str[i];
            else
                ans = str[i] + ans, first = str[i];
        }
        
        fout << "Case #" << t+1 << ": " << ans << "\n";
    }
    
    return 0;
}

