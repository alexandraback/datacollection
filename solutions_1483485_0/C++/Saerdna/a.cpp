#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdio>
#include<string>
using namespace std;
map<char,char>mark;
void train(string pre,string now){
    for(int i=0;i<pre.length();i++){
        if(mark.find(now[i])==mark.end()){
            mark[now[i]] = pre[i];
        }
    }
}
int main(){
    
    train("our language is impossible to understand","ejp mysljylc kd kxveddknmc re jsicpdrysi");
    train("there are twenty six factorial possibilities","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    train("so it is okay if you want to just give up","de kr kd eoya kw aej tysr re ujdr lkgc jv");
    train("qz","zq"); 
    int T;
    scanf("%d",&T);
    for(int tt=0;tt<T;tt++){
        printf("Case #%d: ",tt+1);
        char buff[120];
        do{gets(buff);}while(strlen(buff)==0);
        int len = strlen(buff);
        for(int i=0;i<len;i++){
            printf("%c",mark[buff[i]]);
        }
        puts("");
    }
}
