// Qualification Round 2012 : Problem B. Dancing With the Googlers

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++) {
        int N,S,p;
        int mark;
        int out=0;
        scanf("%d%d%d",&N,&S,&p);
        printf("Case #%d: ",i+1);
        for (int j=0; j<N; j++) {
            scanf("%d",&mark);
            int a= mark-3*p;
            if(a>=-2)out++;
            else if(a>-5 && S &&mark) {
                S--;out++;
            }
            //printf("%d ",a);
        }
        printf("%d\n",out);
    }
    return 0;
}