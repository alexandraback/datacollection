#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <math.h>
#include <cstdlib>

using namespace std;

typedef vector<int>::iterator iter;
typedef vector<int>::reverse_iterator riter;
typedef vector<string>::iterator str_iter;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int cases;
    cin >> cases;
    
    for (int ncase = 0; ncase != cases; ++ncase) {
        string word;
        int n;
        cin >> word >> n;
        int i = 0;
        //string cons = "aeiou";
        string cons = "bcdfghjklmnpqrstvwxyz";
        vector<string> words;
        for (int i = 0; i < word.size(); ++i) {
            for (int j = word.size() - i; j > 0; --j) {
                string temp = word.substr(i, j);
                if (temp.size() >= n) words.push_back(temp);
            }
        }
        
        ull count = 0;
        
        for (int i = 0; i != words.size(); ++i) {
            int needed = n;
            for (int j = 0; j != words[i].size(); ++j) {
                if (needed > words[i].size() - j) break;
                if (cons.find(words[i][j]) == string::npos) needed = n;
                else --needed;
                if (needed == 0) break;
            }
            if (needed == 0)
                ++count;
        }
        
        
        cout << "Case #" << ncase+1 << ": " << count << endl;
    }
   
    return 0;
}