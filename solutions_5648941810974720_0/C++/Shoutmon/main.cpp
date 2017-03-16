#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 2010;
char str[maxn];
int hashTable[260], num[10];

int main() {
//    freopen("A-small.in", "r", stdin);
//    freopen("A-small.out", "w", stdout);
    int T, tcase = 1;
    scanf("%d", &T);
    while(T--) {
        char str[maxn];
        scanf("%s", str);
        memset(hashTable, 0, sizeof(hashTable));
        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            hashTable[str[i]]++;
        }
        num[0] = hashTable['Z'];
        hashTable['Z'] -= num[0], hashTable['E'] -= num[0], hashTable['R'] -= num[0], hashTable['O'] -= num[0];
        num[2] = hashTable['W'];
        hashTable['T'] -= num[2], hashTable['W'] -= num[2], hashTable['O'] -= num[2];
        num[4] = hashTable['U'];
        hashTable['F'] -= num[4], hashTable['O'] -= num[4], hashTable['U'] -= num[4], hashTable['R'] -= num[4];
        num[6] = hashTable['X'];
        hashTable['S'] -= num[6], hashTable['I'] -= num[6], hashTable['X'] -= num[6];
        num[8] = hashTable['G'];
        hashTable['E'] -= num[8], hashTable['I'] -= num[8], hashTable['G'] -= num[8], hashTable['H'] -= num[8], hashTable['T'] -= num[8];
        num[1] = hashTable['O'];
        hashTable['O'] -= num[1], hashTable['N'] -= num[1], hashTable['E'] -= num[1];
        num[3] = hashTable['R'];
        hashTable['T'] -= num[3], hashTable['H'] -= num[3], hashTable['R'] -= num[3], hashTable['E'] -= num[3], hashTable['E'] -= num[3];
        num[7] = hashTable['S'];
        hashTable['S'] -= num[7], hashTable['E'] -= num[7], hashTable['V'] -= num[7], hashTable['E'] -= num[7], hashTable['N'] -= num[7];
        num[5] = hashTable['V'];
        hashTable['F'] -= num[5], hashTable['I'] -= num[5], hashTable['V'] -= num[5], hashTable['E'] -= num[5];
        num[9] = hashTable['I'];
        hashTable['N'] -= num[9], hashTable['I'] -= num[9], hashTable['N'] -= num[9], hashTable['E'] -= num[9];
        printf("Case #%d: ", tcase++);
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j < num[i]; j++) {
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}