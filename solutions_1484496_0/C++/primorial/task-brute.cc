#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <sstream>
#include <cstdio>
#include <iostream>

using namespace std;

bool next_take(vector<int>& takes) {
    int sz = takes.size();
    int carry = 1;

    for (int i = 0; i <= sz; ++i) {
        if (i == sz && carry == 1) {
            return false;
        }

        takes[i] += carry;
        carry = 0;

        if (takes[i] > 1) {
            takes[i] = 0;
            carry = 1;
        } else {
            break;
        }
    }

    return true;
}

const int LIM = 3000000;

int main()
{
    int N;
    int T;
    vector<int> elems;
    vector<int> takes;
    vector<int> sums;
    vector<int> prevs;
    bool isans;

    scanf("%d", &T);

    for (int test = 1; test <= T; ++test) {
        scanf("%d", &N);

        elems.resize(N);
        takes.assign(N, 0);
        isans = false;

        for (int i = 0; i < N; ++i) {
            scanf("%d", &elems[i]);
        }

        do {
            int s = 0;
            sums.assign(LIM, 0);
            prevs.assign(LIM, 0);

            for (int i = 0; i < N; ++i) {
                if (takes[i] == 1) {
                    s += elems[i];
                }
            }

            if (s == 0)
                continue;

            sums[0] = 1;

            for (int i = 0; i < N; ++i) {
                if (takes[i] == 0) {
                    for (int j = LIM - 1; j >= elems[i]; --j) {
                        if (sums[j - elems[i]] && ! sums[j]) {
                            sums[j] = 1;
                            prevs[j] = i;
                        }
                    }
                }
            }

            if (sums[s]) {
                printf("Case #%d:\n", test);

                for (int i = 0; i < N; ++i) {
                    if (takes[i] == 1) {
                        printf("%d ", elems[i]);
                    }
                }
                printf("\n");

                int id;

                while (s > 0) {
                    id = prevs[s];
                    s -= elems[id];
                    printf("%d ", elems[id]);
                }

                printf("\n");
                
                isans = true;
                break;
            }
        } while (next_take(takes));

        if (!isans) {
            printf("Case #%d: Impossible\n", test);
        }
    }

    return 0;
}
