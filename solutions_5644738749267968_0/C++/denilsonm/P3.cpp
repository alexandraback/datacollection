#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int T;

    int i, j, t, a;
    double d;

    cin >> T;

    for(t=0; t<T; t++){
        vector<float> Naomi, Ken;
        int N;

        cin >> N;

        //printf("Naomi: ");
        for(i=0; i<N; i++){
            cin >> d;
            //printf("%lf ", d);
            Naomi.push_back(d);
        }
        //printf("\nKen: ");

        for(i=0; i<N; i++){
            cin >> d;
            //printf("%lf ", d);
            Ken.push_back(d);
        }
        //printf("\n");

        sort(Naomi.begin(), Naomi.end());
        sort(Ken.begin(), Ken.end());

        int DW = N, NW = 0;

        i = j = N-1;

        while(i>=0 && j>=0){
            if(Naomi[i] < Ken[j]){
                j--;
                DW--;
            }else{
                i--;
                j--;
            }
        }

        i = j = 0;

        while(i<N && j<N){
            if(Ken[i] > Naomi[j]){
                i++;
                j++;
                //printf("A");
            }else{
                i++;
                NW++;
                //printf("B");
            }
        }

        printf("Case #%d: %d %d\n", t+1, DW, NW);
    }

    return 0;
}
