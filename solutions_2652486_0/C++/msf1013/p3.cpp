#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <vector>


#include <algorithm>

using namespace std;

int main() {

    ofstream file;
    file.open ("Output4.txt");

    int t, r, n, m, k;

    cin >> t >> r >> n >> m >> k;

    file << "Case #1: " << endl;

    for(int i=1; i<=r; i++){

        for(int l=0; l<3; l++){

            int aux;
            cin >> aux;
            int y=0;

            bool tres=false;

            if(aux%3==0){
                file << 3;
                y++;
                tres=true;
            }

            if(aux%5==0){
                file << 5;
                y++;
            }

            if(aux%25==0){
                file << 5;
                if(y==2) break;
                y++;
            }

            if(y==2){
                int var=rand()%2;
                if(var==1) file << 4;
                else file << 2;
                break;

            }

            if(y==1){
                int var=rand()%2;
                if(var==1) file << 4;
                else file << 2;
                var=rand()%2;
                if(var==1) file << 4;
                else file << 2;
                break;
            }

            if(y==0){
                int var=rand()%2;
                if(var==1) file << 4;
                else file << 2;
                var=rand()%2;
                if(var==1) file << 4;
                else file << 2;
                var=rand()%2;
                if(var==1) file << 4;
                else file << 2;
                break;

            }




        }

    file << endl;



    }

    file.close();

    return 0;
}
