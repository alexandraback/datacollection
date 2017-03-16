#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

long double choose(int n, int k) {
    long double answer = 1;
    for(int i=0; i<k; i++){
        answer *= n-i;
        answer /= k-i;
    }
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
        long double answer;
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
                long double ways = 0;
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