#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>

#define MAXLENGTH 100000

using namespace std;
double p[MAXLENGTH];
double probability[MAXLENGTH+1];

int main(){
    int t;
    cin>>t;
    for(int test = 0 ; test < t ; ++test){
        int length,typed;
        double ans=0.0/0.0;//INFINITY;
        cin>>typed>>length;
        if(typed == 0){
            ans = length+1 ;
        }else{
            for(int i = 0; i < typed  ;++i){
                cin>>p[i];
            }
            double typed_prefix_right = 1;
            for(int i = 0 ; i < typed ; ++i){
                probability[i] = typed_prefix_right*(1-p[i]);
                typed_prefix_right *= p[i];
            }
            probability[typed] = typed_prefix_right ;
            //////////////////////
            double sum[MAXLENGTH+1];
            sum[typed] = probability[typed];
            for(int i = typed -1 ; i >= 0 ; --i){
                sum[i] = sum[i+1]+probability[i];
            }
            double ans_pressing_enter = 2+length;
            double backspace[MAXLENGTH+1];
            for(int i = 0 ; i <= typed ; ++i){
                backspace[i] = (length-typed+1+i*2)*sum[typed-i]  //right
                    + (1-sum[typed-i])*(2*length-typed+2+2*i);  //wrong
            }

         //   for(int i = 0; i <= typed ; ++i){
         //       printf("%lf ",probability[i]);
         //   }
         //   printf("\n");
         //   for(int i = 0; i <= typed ; ++i){
         //       printf("%lf ",sum[i]);
         //   }
         //   printf("\n");
         //   for(int i = 0; i <= typed ; ++i){
         //       printf("%lf ",backspace[i]);
         //   }
         //   printf("\n%lf",ans_pressing_enter);

         //   printf("\n");
            ans = ans_pressing_enter;
            for(int i = 0 ; i <= typed ; ++i){
                ans  = min(ans,backspace[i]);
            }
        }
        printf("Case #%d: %lf\n",test+1,ans);
    }
}
