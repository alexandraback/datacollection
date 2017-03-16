#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int T;
    int A,B;
    scanf("%d",&T);
    for(int cas=1; cas <=T; cas++)
    {
        scanf("%d%d",&A,&B);
        double ans=B+2;
        double right=1.0;
    
        ans=min(ans,(double)( A+B+1));
        for(int i=1; i<=A; i++)
        {
            double tmp;
            scanf("%lf", &tmp);
            right = right*tmp;
               
            ans=min(ans, right*(B-i+A-i+1) + (1.0-right)*(B-i+A-i+1+B+1));

            //printf("%lf, %d, %d, %.6lf\n",right, B-i+A-i+1, B-i+A-i+1+B+1, right*(B-i+A-i+1) + (1.0-right)*(B-i+A-i+1+B+1));
            
        }
        printf("Case #%d: %.6lf\n",cas,ans);

        
    }
    return 0;
}
