#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define ff first
#define ss second 
#define lli long long int
#define get getchar

inline int scan() {
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}

int main() {
        
    ios::sync_with_stdio(false);
    
    //clock_t start = std::clock();
    freopen ("inp.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    //cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    int t,ca = 1;
    cin >> t;

    while (t--) {
        cout << "Case #" << ca << ": ";
        ca++;
        lli n;
        cin >> n;
        if (n == 0) {
            cout << "INSOMNIA" << endl;
            continue;
        }
        int c[10];
        memset(c,0,sizeof(c));
        
        for (lli co = 1; ; co++) {
            lli tmp = co*n;
            while (tmp) {
                c[tmp%10] = 1;
                tmp /= 10;
            }
            int r = 0;
            for (int i = 0; i < 10; i++) {
                r += c[i];
            }
            if (r == 10) {
                cout << co*n << endl;
                break;
            }

        }

    }
    
    return 0;
        
}