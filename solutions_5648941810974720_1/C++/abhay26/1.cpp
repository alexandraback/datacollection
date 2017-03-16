/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define pll pair < ll, ll >
#define pill pair< int, pll >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
int cnt[26];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        printf("Case #%d: ", z);
        for(int i=0;i<26;i++)
            cnt[i] = 0;
        string s;
        cin >> s;
        for(int i=0;i<s.length();i++)
        {
            cnt[s[i]-'A']++;
        }
        vector<int> V;
        while(cnt['Z'-'A'] > 0)
        {
            V.push_back(0);
            cnt['Z'-'A']--;
            cnt['E'-'A']--;
            cnt['R'-'A']--;
            cnt['O'-'A']--;
        }
        while(cnt['X'-'A'] > 0)
        {
            V.push_back(6);
            cnt['S'-'A']--;
            cnt['I'-'A']--;
            cnt['X'-'A']--;
        }
        while(cnt['G'-'A'] > 0)
        {
            V.push_back(8);
            cnt['E'-'A']--;
            cnt['I'-'A']--;
            cnt['G'-'A']--;
            cnt['H'-'A']--;
            cnt['T'-'A']--;
        }
        while(cnt['W'-'A'] > 0)
        {
            V.push_back(2);
            cnt['T'-'A']--;
            cnt['W'-'A']--;
            cnt['O'-'A']--;
        }
        while(cnt['H'-'A'] > 0)
        {
            V.push_back(3);
            cnt['T'-'A']--;
            cnt['H'-'A']--;
            cnt['R'-'A']--;
            cnt['E'-'A']--;
            cnt['E'-'A']--;
        }
        while(cnt['U'-'A'] > 0)
        {
            V.push_back(4);
            cnt['F'-'A']--;
            cnt['O'-'A']--;
            cnt['U'-'A']--;
            cnt['R'-'A']--;
        }
        while(cnt['S'-'A'] > 0)
        {
            V.push_back(7);
            cnt['S'-'A']--;
            cnt['E'-'A']--;
            cnt['V'-'A']--;
            cnt['E'-'A']--;
            cnt['N'-'A']--;
        }
        while(cnt['V'-'A'] > 0)
        {
            V.push_back(5);
            cnt['F'-'A']--;
            cnt['I'-'A']--;
            cnt['V'-'A']--;
            cnt['E'-'A']--;
        }
        while(cnt['O'-'A'] > 0)
        {
            V.push_back(1);
            cnt['O'-'A']--;
            cnt['N'-'A']--;
            cnt['E'-'A']--;
        }
        while(cnt['N'-'A'] > 0)
        {
            V.push_back(9);
            cnt['N'-'A']--;
            cnt['I'-'A']--;
            cnt['N'-'A']--;
            cnt['E'-'A']--;
        }
        sort(V.begin(), V.end());
        for(int i=0;i<V.size();i++)
            cout << V[i];
        cout << endl;
    }
    return 0;
}
