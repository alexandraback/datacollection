#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAXN = 150000;
int A,B;
double P[MAXN];
int intP[MAXN];
int bucket[10];
double enterRightAway;

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int ntests;
    cin >> ntests;
    for (int test = 1; test <= ntests; test++) {
        cin >> A >> B;
        for (int i = 0; i < A; i++) cin >> P[i];
        //for (int i = 0; i < A; i++) {
        //    intP[i] = int(P[i] * 10);        
        //}
        double alpha = 1;
        for (int i = 0; i < A; i++) alpha = alpha * P[i];
        int C = B-A+1;
        int W = C + B + 1;
        double minP = 1000000000;
        for (int i = A-1; i>=0; i--) {            
            double currentP = alpha * C;
            currentP += (1-alpha) * W;
            if (currentP < minP) minP = currentP;
            alpha = alpha / P[i];
            C+=2;
            W+=2;
        }
        enterRightAway = B + 2;
        if (enterRightAway < minP) minP = enterRightAway;
        printf("Case #%d: %.6f\n",test,minP);
    }
}