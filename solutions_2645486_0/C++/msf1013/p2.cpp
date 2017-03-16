#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define _USE_MATH_DEFINES

int maxE;

int func(int e, int eDis, int gain, int r, int n, int i, int arr[]){

    if(i<n){
        for(int j=0; j<=eDis; j++){

            if(j<=eDis && eDis>=0){
                int res=arr[i]*j;
                int aux;

                aux = eDis-j+r;

                if(aux>e){
                    aux=e;
                }

                func(e,aux,gain+res,r,n,i+1,arr);
            }



        }
    } else {

        if(gain>maxE){
            maxE=gain;
        }

    }

}


int main() {

    ofstream file;
    file.open ("Output3.txt");

    int total;

    cin >> total;

    for(int k=1; k<=total; k++){

        int e, r, n;
        cin >> e >> r >> n;

        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        func(e,e,0,r,n,0,arr);

        file << "Case #" << k << ": " << maxE << endl;

        maxE=0;


    }

    file.close();

    return 0;
}
