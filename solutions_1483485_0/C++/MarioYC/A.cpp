#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int a[256];

int main(){
a['a'] = 'y';
a['b'] = 'h';
a['c'] = 'e';
a['d'] = 's';
a['e'] = 'o';
a['f'] = 'c';
a['g'] = 'v';
a['h'] = 'x';
a['i'] = 'd';
a['j'] = 'u';
a['k'] = 'i';
a['l'] = 'g';
a['m'] = 'l';
a['n'] = 'b';
a['o'] = 'k';
a['p'] = 'r';
a['q'] = 'z';
a['r'] = 't';
a['s'] = 'n';
a['t'] = 'w';
a['u'] = 'j';
a['v'] = 'p';
a['w'] = 'f';
a['x'] = 'm';
a['y'] = 'a';
a['z'] = 'q';
a[' '] = ' ';
    
    int T;
    
    cin >> T;
    
    string line;
    getline(cin,line);
    
    for(int tc = 1;tc <= T;++tc){
        getline(cin,line);
        
        int L = line.size();
        
        cout << "Case #" << tc << ": ";
        
        for(int i = 0;i < L;++i)
            cout << (char)a[ line[i] ];
        cout << '\n';
    }
    
    return 0;
}
