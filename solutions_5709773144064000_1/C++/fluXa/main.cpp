#include <cstdio>

void solve(float farmCost, float farmSpeed, float winAmount) {
    float speed = 2.0f;
    
    int numFarms = 0;
    float lastT = -1.0f;
    
    while (true) {
        float t = winAmount/(speed + float(numFarms)*farmSpeed);
        for (int i = numFarms - 1; i >= 0; --i) {
            t += farmCost/(speed + float(i)*farmSpeed);
        }
        if (lastT > 0.0f && t > lastT) break;
        lastT = t;
        numFarms++;
    //    printf("%d %f\n", numFarms, t);
    }
    printf("%f", lastT);
}

int main(int argc, const char * argv[])
{
    int numCases = 0;

    scanf("%d\n", &numCases);
    float farmCost, farmSpeed, winAmount;
    
    for (int count = 1; count <= numCases; ++count) {
        if (scanf("%f %f %f\n", &farmCost, &farmSpeed, &winAmount) != 3) break;
        printf("Case #%d: ", count);
        solve(farmCost, farmSpeed, winAmount);
        printf("\n");
    }
    return 0;
}

