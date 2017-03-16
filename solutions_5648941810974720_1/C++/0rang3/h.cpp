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
    freopen ("inp.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int t;
    cin >> t;
    int ca = 0;
    while (t--) {
        ca++;
        string s;
        cin >> s;

        int n[10];
        memset(n,0,sizeof(n));

        map <char,int> gg;

        for (int i = 0; i < s.length(); i++) 
            gg[s[i]]++;

        n[0] = gg['Z'];
        n[2] = gg['W'];
        n[6] = gg['X'];
        n[8] = gg['G'];
        n[3] = gg['T'] - n[2] - n[8];
        n[7] = gg['S'] - n[6];
        n[4] = gg['R'] - n[0] - n[3];
        n[5] = gg['F'] - n[4];
        n[1] = gg['O'] - n[0] - n[2] - n[4];
        n[9] = gg['I'] - n[5] - n[6] - n[8];

        cout << "Case #" << ca << ": ";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < n[i]; j++)
                cout << i;
        }
        cout << endl;
    }
    
    return 0;
        
}