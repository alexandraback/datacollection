#include<cstdio>
#include<cmath>
#include<cstring>
#include<time.h>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main(){
    int T, n, s, p, t;
    scanf("%d",&T);
    for(int cs=1; cs<=T; cs++){
        scanf("%d%d%d",&n,&s,&p);
        int num = 0;
        for(int i=0; i<n; i++){
            scanf("%d",&t);
            if( t>=max(p,p+p-1+p-1) ) num++;
            else if( t>=max(p,p+p-2+p-2) ){
                if( s>0 ){ num++; s--; }
            }
        }
        printf("Case #%d: %d\n",cs,num);
    }
    return 0;
}

/*
char s[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char t[] = {"our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"};

char r[27]={"yhesocvxduiglbkrztnwjpfmaq"};

int main(){
    for(int i=0; i<strlen(s); i++){
        if( 'a'<=s[i] && s[i]<='z' ) r[s[i]-'a'] = t[i];
    }
    //cout<<r<<endl;
    char in[1000];
    int t;
    scanf("%d\n",&t);
    for(int cs=1; cs<=t; cs++){
        gets(in);
        printf("Case #%d: ",cs);
        for(int i=0; i<strlen(in); i++){
            if( 'a'<=in[i] && in[i]<='z' ) printf("%c",r[in[i]-'a']);
            else printf("%c",in[i]);
        }printf("\n");
    }
    return 0;
}*/
