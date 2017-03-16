#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int DUZO = 1000010;
int n;
char str[DUZO];
int blocks[DUZO];

bool vovel(char c);

int main() {
    int t;

    scanf("%d", &t);
    for(int test_case = 1; test_case <= t; test_case++) {
        int len;
        scanf("%s %d", str, &n);
        len = strlen(str);

        if(vovel(str[0]))
            blocks[0] = 0;
        else
            blocks[0] = 1;

        for(int i = 1; i < len; i++) {
            if(vovel(str[i]))
                blocks[i] = 0;
            else
                blocks[i] = blocks[i - 1] + 1;
        }

        unsigned long long int result = 0;
        int to_enlarge = 0;
        int last_block_end = -1;
        for(int i = 0; i < len; i++) {
            if(blocks[i] >= n) {
                last_block_end = i;
                break;
            }
        }

        // TODO: what if last_block_end == -1?
        if(last_block_end != -1) {
            to_enlarge = last_block_end - n + 2;
            result = to_enlarge;
            //printf("Starting: to_enlarge = result = %d, last_block_end = %d\n", to_enlarge, last_block_end);
            for(int i = last_block_end + 1; i < len; i++) {
                if(blocks[i] >= n) {
                    to_enlarge += i - n + 2 - (last_block_end - n + 2);
                    last_block_end = i;
                }

                result += to_enlarge;
            }
        }

        printf("Case #%d: %llu\n", test_case, result);
    }

    return 0;
}

bool vovel(char c) {
    return c == 'a' ||
           c == 'e' ||
           c == 'i' ||
           c == 'o' ||
           c == 'u';
}

