#include"db.h"

#include<stdio.h>


int read_db(char* buf){
    int i;
    FILE* f;
    int ret;

    f= fopen("db","r");
    for(i=0;i<ASIZE;i++)
        buf[i]='?';
    if(f==NULL)return -1;
    ret = fread(buf,1,ASIZE,f);
    fclose(f);
    return ret;
}

int write_db(const char* buf){
    FILE* f;
    int ret;
    f = fopen("db","w");
    if(f==NULL)return -1;
    ret = fwrite(buf,1,ASIZE,f);
    fclose(f);
    return ret;
}
