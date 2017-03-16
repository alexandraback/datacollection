#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define _USE_MATH_DEFINES

int main() {

  ofstream file;
  file.open ("Output2.txt");

    long double r, t;
    long long int cont=0, casos;
    cin >> casos;

    for(int j=1; j<=casos; j++){

        cin >> r >> t;

        for(long double i=1.0; i<999999999; i=i+1.0){

            long double c=pow(r+2*i-1,2)-pow(r+2*i-2,2);

            t=t-c;

            if(t>=0){
                cont++;
            } else {
                break;
            }

        }

        file << "Case #" << j << ": " << cont << endl;

        cont = 0;

    }



  file.close();

  return 0;
}
