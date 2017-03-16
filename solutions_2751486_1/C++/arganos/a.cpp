/*
ID: enggi231
LANG: C++
PROG: 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

fstream out;
int t;
int n;
string s;
bool iscons[1000];
int cnt[1000001];

long long getres() {
    /*for (int i = 0; i < s.length(); i++)
        cnt[i+1] = cnt[i]+ (!iscons[s[i]]);
    int res = 0;
   // cout << cnt[0] << cnt[1]<< cnt[2] << endl;
   
    for (int a = 0; a < s.length(); a++) {
        for (int b = a+n-1; b < s.length(); b++) {
            cout << a <<" " << b <<" "<< cnt[b+1]-cnt[a] <<  endl;
            if (cnt[b+1]-cnt[a] >= n) {
                res += s.length()-b;
                break;
            }
        }
    }*/
    
    long long cur = 0, res = 0, last = -1;
    
    for (int i = 0; i < s.length(); i++) {
        if (!iscons[s[i]])
            cur++;
        else {
            if ((cur >= n) && (last < i-cur))
                last = i-cur;
            cur = 0;
        }
        
        if (cur >= n) {
            res  += (i-n-last+1)*(s.length()-i);
//            cout << i << " " << last << " " <<  (i-n-last+1) << " " << (s.length()-i) << endl;
        }
        
        if ((cur >= n) && (i-n+1 > last))
            last =i-n+1;
//        cout << i << "  last " << last << endl;
    }
    
    return res;
    
}

int main()
{
    cin >> t;
    
    iscons['a'] = 1;
    iscons['i'] = 1;
    iscons['u'] = 1;
    iscons['e'] = 1;
    iscons['o'] = 1;
    
    for (int i = 0; i < t; i++) {
        cin >> s >> n;
        cout << "Case #" << i+1 << ": " << getres() << endl;
     }
}

