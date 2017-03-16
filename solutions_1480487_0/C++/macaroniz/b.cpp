#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CAS;
int N;
int s[210];
int sum;
const double eps = 1e-6;
bool can(double x,int y)
{
    int cnt = 0,ss = 0;
    for(int i = 0;i < N;i++)
        if(s[i] <= x)
        {
            cnt++;
            ss += s[i];
        }
    double avg = 1.0*(sum * (1-y/100) + ss)/cnt;
    //printf("x:%lf avg:%lf\n",x,avg);
    return x >= avg;
}
double erfen(int s)
{
    double l = 0,r = 100,mid;
    while(r - l > eps)
    {
        mid = (l + r)/2;
        if(can(s + mid/100*sum,mid))
            r = mid;
        else l = mid;
        //printf("%lf %lf\n",l,r);
        //system("pause");
    }
    return (l + r)/2;
}
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&CAS);
    for(int cas = 1;cas <= CAS;cas++)
    {
        scanf("%d",&N);
        sum = 0;
        double avg = 0;
        for(int i = 0;i < N;i++)
        {
            scanf("%d",&s[i]);
            sum += s[i];
        }
        printf("Case #%d: ",cas);
        for(int i = 0;i < N;i++)
            printf("%.6lf ",erfen(s[i]));
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
}
