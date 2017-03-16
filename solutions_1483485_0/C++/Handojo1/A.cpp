#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char ubah[255];
char kata[150];
int kasus,panjang;

int main() {
    ubah['a'] = 'y';
    ubah['b'] = 'h';
    ubah['c'] = 'e';
    ubah['d'] = 's';
    ubah['e'] = 'o';
    ubah['f'] = 'c';
    ubah['g'] = 'v';
    ubah['h'] = 'x';
    ubah['i'] = 'd';
    ubah['j'] = 'u';
    ubah['k'] = 'i';
    ubah['l'] = 'g';
    ubah['m'] = 'l';
    ubah['n'] = 'b';
    ubah['o'] = 'k';
    ubah['p'] = 'r';
    ubah['q'] = 'z';
    ubah['r'] = 't';
    ubah['s'] = 'n';
    ubah['t'] = 'w';
    ubah['u'] = 'j';
    ubah['v'] = 'p';
    ubah['w'] = 'f';
    ubah['x'] = 'm';
    ubah['y'] = 'a';
    ubah['z'] = 'q';
    
    scanf("%d\n",&kasus);
    for (int l=1;l<=kasus;++l) {
        gets(kata);
        panjang = strlen(kata);
        for (int i=0;i<panjang;++i)
            if ((kata[i] != ' ')&&(ubah[kata[i]])) kata[i] = ubah[kata[i]];
            
        printf("Case #%d: %s\n",l,kata);
    }
    return 0;
}
