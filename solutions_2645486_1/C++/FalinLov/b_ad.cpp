#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<fstream>
#include<iostream>

#define maxn 100005

using namespace std;

int tot;
long long e, r, n;
bool flag[maxn];
//int f[25][1];
long long a[maxn];
long long res = 0;

long long max(long long x, long long y) {
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    
    ifstream fi("B-large.in");
    ofstream fo("out.txt");
    
    fi >> tot;
    int cnt = 0;
    while (tot > 0) {
        cnt++;
        
        //memset(f, sizeof(f), 0);
        
        fi >> e >> r >> n;
        
        
        for (int i = 0; i < n; i++) {
            fi >> a[i];
            flag[i] = false;
        }
            
        
        long long x = 0;
        for (int i = n - 1; i >= 0; i--)
            if (x > a[i]) {
                flag[i] = true;
            }
            else
                x = a[i];
                
        //for (int i = 0; i<n;i++)
            //cout << int(flag[i]) << endl;
        
        res = 0;
        long long left = e;
        for (int i = 0; i < n; i++) {
            if (flag[i] && i != n - 1) {
                long long use = max(left + r - e, 0);
                //cout << use << "XXX" << endl;
                res += use * a[i];
                left = left - use + r;
            }    
            else {
                res += left * a[i];
                left = r;
            }
            
        }
              
        
        fo << "Case #" << cnt << ": " << res << endl;
        tot--;
    }
    
    
    fi.close();
    fo.close();
    return 0;
}
