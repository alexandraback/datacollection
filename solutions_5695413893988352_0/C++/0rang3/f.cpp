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
string a,b;
pair<int,pair<int,int> > func(int id, int x, int y) {

    //cout << id << " " << x << " " << y << " " << a << " " << a.length() << endl;

    if (id == a.length()) return {abs(x-y),{x,y}};

    pair<int,pair<int,int> > gg,hh;
    gg = {1000,{0,0}};

    if (a[id] == '?' and b[id] == '?') {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                hh = func(id+1,x*10+i,y*10+j);
                if (gg > hh) gg = hh;
            }
        }
    } else if (a[id] == '?') {
        for (int i = 0; i < 10; i++) {
            int j = b[id] - '0';
            hh = func(id+1,x*10+i,y*10+j);
            if (gg > hh) gg = hh;
     
        }
    } else if (b[id] == '?') {
        for (int j = 0; j < 10; j++) {
            int i = a[id] - '0';
            hh = func(id+1,x*10+i,y*10+j);
            if (gg > hh) gg = hh;
     
        }
    } else {
        int i,j;
        i = a[id] - '0';
        j = b[id] - '0';
        hh = func(id+1,x*10+i,y*10+j);
        if (gg > hh) gg = hh;
    }
    return gg;
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
        cin >> a >> b;
        int ans = 100000;
        int x,y;
        pair<int,pair<int,int> > gg;
        gg = func(0,0,0);
        x = gg.ss.ff;
        y = gg.ss.ss;
        int m[5];

        m[0] = 1;
        m[1] = 10;
        m[2] = 100;
        m[3] = 1000;
        m[4] = 10000;


        cout << "Case #" << ca << ": ";

        for (int i = a.length(); i > 0; i--) {
            int dig;
            dig = (x/m[i-1]);
            dig %= 10;
            cout << dig;
        }
        cout << " ";

        for (int i = a.length(); i > 0; i--) {
            int dig;
            dig = (y/m[i-1]);
            dig %= 10;
            cout << dig;
        }

        cout << endl;

    }
    
    return 0;
        
}