// =====================================================================================
//
//       Filename:  A.cpp
//         Author:  Reyno Tilikaynen, r.tilikaynen@gmail.com
//   Organization:  University of Waterloo
//
// =====================================================================================

#include <bits/stdc++.h>

using namespace std; 

bool has (string s, vector <int> &c){
    for (int i = 0; i < s.length (); i++)
        c[s[i] - 65]--;
    for (int i = 0; i < s.length (); i++){
        if (c[s[i] - 65] < 0){
            for (int j = 0; j < s.length (); j++)
                c[s[j] - 65]++;
            return false;
        }
    }
    return true;
}

int main (){ 
    int tt; 
    cin >> tt; 
    for (int cases = 1; cases <= tt; cases++){
        printf ("Case #%d: ", cases);
        string s; 
        cin >> s;
        vector <int> c (26, 0);
        for (int i = 0; i < s.length (); i++)
            c[s[i] - 65] ++;
        string words [10] = {"ZERO", "TWO", "EIGHT", "FOUR", "SIX", "SEVEN", "FIVE", "NINE", "ONE", "THREE"};
        string id [10] = {"Z", "W", "G", "U","X", "S", "V", "I", "O", "H"}; 
        int num [10] = {0, 2, 8, 4, 6, 7, 5, 9, 1, 3};
        vector <int> amt (10, 0);
        for (int i = 0; i < 10; i++){
            while (has (id[i], c)){
                c[id[i][0] - 65] ++;
                has (words[i], c);
                amt[num[i]]++;
            }
        }
        for (int i = 0; i < 10; i++)
            while (amt[i]--)
                cout << i;
        cout << "\n";
    }
}
