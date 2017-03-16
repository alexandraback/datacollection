#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double choose(int n, int k) {
    double answer = 1;
    for(int i=n-k+1; i<=n; i++)
        answer *= i;
    for(int i=1; i<=k; i++)
        answer /= i;
    return answer;
}

int main() {
    int ncases;
    cin>>ncases;
    for(int caseNum=0; caseNum < ncases; caseNum++) {
        int numDiamonds, x, y;
        cin>>numDiamonds>>x>>y;
        int layer=0;
        while(numDiamonds >= 4*layer + 1){
            numDiamonds -= 4*layer + 1;
            layer++;
        }
        double answer;
        if((abs(x) + y)%2 != 0)
            answer = 0;
        else if(abs(x) + y < 2*layer)
            answer = 1;
        else if(abs(x) + y > 2*layer)
            answer = 0;
        else {
            if(numDiamonds >= 2*layer + y + 1)
                answer = 1;
            else if(x == 0)
                answer = 0;
            else {
                double ways = 0;
                for(int n=y+1; n<=numDiamonds; n++){
                    ways += choose(numDiamonds, n);
                }
                answer = ways / pow(2.0, numDiamonds);
            }
        }
        cout.precision(10);
        cout<<"Case #"<<caseNum+1<<": "<<answer<<"\n";
    }
}