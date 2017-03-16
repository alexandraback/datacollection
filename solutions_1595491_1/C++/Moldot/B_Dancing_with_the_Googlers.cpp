/*  Grader: Codejam - Qualification Round 2012
    B Dancing with the Googlers
    Varot Premtoon 14 Apr 2555 */

#include <cstdio>

int sol(int cse)
{
    int sum = 0;
    int n,s,p;
    int t;
    int i,j,k;
    scanf("%d %d %d",&n,&s,&p);
    for(i=0;i<n;i++) {
        scanf("%d",&t);
        j = t/3;
        k = t%3;
        if(j+(k>0) >= p) {
            sum++;
        } else if(s>0 and k!=1 and (j!=0 or k==2) and j+(k>0)+1 >= p) {
            sum++;
            s--;
        }
    }
    printf("Case #%d: %d\n",cse,sum);
    return 0;
}


int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++) sol(i);
    return 0;
}
