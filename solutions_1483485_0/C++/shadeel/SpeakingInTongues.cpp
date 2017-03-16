#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0;
    char mapping[26] = {0}, in[105];
    char exin[3][60]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                    "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    char exout[3][60]={"our language is impossible to understand",
                    "there are twenty six factorial possibilities",
                    "so it is okay if you want to just give up"};
    mapping['y'-'a'] = 'a';
    mapping['e'-'a'] = 'o';
    mapping['q'-'a'] = 'z';
    mapping['z'-'a'] = 'q';
    for(int i=0; i<3; ++i){
        int j = strlen(exin[i]);
        for(int k=0; k<j; ++k)
        if( exin[i][k] != ' ' ){
        /*if( mapping[exin[i][k]-'a'] && mapping[exin[i][k]-'a']!=exout[i][k] )
            printf("alert %c has been stored as %c, now input %c\n", exin[i][k], mapping[exin[i][k]-'a'], exout[i][k]);
        else*/    mapping[exin[i][k]-'a'] = exout[i][k];
        }
    }
    /*for(int i=0; i<26; ++i)
    printf("%c -> %c\n", 'a'+i, mapping[i]);*/
    
    scanf("%d", &cas);
    getchar();
    while( cas-- ){
        printf("Case #%d: ", ++c);
        gets(in);
        int len = strlen(in);
        for(int i=0; i<len; ++i)
        if( in[i]==' ' )    putchar(' ');
        else                putchar(mapping[in[i]-'a']);
        putchar('\n');
    }
    
    return 0;
}
