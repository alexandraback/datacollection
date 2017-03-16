#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int caseno=1; caseno<=t; caseno++)
    {
        int p,q;
        scanf("%d/%d",&p,&q);
        bool flag = true;
        int tmp = q;
        while(tmp)
        {
            if(tmp!=1 && tmp%2==1){
                flag = false;
                break;
            }
            else tmp/=2;
        }
        if(!flag){
            printf("Case #%d: impossible\n",caseno);
        }
        else{
            double num = (double)p/(double)q;
            int cnt=0;
            while(num < 1)
            {
                num *=2;
                cnt++;
            }
            printf("Case #%d: %d\n",caseno, cnt);
        }
    }

    return 0;
}
