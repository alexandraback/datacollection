#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int mapping[256];
char text[1111];

int main() {
    mapping['a'] = 121;
mapping['b'] = 104;
mapping['c'] = 101;
mapping['d'] = 115;
mapping['e'] = 111;
mapping['f'] = 99;
mapping['g'] = 118;
mapping['h'] = 120;
mapping['i'] = 100;
mapping['j'] = 117;
mapping['k'] = 105;
mapping['l'] = 103;
mapping['m'] = 108;
mapping['n'] = 98;
mapping['o'] = 107;
mapping['p'] = 114;
mapping['q'] = 'z';
mapping['r'] = 116;
mapping['s'] = 110;
mapping['t'] = 119;
mapping['u'] = 106;
mapping['v'] = 112;
mapping['w'] = 102;
mapping['x'] = 109;
mapping['y'] = 97;
mapping['z'] = 'q';
mapping[' '] = ' ';


    int numberOfCases;
    scanf("%d",&numberOfCases); gets(text);
    for(int testNo=1; testNo<=numberOfCases; testNo++) {
        gets(text);
        printf("Case #%d: ", testNo);
        int n = strlen(text);

        for(int i=0; i<n; i++) text[i] = mapping[text[i]];
        puts(text);
    }
}
