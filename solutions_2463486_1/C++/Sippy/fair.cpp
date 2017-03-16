#include<stdio.h>
#include <algorithm>
#include <string.h>

unsigned long long int ans[100], counta=0;

unsigned long long int reverseint(unsigned long long int x){
    unsigned long long int y = 0;
    while(x>0){
        y = y*10+(x%10);
        x = x/10;
    }
    return y;
}

bool isPalindrome(unsigned long long int x){
    unsigned long long int y = reverseint(x);
    if(x==y) return true;
    return false;
}

void calculate(){
    for(unsigned long long int i=1; i<=10000001; i++){
        unsigned long long int sqr = i*i;
        if(isPalindrome(i)&&isPalindrome(sqr)){
            ans[counta] = sqr;
            counta++;
        }
    }
}

int main(){
    int T;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    calculate();
    unsigned long long int a, b;
    //printf("Number of fair is %llu\n",counta);
    for(int t=0; t<T; t++){
        scanf("%llu%llu",&a,&b);
        unsigned long long int j,l;
        for(j=0; j<counta; j++){
            if(ans[j]>=a) break;
        }

        for(l=0; l<counta; l++){
            if(ans[l]>b) break;
        }
        printf("Case #%d: %llu\n",t+1,l-j);
    }
return 0;
}
