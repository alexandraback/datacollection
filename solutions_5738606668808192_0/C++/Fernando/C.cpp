#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int main()
{
    ofstream cout("C-small.out");
    cout << "Case #1:" << endl;
    
    char arr1[] = {'0', '0', '0', '0', '0', '1', '1'};
    char arr2[] = {'0', '0', '0', '0', '0', '1', '1'};
    
    int J = 50;
    while (J > 0)
    {
        string s = "1";
        for (int i = 0; i < 7; i++) 
        {
            s = s + arr1[i];
            s = s + arr2[i];
        }
        s = s + '1';
        cout << s << " 3 2 3 2 7 3 3 2 3" << endl;
        J--;
        
        bool flag = std::next_permutation(arr2, arr2 + 7);
        if (!flag) flag = next_permutation(arr1, arr1 + 7);
    }
       
    return 0;
}
