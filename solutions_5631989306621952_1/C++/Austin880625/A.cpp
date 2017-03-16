#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAXN 1005

using namespace std;

char S[MAXN];
char ANS[MAXN*3];
int L,R;

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%s",S);
        char cur=0;
        int len=strlen(S);
        L=1500;R=1501;
        for(int i=0;i<len;i++)
        {
            if(S[i]>=cur)
            {
                cur=S[i];
                ANS[L--]=cur;
            }
            else
            {
                ANS[R++]=S[i];
            }
        }
        ANS[R++]='\0';
        printf("Case #%d: %s\n",kase,ANS+L+1);
    }
    return 0;
}
