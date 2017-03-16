#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

#define MAXN 100100
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> pr;
typedef long long ll;

int t , n;
string s[21];
string st;
int ch[30] , ch1[30];
int prt[100];

int main()
{
    freopen("B-small.in","r",stdin);
    freopen("outputB.txt","w",stdout);

    scanf("%d",&t);
    for (int tc = 1; tc <= t; tc++) {
        int ans = 0;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++) {
            prt[i] = i;
            for (int j = 0; j < s[i].length(); j++)
                ch[s[i][j] - 97]++;
        }
        do {
            st = "";
            for (int i = 0; i < n; i++) st += s[prt[i]];
            int l = st.length();
            int chk = 1;
            for (int i = 0; i < 30; i++) ch1[i] = ch[i];
              char c = st[0]; ch1[c - 97]--;
            for (int i = 1; i < l && chk; i++) {
                if (st[i] == c)
                    ch1[c - 97]--;
                else {
                    if (ch1[c - 97] != 0) chk = 0;
                    ch1[st[i] - 97]--;
                }
                c = st[i];
            }
            if (chk) ans++;
        } while (next_permutation(prt , prt + n));
        printf("Case #%d: %d\n",tc,ans);
        memset(ch , 0 , sizeof(ch));
    }

    return 0;
}

