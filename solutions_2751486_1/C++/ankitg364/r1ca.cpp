#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<climits>
using namespace std;

int isvowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return 1;
    return 0;
}

long long t, n, co, a;
long long answer;
char str[1000010];

int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>>t;
    for(int c=1; c<=t; c++)
    {
        answer=0;
        cin>>str>>n;
        a=0;
        co=0;
        if(!isvowel(str[0]))
        {
            co++;
            if(n==1)
            {
                a=1;
                answer=1;
            }
        }
        for(int i=1; str[i]!='\0'; i++)
        {
            if(isvowel(str[i]))
            {
                co=0;
                answer+=a;
            }
            else
            {
                co++;
                if(co>=n)
                {
                    a=(i-n+2);
                    answer+=a;
                }
                else
                {
                    answer+=a;
                }
            }
        }

        printf("Case #%d: %lld\n", c, answer);
    }
    return 0;
}
