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
}
