#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <random>
#include <iostream>
#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif

using namespace std;
typedef pair<int, int> ii;
int nTest;
const string DIGIT[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string res;
string s;
int a[111];
int f[111];

int dq(int num){
    if (num > 9){
        if (res.length() == s.length()){
            string temp = res;
            sort(temp.begin(), temp.end());

            if (temp == s) return 1;
            return 0;
        }
        return 0;
    }
    if (res.length() > s.length()) return 0;

    string temp = res;
    for (int i = 0; i <= 700; i++){
        f[num] = i;
        
        if (i > 0) res += DIGIT[num];

        if (res.length() > s.length()) {
            res = temp;
            break;
        }

        if (dq(num + 1)) return 1;
    }
    res = temp;
    return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &nTest);
    for (int test = 1; test <= nTest; test++){
        printf("Case #%d: ", test);
        
        cin >> s;
        sort(s.begin(), s.end());

        res.clear();
        for (int i = 0; i < 100; i++) {
            a[i] = 0;
            f[i] = 0;
        }

        dq(0);
        for (int i = 0 ; i < 10; i++){
            for (int j = 0; j < f[i]; j++){
                printf("%d", i);
            }
        }
        printf("\n");
        // cout<<s<<endl;
        // cout<<res<<endl;
    }
    

    return 0;
}