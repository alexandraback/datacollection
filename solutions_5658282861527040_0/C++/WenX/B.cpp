//This template is CopyRight By WenX(R), Southeast University, China
//wenxiao1992@gmail.com
//This is for GCJ 2014 Round 1B

#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)

//SYS
#include <iostream>
#include <string>/////////
#include <cstring>////////This two
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
//ALG
#include <list>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int cc, tt;
    int ables;
    cin >> tt;
    for (cc = 1; cc <= tt; cc++){
        int a, b, k;
        long long ans = 0;
        cin >> a >> b >> k;

        for (int i = 0; i < a;i++)
        for (int j = 0; j < b;j++)
        if ((i&j) < k)
            ans++;
        cout << "Case #" << cc << ": " << ans << endl;
    }
    return 0;
}