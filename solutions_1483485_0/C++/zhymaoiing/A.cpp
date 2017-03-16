#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const int MaxL = 1024;
char S[MaxL],T[MaxL];
int Turn[26] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};

int main(){
    freopen("W:\\A-small-attempt0.in","r",stdin);
    freopen("W:\\A-small-attempt0.out","w",stdout);
    int tCase;
    scanf("%d",&tCase);
    gets(S);
    for (int ct = 1;ct <= tCase;ct++){
        gets(S);
        printf("Case #%d: ",ct);
        for (int i = 0;S[i];i++)
            if (isalpha(S[i]))
                putchar(Turn[S[i] - 'a'] + 'a');
            else
                putchar(S[i]);
        putchar('\n');
    }
    return 0;
}
