#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAXN 55

using namespace std;

int N;
int LIST[MAXN*2][MAXN];
int CNT[2505];
vector<int> ANS;

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        for(int i=0;i<=2504;i++)CNT[i]=0;
        ANS.clear();
        int max_height=0;
        scanf("%d",&N);
        for(int i=0;i<2*N-1;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&LIST[i][j]);
                max_height=max(max_height,LIST[i][j]);
                CNT[LIST[i][j]]++;
            }
        }
        for(int i=0;i<=max_height;i++)
        {
            if(CNT[i]%2)ANS.push_back(i);
        }
        sort(ANS.begin(),ANS.end());
        printf("Case #%d:",kase);
        for(int i=0;i<ANS.size();i++)
        {
            printf(" %d",ANS[i]);
        }
        puts("");
    }
    return 0;
}
