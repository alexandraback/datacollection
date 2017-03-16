#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int tc, i, j;
string s;

char map[100];

int main(void){
    freopen("speak.in", "r", stdin);
    freopen("speak.out", "w", stdout);
    
    map['a'] = 'y';
    map['b'] = 'h';
    map['c'] = 'e';
    map['d'] = 's';
    map['e'] = 'o';
    map['f'] = 'c';
    map['g'] = 'v';
    map['h'] = 'x';
    map['i'] = 'd';
    map['j'] = 'u';
    map['k'] = 'i';
    map['l'] = 'g';
    map['m'] = 'l';
    map['n'] = 'b';
    map['o'] = 'k';
    map['p'] = 'r';
    map['q'] = 'z';
    map['r'] = 't';
    map['s'] = 'n';
    map['t'] = 'w';
    map['u'] = 'j';
    map['v'] = 'p';
    map['w'] = 'f';
    map['x'] = 'm';
    map['y'] = 'a';
    map['z'] = 'q';
    map[' '] = ' ';
    
    scanf("%d\n", &tc);
    
    for (i = 1; i <= tc; i++){
        printf("Case #%d: ", i);
        
        getline(cin, s);
        for (j = 0; j < s.length(); j++)
            printf("%c", map[s[j]]);
        printf("\n");
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
    
