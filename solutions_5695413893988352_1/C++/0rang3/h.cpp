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
#define lli unsigned long long

string a,b;

pair <lli,pair<lli,lli> > func (bool flag, lli x, lli y, int id) {

    //x > y
    if (id == a.length()) {
        if (y > x) {
            pair <lli,pair<lli,lli> > ans = {1e19,{0,0}},hh;
            return ans;
        }
        return {x-y,{x,y}};
    }
    pair <lli,pair<lli,lli> > ans = {1e19,{0,0}},hh;
    if (flag == 0) {
        if (a[id] != '?' and b[id] != '?' and (b[id] > a[id])) {
            return ans;
        }
        if (a[id] == '?' and b[id] == '?') {
            hh = func(0,x*10,y*10,id+1);
            if (hh < ans) ans = hh;
            hh = func(1,x*10+1,y*10,id+1);
            if (hh < ans) ans = hh;
        } else if (a[id] == '?') {
            int dig = b[id] - '0';
            hh = func(0,x*10+dig,y*10+dig,id+1);
            if (hh < ans) ans = hh;
            if (dig != 9) {
                hh = func(1,x*10+dig+1,y*10+dig,id+1);
                if (hh < ans) ans = hh;
            }
        } else if (b[id] == '?') {
            int dig = a[id] - '0';
            hh = func(0,x*10+dig,y*10+dig,id+1);
            if (hh < ans) ans = hh;
            if (dig != 0) {
                hh = func(1,x*10+dig,y*10+dig-1,id+1);
                if (hh < ans) ans = hh;
            }
        } else {
            bool f;
            if (a[id] > b[id]) f = 1;
            else f = 0;
            hh = func(f,x*10+a[id]-'0',y*10+b[id]-'0',id+1);
            if (hh < ans) ans = hh;
        }
    } else {
        if (a[id] == '?' and b[id] == '?') {
            hh = func(1,x*10,y*10+9,id+1);
            if (hh < ans) ans = hh;
        } else if (a[id] == '?') {
            hh = func(1,x*10,y*10+b[id]-'0',id+1);
            if (hh < ans) ans = hh;
        } else if (b[id] == '?') {
            hh = func(1,x*10+a[id]-'0',y*10+9,id+1);
            if (hh < ans) ans = hh;
        } else {
            hh = func(1,x*10+a[id]-'0',y*10+b[id]-'0',id+1);
            if (hh < ans) ans = hh;
        }
    }
    return ans;
}




pair <lli,pair<lli,lli> > func2 (bool flag, lli x, lli y, int id) {

    //x > y
    if (id == a.length()) {
        if (y > x) {
            pair <lli,pair<lli,lli> > ans = {1e19,{0,0}},hh;
            return ans;
        }
        return {x-y,{y,x}};
    }
    pair <lli,pair<lli,lli> > ans = {1e19,{0,0}},hh;
    if (flag == 0) {
        if (a[id] != '?' and b[id] != '?' and (b[id] > a[id])) {
            return ans;
        }
        if (a[id] == '?' and b[id] == '?') {
            hh = func2(0,x*10,y*10,id+1);
            if (hh < ans) ans = hh;
            hh = func2(1,x*10+1,y*10,id+1);
            if (hh < ans) ans = hh;
        } else if (a[id] == '?') {
            int dig = b[id] - '0';
            hh = func2(0,x*10+dig,y*10+dig,id+1);
            if (hh < ans) ans = hh;
            if (dig != 9) {
                hh = func2(1,x*10+dig+1,y*10+dig,id+1);
                if (hh < ans) ans = hh;
            }
        } else if (b[id] == '?') {
            int dig = a[id] - '0';
            hh = func2(0,x*10+dig,y*10+dig,id+1);
            if (hh < ans) ans = hh;
            if (dig != 0) {
                hh = func2(1,x*10+dig,y*10+dig-1,id+1);
                if (hh < ans) ans = hh;
            }
        } else {
            bool f;
            if (a[id] > b[id]) f = 1;
            else f = 0;
            hh = func2(f,x*10+a[id]-'0',y*10+b[id]-'0',id+1);
            if (hh < ans) ans = hh;
        }
    } else {
        if (a[id] == '?' and b[id] == '?') {
            hh = func2(1,x*10,y*10+9,id+1);
            if (hh < ans) ans = hh;
        } else if (a[id] == '?') {
            hh = func2(1,x*10,y*10+b[id]-'0',id+1);
            if (hh < ans) ans = hh;
        } else if (b[id] == '?') {
            hh = func2(1,x*10+a[id]-'0',y*10+9,id+1);
            if (hh < ans) ans = hh;
        } else {
            hh = func2(1,x*10+a[id]-'0',y*10+b[id]-'0',id+1);
            if (hh < ans) ans = hh;
        }
    }
    return ans;
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
        cout << "Case #" << ca << ": ";

        cin >> a >> b;
        bool f = false;
        bool tmp = true;
        for (int i = 0; i < a.length(); i++) {
            if (!(a[i] == '?' or b[i] == '?' or (a[i] == b[i])))
                tmp = false;
        }
        if (tmp) {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == '?' and b[i] == '?') {
                    a[i] = b[i] = '0';
                }
                if (a[i] == '?')
                    a[i] = b[i];
                if (b[i] =='?')
                    b[i] = a[i];
            }
            cout << a << " " << b << endl;
        } else {
            //cases x > y and x < y
            pair <lli,pair<lli,lli> > ans = {1e19,{0,0}},hh;
            hh = func(0,0,0,0);
            if (hh < ans) ans = hh;
            swap(a,b);
            hh = func2(0,0,0,0);
            if (hh < ans) ans = hh;
            lli m[20],ggg = 10;
            m[0] = 1;
            for (int i = 1; i < 20; i++)
                m[i] = ggg*m[i-1];


            lli x = ans.ss.ff, y = ans.ss.ss;


            for (int i = a.length(); i > 0; i--) {
                lli dig;
                dig = (x/m[i-1]);
                dig %= ggg;
                cout << dig;
            }
            cout << " ";

            for (int i = a.length(); i > 0; i--) {
                lli dig;
                dig = (y/m[i-1]);
                dig %= ggg;
                cout << dig;
            }
            cout << endl;

        }

    }
    
    return 0;
        
}