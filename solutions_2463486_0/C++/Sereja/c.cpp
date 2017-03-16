#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int ttt, t;

string s;

int ok;

long long q,w,a,b;

int i, cnt;
long long e[10000];

int main()
{
    freopen("c1.in","r",stdin);
    freopen("c1.out","w",stdout);    
    cin >> t;
    
    for (q=1;q<=10000000;q++){
        w = q;
        s = "";
        while (w){
              s += (w%10+'0');
              w /= 10;
        }
        
        ok = 1;
        for (i=0;i<s.size();i++)        
            if (s[i] != s[s.size()-i-1]) ok = 0;
            
        if (ok){
            w = q*q;
            s = "";
            while (w){
                  s += (w%10+'0');
                  w /= 10;
            }
            
            ok = 1;
            for (i=0;i<s.size();i++)        
                if (s[i] != s[s.size()-i-1]) ok = 0;
            if (ok){
               cnt++;
               e[cnt] = q*q;
            }
        }
    }
    
//    cout << cnt << endl;
//    for (i=1;i<=cnt;i++) cout << e[i] << endl;
    
    for (ttt = 1; ttt <= t; ttt++){
        printf("Case #%d: ",ttt);
        
        cin >> a >> b;
        ok = 0;
        for (i=1;i<=cnt;i++)
            if (a<=e[i])
               if (e[i]<=b) ok++;
               
        cout << ok << endl;
    }
    return 0;
}
