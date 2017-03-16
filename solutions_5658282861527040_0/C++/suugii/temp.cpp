#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>

#define xx first
#define yy second
#define mod 1000000007
#define pb push_back
#define mp make_pair
//#define MAX 2000000000
using namespace std;

int dirx[8] = {1,0,-1,0,1,-1,-1,1};
int diry[8] = {0,1,0,-1,1,1,-1,-1};

vector<int>s;
main() {
    freopen("input.in","r",stdin);
    freopen("The_Repeater","w",stdout);
    int test, a, b, c, k, ans;
    cin >> test;
    for(int t=1;t<=test;t++) {
        ans = 0;
        cin >> a >> b >> k;
        for(int i=0;i<a;i++) {
            for(int j=0;j<b;j++) {
                c = i&j;
                if(c<k) ans++;
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

