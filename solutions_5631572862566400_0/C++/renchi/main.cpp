#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

const int MAXN = 10005;

int a[2000];
int c[2000];
vector<bool> b(2000, false);
int k;
int DFS(int start, int now, int circle) {
    //cout<<start<<now<<circle<<endl;
    if (circle > k) {
        return -1;
    }
    if (now == start) {
        return circle;
    }
    int result;
    b[now] = true;
    if (b[a[now]] == false) {
        result = DFS(start, a[now], circle+1);
    } else {
        if (a[a[now]] != now) {
            return 0;
        } else {
            if (c[now] > 1)
                result = circle + 2;
            else
                result = circle + 1;
        }
    }
    b[now] = false;
    return result;
}

int main() {
    int i,j,t,h,Case = 1;
    cin>>t;
    while(t--)
    {
        cin>>k;
        for (int i = 1; i <= k; i++) {
            c[i] = 0;
        }
        for(int i = 1; i <= k; i++) {
            cin>>h;
            a[i] = h;
            c[h]++;
        }
        //cout<<c[3]<<endl;
        int result = 0;
        for(int i = 1; i <= 1; i++) {
            result = max(result, DFS(i, a[i], 1));
        }
        cout<<"Case #"<<Case++<<": "<<result<<endl;
    }
    return 0;
}
