#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

typedef long long ll;

int main(){

    int T;
    cin >> T;

    long double C,F,X;
    long double t;
    long farms;

    for(int i=1;i<=T;i++){

        cin >> C;
        cin >> F;
        cin >> X;

        farms=0;
        t=0;

        while(X>0){
            if(X/(2+farms*F)<C/(2+farms*F)+X/(2+farms*F+F)){
                t+=X/(2+farms*F);
                X=0;
            }else{
                t+=C/(2+farms*F);
                farms++;
            }
        }



        cout << "Case #" << i << ": ";

        cout << setiosflags(ios::fixed) << setprecision(7) << t;

        cout << endl;
    }

    return 0;
}
