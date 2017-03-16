#include <iostream>
#include <stdio.h>
using namespace std;

int T;
char people[1011];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-output.txt","w",stdout);

    int test;
    int maxS;
    int i;
    int standing_up,answer;

    scanf("%d",&T);

    for (test=1;test<=T;test++)
    {
        scanf("%d",&maxS);

        scanf("%s",people);

        answer=0;
        standing_up=people[0]-'0';

        for (i=1;i<=maxS;i++)
        {
            if (standing_up<i)
            {
                answer+=i-standing_up;
                standing_up=i;
            }

            standing_up+=people[i]-'0';
        }

        printf("Case #%d: %d\n",test,answer);
    }

    return 0;
}
