#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

bool _flag[2000005];
const int COMB[] = {0, 0, 1, 3, 6, 10, 15};

void Rotate (string& str_num) {
    rotate(str_num.begin(), str_num.begin()+1, str_num.end());
}

int main () {
    freopen("A-small.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int case_cnt;
    scanf("%d", &case_cnt);

    int n;
    int m;
    int result;
    for (int crt_case = 1; crt_case <= case_cnt; ++crt_case) {
        result = 0;
        memset(_flag, 0, sizeof(_flag));
        scanf("%d %d", &n, &m);

        for (int num = n; num <= m; ++num) {
            stringstream converter;
            converter << num;
            string str_num = converter.str();
            if (!_flag[num]) {
                int pairs = 1;
                _flag[num] = true;

                for (int rotate_num = 0; rotate_num < str_num.size() - 1; ++rotate_num) {
                    Rotate(str_num);
                    if (str_num[0] == '0')
                        continue;

                    int rotated_num = atoi(str_num.c_str());

                    if (!_flag[rotated_num] &&
                        rotated_num >= n && rotated_num <= m)
                        pairs++;

                    _flag[rotated_num] = true;
                }
                result += COMB[pairs];
            }
        }

        printf("Case #%d: %d\n", crt_case, result);
    }

    return 0;
}