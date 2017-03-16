#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;

char s[1000008];

bool IsVowels(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main(){
    int T, k;
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        scanf("%s%d",s,&k);
        int n = strlen(s);
        int st = 0, num = 0;
        long long total = 0;
        for(int i=0; i<n; i++){
            if( !IsVowels(s[i]) ) num++;
            else num = 0;
            if( num>=k ){
                total += (long long)(i-k+1-st+1)*(n-1-i+1);
                st = i-k+1+1; num-=1;
            }
        }
        cout<<"Case #"<<t<<": "<<total<<endl;
    }
    return 0;
}

