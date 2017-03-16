#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char cod[][100] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv",
                "y qee"};
char ori[][100] = {"our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up",
                "a zoo"};
char map[256];
int main(){
    memset(map, -1, sizeof(map));
    for(int i=0;i<4;i++){
        int len = strlen(cod[i]);
        for(int j=0;j<len;j++){
            map[cod[i][j]] = ori[i][j];
        }
    }
    int sum=0, sum2=0;
    for(int i='a';i<='z';i++){
        sum +=i;
        if(i!='z')sum2+=map[i];
    }
    map['z'] = sum-sum2;
    int cas;
    scanf("%d", &cas);
    char inp[1010];
    gets(inp);
    for(int iii=0;iii<cas;iii++){
        gets(inp);
        int len = strlen(inp);
        for(int i=0;i<len;i++){
            inp[i] = map[inp[i]];
            if(inp[i] == -1) inp[i] = ' ';
        }
        printf("Case #%d: %s\n", iii+1, inp);
    }
    scanf(" ");
    return 0;   
}
                


