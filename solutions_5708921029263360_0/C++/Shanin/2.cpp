#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define hash privet5

using namespace std;

    int t, a, b, c, k;

    void inc(int &i){if(i == c) i = 0; else i++;}

int main(){
    freopen("C-small-attempt5.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int w=0; w<t; w++){
        cin >> a >> b >> c >> k;
        cout << "Case #" << w+1 << ": " << a*b*min(k, c) << "\n";
        for(int e=0; e<a; e++){
            int i=0;
            for(int r=0; r<b; r++){
                for(int q=0; q<min(k, c); q++){
                    cout << e+1 << " " << r+1 << " " << i%c+1 << "\n";
                    i++;
                }
            }
        }

    }

}
/*
1212121112121124
111212
*/
