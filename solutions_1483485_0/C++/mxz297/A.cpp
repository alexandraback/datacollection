#include <cstdio>
#include <cstring>

char map[26];
int t;

char str[100];
void analyze(char *a, char *b){
     for (int i = 0; a[i]; ++i)
         if (a[i] != ' ')
            map[a[i]-'a'] = b[i];
}

int main(){
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);    
    map['a'-'a'] = 'y';
    map['o'-'a'] = 'e';
    map['z'-'a'] = 'q';
    map['q'-'a'] = 'z';    
    analyze("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
    analyze("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
    analyze("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");    
    int cases;
    scanf("%d",&t); gets(str);
    for (int cases = 1; cases <= t; ++cases){
        gets(str);
        for (int i = 0; str[i]; ++i)
          if (str[i] != ' ')
             str[i] = map[str[i]- 'a'];
        printf("Case #%d: ", cases);
        puts(str);
    }
}
