#include <stdio.h>
#include <string.h>
#define MAX 1000000

int vow(char inp){
    if(inp == 'a' || inp == 'e' || inp == 'i' || inp == 'o' || inp == 'u')
        return 1;
    else
        return 0;
}

int chk(char *inp, int n){
    int i=0;
    while (i<n){
        if (vow(*(inp+i++))) return 0;
    }
    // printf(">> it is a string %s\n", inp);
    return 1;
}

int main(){
    
    int t,i,j,flag;
    long int n, sum;
    char str[MAX];
    
    scanf("%d",&t);
    for ( i = 0; i < t; ++i)
    {
        sum = 0;
        flag = 1;
        scanf("%s%ld", str, &n);
        for(j=0; j<=strlen(str)-n; j++){
            if(chk(str+j,n)) { sum += flag*(strlen(str)-n-j+1); flag =0; }
            flag++;
        }
        printf("Case #%d: %ld\n", i+1, sum);
    }
    return 1;
}