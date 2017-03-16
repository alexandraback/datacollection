#include"db.h"
#include<stdio.h>


char db[ASIZE];

int main(){
    int n;
    char line[128];
    int i;
    read_db(db);
    scanf("%i\n",&n);
    for(i=0;i<n;i++){
        printf("Case #%i: ",i+1);
        int j;
        fgets(line,128,stdin);
        for(j=0;line[j]!='\n'&&line[j]!='\0';j++){
            if(isalpha(line[j]))
                putchar(db[line[j]-'a']);
            else
                putchar(line[j]);
        }
        putchar('\n');
    }
}
