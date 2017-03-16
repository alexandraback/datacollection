#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define INF 1000000000;
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define EPS                         1e-9
#define all(a)                      a.begin(), a.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main(){
    int tc;
    scanf("%d",&tc);
    string s,maxs;
    getline(cin,s);
    for(int tci=1;tci<=tc;tci++){
        getline(cin,s);
        for(int i=0;i<s.length();i++){
            if(i==0) maxs = s[i];
            else if(maxs[0] > s[i]) maxs += s[i];
            else if(maxs[0] <= s[i]) maxs = s[i]+maxs;
        }
        printf("Case #%d: %s\n",tci,maxs.c_str());
    }
}