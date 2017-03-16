#include"db.h"
#include<stdio.h>
#include<ctype.h>


char db[ASIZE];

const char* example[]={
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"y qee"
};

const char* example_output[]={
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up",
"a zoo"
};



int main(){
    int i;
    read_db(db);
    for(i=0;i<4;i++){
        int x;

        for(x=0;example_output[i][x]!=0;x++){
            char t = example_output[i][x];
            char c = example[i][x];
            if(!isalpha(c))continue;
            db[c-'a']=t;
        }
    }
    write_db(db);
}
