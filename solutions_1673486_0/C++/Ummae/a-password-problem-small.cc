#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int tcase=1; tcase<=T; ++tcase)
    {
        int A,B;
        scanf("%d %d", &A, &B);
        double p;
        vector<double> prob;
        for(int i=0; i < A; ++i){
            scanf("%lf", &p);
            prob.push_back(p);
        }
        double c1=0.0,c2=0.0,c3=0.0,c4=0.0,c5=0.0;
        for(int i=0; i < (1<<A); ++i){

            p = 1.0;
            for(int j=0; j < A; ++j){
                if(i&(1<<j))
                    p *= (1-prob[j]);
                else 
                    p *= prob[j];
            }

            c1 += (p*(B+2));

            bool typo=false;
            for(int k=0; k < A; ++k){
                if( i&(1<<k) )
                    typo=true;
            }
            c2 += (typo ? p*(B-A+1+B+1) : p*(B-A+1));

            typo=false;
            for(int k=0; k < A-1; ++k){
                if( i&(1<<k) )
                    typo=true;
            }
            c3 += (typo ? p*(B-A+3+B+1) : p*(B-A+3));

            typo=false;
            for(int k=0; k < A-2; ++k){
                if( i&(1<<k) )
                    typo=true;
            }
            c4 += (typo ? p*(B-A+5+B+1) : p*(B-A+5));

            typo=false;
            for(int k=0; k < A-3; ++k){
                if( i&(1<<k) )
                    typo=true;
            }
            c5 += (typo ? p*(B-A+7+B+1) : p*(B-A+7));
            //printf("[%f] %f %f %f %f %f\n",p, c1,c2,c3,c4,c5);
        }
        double ret = min(c1,c2);
        ret = min(ret, c3);
        if( A==2 ) ret = min(ret, c4);
        if( A==3 ) ret = min(ret, c5);
        printf("Case #%d: %.6f\n", tcase, ret);
    }
    return 0;
}
