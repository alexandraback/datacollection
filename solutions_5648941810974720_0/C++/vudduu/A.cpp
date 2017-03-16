// vudduu - Codejam 2016 Round 1B
// Problem A
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

const string nums[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void solve() {
    string s;
    cin >> s;

    vector<int> v(10, 0);
    vector<int> letters(300, 0);
    F(i, s.S) {
        letters[s[i]]++;
    }
    v[0] += letters['Z']; // 0
    F(i, nums[0].S) letters[nums[0][i]] -= v[0];

    v[2] += letters['W']; // 2
    F(i, nums[2].S) letters[nums[2][i]] -= v[2];

    v[6] += letters['X']; // 6
    F(i, nums[6].S) letters[nums[6][i]] -= v[6];

    v[8] += letters['G']; // 8
    F(i, nums[8].S) letters[nums[8][i]] -= v[8];

    v[4] += letters['U']; // 4
    F(i, nums[4].S) letters[nums[4][i]] -= v[4];

    v[7] += letters['S']; // 7
    F(i, nums[7].S) letters[nums[7][i]] -= v[7];

    v[5] += letters['V']; // 5
    F(i, nums[5].S) letters[nums[5][i]] -= v[5];

    v[1] += letters['O']; // 1
    F(i, nums[1].S) letters[nums[1][i]] -= v[1];


    if(letters['N'] > 0) {
        v[9] += letters['N'] / 2; // 9
        F(i, nums[9].S) letters[nums[9][i]] -= v[9];
    }

    v[3] += letters['H']; // 3
    F(i, nums[3].S) letters[nums[3][i]] -= v[3];

    F(i, letters.S) {
        if(letters[i]) cout << "ERROR" << endl;
    }

    F(i, v.S) {
        while(v[i] > 0) {
            printf("%d", i);
            v[i]--;
        }
    }
    printf("\n");
}

int main(){
	// freopen("in.txt", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}
