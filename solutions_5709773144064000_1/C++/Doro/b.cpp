#include <cstdio>
#include <cmath>

void test_case(){
    double farm_cost, farm_rate, goal; // C, F, X
    scanf("%lf%lf%lf", &farm_cost, &farm_rate, &goal);

    int num_of_farms = floor(goal*farm_rate - 2 * farm_cost) / (farm_cost * farm_rate);
    //printf("the best -> build %d farms\n", num_of_farms);
    double time = 0;
    int k = 0;
    while(k < num_of_farms){
        // build (k+1)-th farm
        time += farm_cost/ (2 + k*farm_rate); // time to buy farm
        ++k;
    }
    // when we have num_of_farms -> produce X cookies
    time += goal / (2 + k*farm_rate);
    printf("%.7lf\n", time);
}

int main(){
    int z;
    scanf("%d", &z);
    for(int t=1;t<=z;++t){
        printf("Case #%d: ", t);
        test_case();
    }
    return 0;
}
