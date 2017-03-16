#include<stdio.h>

int T;
double C,F,X,tim,cook,ans;


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("pb.out","w",stdout);

    scanf(" %d",&T);
    for( int cas = 1; cas <= T; cas++ ){
        scanf(" %lf %lf %lf",&C,&F,&X);
        cook = 2.0;
        tim = 0.0;
        ans = X/2.0;

        while(true){
            tim += C/cook;
            cook += F;
            if( tim+X/cook < ans ){
                ans = tim+X/cook;
            }else{
                break;
            }
        }

        printf("Case #%d: %.8lf\n",cas,ans);
    }

    return 0;
}
