#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#define zero(x) (((x)>0?(x):-(x))<eps)
//#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof((a)))
#define lld long long
#define INF 0x3f3f3f3f
#define eps 1e-6

using namespace std;

int n, m;
string str[19];
int num[19][19];
int c[19];
stack<int> s;
string ans;

int MAIN() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    ans = "";
    mem(num, 0);
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        num[a][b] = num[b][a] = 1;
    }
    for(int i = 0; i < n; i++) {
        c[i] = i + 1;
    }
    do{
//        for(int i = 0; i < n; i++) {
//            printf("%d ", c[i]);
//        }
//        putchar(10);
        bool ok = true;
        while(!s.empty()) s.pop();
        s.push(c[0]);
        string tmp = string(str[c[0] - 1]);
        for(int i = 1; i < n; i++) {
            while(!s.empty() && (num[s.top()][c[i]] == 0)) s.pop();
            if(!s.empty()) {
                tmp = string(tmp + str[c[i] - 1]);
                s.push(c[i]);
            } else {
                ok = false;
                break;
            }
        }
//        tmp = tmp + str[c[n - 1]];
//        cout << tmp << endl;
        if(ok == true) {
            if(ans == "") ans = tmp;
            else ans = min(ans, tmp);
        }
        ok = true;
        for(int i = 0; i < n; i++) {
            if(c[i] != n - i) ok = false;
        }
        if(ok) break;
        next_permutation(c, c + n);
    }while(true);
    cout << ans << endl;
    return 0;
}

int main() {
#ifdef LOCAL_TEST
    freopen("F:/ACMData.txt","r",stdin);
    freopen("F:/out.txt","w",stdout);
#endif
    int cases;
    scanf("%d", &cases);
    int cc = 1;
    while(cases--) {
        printf("Case #%d: ", cc++);
        MAIN();
    }
    return 0;
}
