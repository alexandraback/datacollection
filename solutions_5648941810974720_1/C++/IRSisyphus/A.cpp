#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T;

int main(){
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t){
        int alphabet [30] = {0};
        int output [10] = {0};
        string ins;
        cin >> ins;

        for (int i = 0; i < ins.length(); ++i){
            alphabet[ins[i]-'A']++;
        }
        output[0] = alphabet['Z'-'A'];
        output[2] = alphabet['W'-'A'];
        output[4] = alphabet['U'-'A'];
        output[6] = alphabet['X'-'A'];
        output[8] = alphabet['G'-'A'];
        output[1] = alphabet['O'-'A'] - output[0] - output[2] - output[4];
        output[3] = alphabet['T'-'A'] - output[2] - output[8];
        output[5] = alphabet['F'-'A'] - output[4];
        output[7] = alphabet['V'-'A'] - output[5];
        output[9] = alphabet['I'-'A'] - output[5] - output[6] - output[8];

        printf("Case #%d: ", t);

        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < output[i]; ++j)
                cout << i;
        }


        printf("\n");
    }
}
