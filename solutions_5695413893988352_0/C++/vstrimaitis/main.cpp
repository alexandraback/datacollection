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
#define MAX_N 100000
using namespace std;

ll minDiff = INF;
string A, B;

ll toInt(string x){
    ll ans = 0;
    for(int i = 0; i < x.length(); i++)
        ans = ans*10 + x[i]-'0';
    return ans;
}

void solve(string s1, string s2){
    bool foundQ = false;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == '?'){
            foundQ = true;
            for(int j = '0'; j <= '9'; j++){
                s1[i] = j;
                solve(s1, s2);
            }
            s1[i] = '?';
        }
    }
    if(foundQ)
        return ;
    for(int i = 0; i < s2.length(); i++){
        if(s2[i] == '?'){
            foundQ = true;
            for(int j = '0'; j <= '9'; j++){
                s2[i] = j;
                solve(s1, s2);
            }
            s2[i] = '?';
        }
    }

    if(!foundQ){
        ll a = 0, b = 0;
        for(int i = 0; i < s1.length(); i++){
            a = a*10 + s1[i]-'0';
            b = b*10 + s2[i]-'0';
        }
        ll diff = abs(a-b);
        //cout << s1 << " " << s2 << endl;
        if(diff < minDiff){
            minDiff = diff;
            A = s1;
            B = s2;
        }else if(diff == minDiff){
            if(a < toInt(A))
                A = s1;
            if(b < toInt(B))
                B = s2;
        }
    }
}

int main()
{
    freopen("../B-small-attempt2.in","r",stdin);
    freopen("output.txt", "w", stdout);
    int T;
    string s1, s2;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> s1 >> s2;
        cout << "Case #" << t << ": ";
        minDiff = INF;
        solve(s1, s2);
        cout << A << " " << B << endl;
    }
    return 0;
}
