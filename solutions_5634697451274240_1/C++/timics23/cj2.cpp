#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#define pb push_back
using namespace std;

int T;
string s;


int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        cin>>s;
        int N = 1;
        for(int i=1;i<s.size();++i) {
            if(s[i] != s[i-1]) ++N;
        }
        if(s.back() == '+') {
            printf("%d\n",N-1);
        } else {
            printf("%d\n",N);
        }
    }
}
