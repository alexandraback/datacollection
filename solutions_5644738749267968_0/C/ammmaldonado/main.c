#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Low to high
int compare (const void * a, const void * b){
    if( *(double*)a - *(double*)b < 0.000005){
        return 0;
    }else{
        return 1;
    }
}


int N; //Number of blocks each player has (1-1000)

double Naomi[10001]; //the masses of Naomi's blocks (between 0.0 and 1.0 exclusive)

double Ken[10001]; //the masses of Ken's blocks (between 0.0 and 1.0 exclusive)

double NaomiD[10001];

double KenD[10001];


//Devuelve la posición del siguiente elemento mayor al dado
int next(double num){

    //Miramos si tenemos algun numero mayor que Naomi, y cogemos el menor entre los mayores
    int i;
    for(i=0; i<N; i++){

        if( Ken[i] > num){
            return i;
        }
    }

    //Si no tenemos ningún numero mayor, cogemos el menor de todos los que tenemos
    for(i=0; i<N; i++){

        if( Ken[i] > 0.0){
            return i;
        }
    }

}

int main(){

    int T; //Number of test cases (1-50)
    scanf("%d", &T);

    int t;
    for(t=1; t<=T; t++){

        scanf("%d", &N);

        int i;
        for(i=0; i<N; i++){
            scanf("%lf", &Naomi[i]);
        }

        for(i=0; i<N; i++){
            scanf("%lf", &Ken[i]);
        }


        //Lo primero es ordenar los bloques de menor a mayor: para poder realizar una búsqueda binaria
        qsort(&Naomi[0], N, sizeof(double), compare);
        qsort(&Ken[0], N, sizeof(double), compare);

        memcpy(NaomiD, Naomi, N*sizeof(double));
        memcpy(KenD, Ken, N*sizeof(double));

        int Naomi_War_Points = 0;
        int Ken_War_Points = 0;

        //N rounds
        int n;
        for(n=0; n<N; n++){

                //Naomi elige un bloque y le dice el peso a Ken
                int Chosen_Naomi = n; //Los va eligiendo en el mismo orden que estan ordenados

                //Ahora Ken, de entre todos los bloque mayores que el de Naomi, elige el menor
                int Chosen_Ken = next(Naomi[n]);

                if(Ken[Chosen_Ken] > Naomi[Chosen_Naomi]){

                    Ken_War_Points++;
                }else{
                    Naomi_War_Points++;
                }

                //Quemamos los bloques elegidos
                Ken[Chosen_Ken] = -1.0;

        }



        int Naomi_Deceitful_Points = 0;
        int Ken_Deceitful_Points = 0;

        int f = N-1;
        int s = 0;

        for(n=0; n<N; n++){

            if(NaomiD[n] < KenD[s]){
                Ken_Deceitful_Points++;
                KenD[f] = -1.0;
                f--;

            }else{
                Naomi_Deceitful_Points++;
                KenD[f] = -1.0;
                s++;
            }

        }

        printf("Case #%d: %d %d\n", t, Naomi_Deceitful_Points, Naomi_War_Points);


    }


    return 0;
}
