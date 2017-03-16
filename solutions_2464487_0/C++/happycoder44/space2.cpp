#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <stdio.h>

#define pb push_back
#define mp make_pair

using namespace std;


int main(){
    long long T,r,t;
    cin >> T;
    long long count;
    for(int i = 0; i < T; i++){
        cin >> r;
        cin >> t;
        count = 0;
        r--;
        do{
        r+=2;
        count++;
        t -= ((r)*(r) - (r-1)*(r-1));

        }while(t >= (r+2)*(r+2) - (r+1)*(r+1));
        cout << "Case #" << i+1 << ": " << count << endl;

    }


}
