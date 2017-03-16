#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <stack>
#include <deque>

using namespace std;

//int S[601][601];
//const int org = 300;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;
typedef pair<PII, PIS> PIIPIS;


int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);

    int T;
    int x, y;
    scanf("%d", &T);
    for(int prob = 1; prob <= T; prob++) {
        printf("Case #%d: ", prob);
        scanf("%d %d", &x, &y);
        string Answer;
        if (x > 0) {while (x){Answer += "WE"; x--;} }
        else {while (x) {Answer += "EW"; x++;}}
        if (y > 0) {while (y){Answer += "SN"; y--;} }
        else {while (y) {Answer += "NS"; y++;} }
        cout << Answer << endl;
    }
    return 0;
}

