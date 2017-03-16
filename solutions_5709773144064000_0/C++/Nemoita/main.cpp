#include <iostream>
using namespace std;

#if 1
#define INPUT_FILE  "B-small.in.txt"
#define OUTPUT_FILE "B-small.out.txt"
#else
#define INPUT_FILE  "B-large.in.txt"
#define OUTPUT_FILE "B-large.out.txt"
#endif


int main(int argc, const char * argv[])
{
    freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w+", stdout);
    
    int T;
    
    scanf("%i\n", &T);
    
    // For each test case
    for (int t = 0; t < T; t++)
    {
        double C, F, X;
        double timeToGetNFarms = 0;
        double minSeconds;
        double rate = 2.0;
        bool enoughFarms = false;
        
        scanf("%lf %lf %lf\n", &C, &F, &X);
        
        // with 0 farms
        minSeconds = X / 2.0;
        
        // with N farms
        while (!enoughFarms)
        {
            timeToGetNFarms += C/rate;
            rate += F;
            double seconds = timeToGetNFarms + X/rate;
            if (seconds > minSeconds) enoughFarms = true;
            else minSeconds = seconds;
        }
        
        printf("Case #%i: ", t+1);
        printf("%.7f\n", minSeconds);
    }
    return 0;
}