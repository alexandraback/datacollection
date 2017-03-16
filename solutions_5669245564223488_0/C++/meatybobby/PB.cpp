#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    string s[200];
    char c[26],pre;
    int num[200];
    int n,t,T,i,sum,j,ok,now,next;
    scanf("%d",&T);
    for(t=1;t<=T;t++) {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            cin>>s[i];
        sum=0;
        for(i=0;i<n;i++) num[i]=i;
        do {
            for(i=0;i<26;i++) c[i]=0;
            ok=1;
            pre=0;
            for(i=0;ok&&i<n;i++) {
                now=num[i];
                for(j=0;j<s[now].length();j++)
                    if(s[now][j]!=pre) {
                        if(pre) {
                            if(c[pre-'a']) {
                                ok=0;
                                break;
                            }
                            c[pre-'a']=1;
                        }
                        pre=s[now][j];
                    }
            }
            if(ok&&c[pre-'a']==0) sum++;
        }while(next_permutation(num,num+n));
        printf("Case #%d: %d\n",t,sum);
    }
    return 0;
}
