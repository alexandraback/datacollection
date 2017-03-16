# include <string>
# include <vector>
# include <iostream>
# include <sstream>
# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <cctype>
# include <cstring>
# include <map>
# include <queue>
# include <deque>
# include <set>
# include <algorithm>
# include <utility>
# include <functional>
# include <stack>
# include <bitset>
# include <complex>
# include <cassert>
# include <ctime>
# include <list>
# include <valarray>

using namespace std;

bool is_num_valid(string C, int tmp)
{
    bool valid = true;
    
    for(int i = C.length()-1; i >= 0; i--)
    {
        int digit = tmp %10;
        tmp /= 10;
        
        if(C[i] == '?')
            continue;
        
        if(C[i] != (char)('0' + digit))
        {
            valid = false;
        }
    }
    
    return valid;
}
void work(string C, string J)
{
    int min_diff = 1000000;
    string best_c;
    string best_j;
    
    for(int num_c = 0; num_c < pow(10, (C.length())); num_c++)
    {
        bool valid = is_num_valid(C, num_c);
        
        if(!valid)
            continue;
        
        for(int num_j = 0; num_j < pow(10, (J.length())); num_j++)
        {
            valid = is_num_valid(J, num_j);
            
            if(!valid)
                continue;
            
            if(abs(num_c - num_j) < min_diff)
            {
                min_diff = abs(num_c - num_j);
                best_c = to_string (num_c);
                best_j = to_string (num_j);
            }
        }
    }
    string padded_zeros_c = "";
    for(int i = 0; i < C.length() - best_c.length(); i++)
        padded_zeros_c.append("0");
    
    string padded_zeros_j = "";
    for(int i = 0; i < J.length() - best_j.length(); i++)
        padded_zeros_j.append("0");
    
    cout << padded_zeros_c << best_c << " " << padded_zeros_j << best_j << endl;
    
    
    
}

int main()
{
    int T;
    cin >> T;
    
    for(int i = 1; i <= T; i++)
    {
        string C, J;
        cin >> C >> J;
        
        cout << "Case #" << i << ": ";
        work(C, J);
    }
    return 0;
}

