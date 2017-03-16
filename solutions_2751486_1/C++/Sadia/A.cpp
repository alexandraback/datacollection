#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
char str[1000006];
bool check(char ch)
{
    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return false;
    return true;
}
int main()
{
    //freopen("data.txt", "r", stdin);
    freopen("inputAlarge.txt", "r", stdin);
    freopen("outputA.txt", "w", stdout);
    int t,T;
    int L,l,start,end,len,i,last0;
    long long ans;
    scanf("%d", &T);
    for (t=1; t<=T; ++t)
    {
        scanf("%s %d", str, &L);
        len = strlen(str);
        for (i=0; i<len; ++i) str[i] = check(str[i]);
        //for (i=0; i<len; ++i) printf("%d", str[i]); puts("");
        start = end = 0,l=last0=0;
        ans = 0;
        while(start<len)
        {
            while (start < len && str[start]==0) ++start;
            if (end<=start)
            {
                end = start, l=0;
                while(1)
                {
                    if (!str[end]) break;
                    ++l;
                    if (l==L) break;
                    ++end;
                }
            }
            if (l == L)
            {
                //printf("\t\t%d %d : %d %d :: %d\n", start, end, len, last0, (start-last0+1)*(len-end));
                ans += (long long) (start-last0+1)*(len-end);
                last0 = start+1;
                ++end;
            }
            if (str[end]==0)
            {
                start = end;
                l = 0;
            }
            else ++start;
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
