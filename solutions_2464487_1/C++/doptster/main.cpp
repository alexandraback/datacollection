#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

    ifstream is;
    is.open("A-large.in");
    ofstream os;
    os.open("answer.txt");
    int test;
    is >> test;
    for(int i = 1; i <= test; i++){
        long long int r, ml;
        is >> r >> ml;
        long long int count = 0;
        //binary search??
        long long int min = 1, max = 2147483648;//ml/r;
        if(ml/r <= 2147483648)max = ml/r;
        while(max-min>1){
            long long int n = (min+max)/2;
            long long int amount = (n*2*r) + (n*2-1)*n;
            if(amount < 0){
                max--;
            }
            if(amount == ml){
                min = n; max = n;
                break;
            } else if(amount < ml){
                min = n;
            } else if(amount > ml){
                max = n;
            }
        }
        cout << min << " " << max << endl;
        count = min;
        os << "Case #" << i << ": " << count << endl;
    }
    return 0;
}
