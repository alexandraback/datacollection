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
        vector<double> pos;
        pos.push_back( B+2 );
        for(int i=0; i <= A; ++i){
            p=1.0;
            for(int j=0; j < A-i; ++j)
                p *= prob[j];
            pos.push_back( p*(i*2+B-A+1)+((1-p)*(i*2+B-A+1+B+1)) );
        }
        double ret = 987654321.0;
        for(int i=0; i < (int)pos.size(); ++i)
            ret = min(ret, pos[i]);
        printf("Case #%d: %.6f\n", tcase, ret);

    }
    return 0;
}


