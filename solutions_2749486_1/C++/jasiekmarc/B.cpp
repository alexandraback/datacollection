#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool dotrze(int sumak, int x, int y) {
    int odl = abs(x) + abs(y);
    return sumak >= odl && sumak % 2 == odl % 2;
}

void tcase() {
    int x, y;
    scanf("%d %d", &x, &y);
    int kroki = 0, sumak = 0;
    for(; !dotrze(sumak, x, y); kroki ++, sumak += kroki);
    vector<char> K;
    for(; kroki; kroki --) {
        sumak -= kroki;
        if(dotrze(sumak, x - kroki, y)) {
            K.push_back('E');
            x -= kroki;
        }
        else if(dotrze(sumak, x + kroki, y)) {
            K.push_back('W');
            x += kroki;
        }
        else if(dotrze(sumak, x, y - kroki)) {
            K.push_back('N');
            y -= kroki;
        }
        else if(dotrze(sumak, x, y + kroki)) {
            K.push_back('S');
            y += kroki;
        }
        else {
            printf("No to kicha\n");
            break;
        }
    }
    for(auto it = K.rbegin(); it != K.rend(); it ++)
        printf("%c", *it);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++) {
        printf("Case #%d: ", i);
        tcase();
        printf("\n");
    }
}