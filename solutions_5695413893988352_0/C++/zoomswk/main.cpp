#include <stdio.h>
#include <string>
using namespace std;

char s1[105];
char s2[105];
int len1, len2;

int abs(int a){ if(a < 0) return -a; return a; }

int valid(int a, int b){
    char val[105];
    char rval[105];
    val[0] = 0, val[1] = 0, val[2] = 0;
    rval[0] = 0, rval[1] = 0, rval[2] = 0;
    int ptr;
    ptr = 0;
    if(a == 0) val[ptr++] = '0';
    while(a > 0){
        val[ptr++] = a%10 + '0';
        a /= 10;
    }
    for(int i=0; i<ptr; i++) rval[i+len1-ptr] = val[ptr-i-1];
    for(int i=0; i<len1; i++) if(!rval[i]) rval[i] = '0';
    for(int i=0; i<len1; i++){
        if(rval[i] != s1[i] && s1[i] != '?') return 0;
    }
    
    val[0] = 0, val[1] = 0, val[2] = 0;
    rval[0] = 0, rval[1] = 0, rval[2] = 0;
    ptr = 0;
    if(b == 0) val[ptr++] = '0';
    while(b > 0){
        val[ptr++] = b%10 + '0';
        b /= 10;
    }
    for(int i=0; i<ptr; i++) rval[i+len2-ptr] = val[ptr-i-1];
    for(int i=0; i<len2; i++) if(!rval[i]) rval[i] = '0';
    for(int i=0; i<len2; i++){
        if(rval[i] != s2[i] && s2[i] != '?') return 0;
    }
    return 1;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        int min = 1000000;
        int mina, minb;
        int max1, max2;
        scanf("%s", s1);
        for(len1=0; s1[len1]; len1++);
        scanf("%s", s2);
        for(len2=0; s2[len2]; len2++);
        if(len1 == 1) max1 = 9;
        if(len1 == 2) max1 = 99;
        if(len1 == 3) max1 = 999;
        if(len2 == 1) max2 = 9;
        if(len2 == 2) max2 = 99;
        if(len2 == 3) max2 = 999;
        for(int i=0; i<=max1; i++){
            for(int j=0; j<=max2; j++){
                if(abs(i-j) < min && valid(i, j)){ min = abs(i-j); mina = i; minb = j; }
            }
        }
        printf("Case #%d: ", test);
        if(mina < 10) for(int i=0; i<len1-1; i++) printf("0");
        else if(mina < 100) for(int i=0; i<len1-2; i++) printf("0");
        else if(mina < 1000) for(int i=0; i<len1-3; i++) printf("0");
        printf("%d ", mina);
        if(minb < 10) for(int i=0; i<len2-1; i++) printf("0");
        else if(minb < 100) for(int i=0; i<len2-2; i++) printf("0");
        else if(minb < 1000) for(int i=0; i<len2-3; i++) printf("0");
        printf("%d\n", minb);
    }
}