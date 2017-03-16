#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <climits>
#include <set>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;

#define PI 3.1415926535897932384626433
#define INF ((1<<30)-1)*2+1
#define mp(a, b) make_pair((a), (b))
#define pb push_back
#define MOD 1000000007
#define MAX_N 10000
using namespace std;

bool isPossible(int x, int N, pair<string, string> topics[MAX_N]){
    set<string> frst, scnd;
    int y = x;
    for(int i = 0; i < N; i++){
        if(y%2){
            pair<string, string> tmp = topics[N-i-1];
            frst.insert(tmp.first);
            scnd.insert(tmp.second);
        }
        y /= 2;
    }
    y = x;
    /*for(set<string>::iterator it = frst.begin(); it != frst.end(); it++){
        cout << *it << endl;
    }cout << endl;*/
    for(int i = 0; i < N; i++){
        if(y%2 == 0){
            pair<string, string> tmp = topics[N-i-1];
            if(frst.count(tmp.first) == 0 || scnd.count(tmp.second) == 0)
                return false;
        }
        y /= 2;
    }
    return true;
}

int getNum(int x){
    int ans = 0;
    while(x > 0){
        if(x%2 == 0)
            ans++;
        x /= 2;
    }
    return ans;
}

int solve(int N, pair<string, string> topics[MAX_N]){
    int ans = 0;
    for(int i = 0; i < (1<<N); i++){
        if(isPossible(i, N, topics)){
            ans = max(getNum(i), ans);
        }
    }
    return ans;
}

int main()
{
    //freopen("../C-small-attempt2.in","r",stdin);
    freopen("../C-small-attempt3.in","r",stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        string s1, s2;
        pair<string, string> topics[MAX_N];
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> s1 >> s2;
            topics[i].first = s1;
            topics[i].second = s2;
        }
        cout << "Case #" << t << ": " << solve(N, topics) << endl;
    }
    return 0;
}
