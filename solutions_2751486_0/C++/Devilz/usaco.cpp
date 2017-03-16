/*
ID: ankitgu1
LANG: C++
TASK: holstein
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

FILE *in,*out;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

typedef long long LL;
typedef long L;

int is_prime(long long num) {
    for(long long t=2; t<=sqrt(num); t++) {
        if(num%t==0)return 0;
    }
    return 1;
}
LL gcd(LL a,LL b) {
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
int dec_compare (const void * a, const void * b) {
    return ( - *(int*)a + *(int*)b );
}
//////////////////////////

#define DEBUG 0

char str[1000];

int isVowel(char c) {
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 1;
    return 0;
}

int main() {
    in=fopen("input.in","r");
    out=fopen("output.out","w");
    int cases;
    fscanf(in,"%d",&cases);
    for(int test=0; test<cases; test++) {
        memset(str,'\0',sizeof(str));
        fscanf(in,"%s",str);
        if(DEBUG)cout<<str<<endl;
        int num;
        fscanf(in,"%d",&num);
        int ans=0;
        for(int t=0; t<strlen(str); t++) {
            int score=0,pre=0,highest=0;
            for(int tt=t; tt<strlen(str); tt++) {
                if(DEBUG) {
                    for(int deb=t; deb<=tt; deb++)cout<<str[deb];
                    cout<<endl;
                }
                if(isVowel(str[tt])) {
                    score=0;
                    pre=0;
                } else {
                    score++;
                    highest = MAX(highest,score);
                }
                if(highest>=num) {
                    if(DEBUG){
                        cout<<"passed for"<<endl;
                        for(int deb=t;deb<=tt;deb++)cout<<str[deb];
                        cout<<endl;
                    }
                    ans++;
                }
            }
        }if(DEBUG)cout<<"ans is "<<ans<<endl;
        fprintf(out,"Case #%d: %d\n",test+1,ans);
    }
    fclose(in);
    fclose(out);
    return 0;
}
