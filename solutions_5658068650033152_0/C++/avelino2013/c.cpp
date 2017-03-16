#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=1, T, n, m, k;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n, &m, &k);
        if(n>m) swap(n, m);
        printf("Case #%d: ", t++);
        if(n<=2) printf("%d\n", k);
        else if(n==3)
        {
            if(k<=4) printf("%d\n", k);
            if(k==5) printf("4\n");
            if(k==6) printf("5\n");
            if(k==7) printf("6\n");
            if(k==8) printf("6\n");
            if(k==9) printf("7\n");
            if(k==10) printf("8\n");
            if(k==11) printf("8\n");
            if(k==12) printf("9\n");
            if(k==13) printf("10\n");
            if(k==14) printf("10\n");
            if(k==15) printf("11\n");
            if(k==16) printf("12\n");
            if(k==17) printf("13\n");
            if(k==18) printf("14\n");
        }
        else
        {
            if(k<=4) printf("%d\n", k);
            if(k==5) printf("4\n");
            if(k==6) printf("5\n");
            if(k==7) printf("6\n");
            if(k==8) printf("6\n");
            if(k==9) printf("7\n");
            if(k==10) printf("8\n");
            if(k==11) printf("8\n");
            if(k==12) printf("8\n");
            if(k==13) printf("9\n");
            if(k==14) printf("9\n");
            if(k==15) printf("10\n");
            if(k==16) printf("10\n");
            if(k==17) printf("11\n");
            if(k==18) printf("12\n");
            if(k==19) printf("13\n");
            if(k==20) printf("14\n");
        }
    }
    return 0;
}
