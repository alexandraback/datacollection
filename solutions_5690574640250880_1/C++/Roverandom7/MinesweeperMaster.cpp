#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

    FILE *f;


int rjesenje_2(int R, int C, int i){
        int j,k;
        int Praznine;
        fprintf(f, "Case #%d:\n",i+1);

            Praznine = R*C;

            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else if( Praznine != 0 ){
                        fprintf(f, ".");
                        Praznine--;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");
                                }
return 1;

}

int rjesenje_1(int R, int C, int M, int i){

    int PopunjeniRetci;
    int PopunjeniStupci;
    int OstatakNakonPopunjivanjaRedaka;
    int Praznine;
    int k,j;

    PopunjeniRetci = M/C;
    OstatakNakonPopunjivanjaRedaka = M%C;

    Praznine = R*C - M;

    if( Praznine == 1 ){
                    fprintf(f, "Case #%d:\n",i+1);
            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");

                                }
                        return 1;
                        }


    if( Praznine < 4 ){
        fprintf(f, "Case #%d:\nImpossible\n", i+1);
        return 1;
                }

    if( Praznine%2 == 0 ){

        fprintf(f, "Case #%d:\n",i+1);

        if( Praznine < 2*C+1  ){
            int temp = Praznine;
            Praznine = Praznine/2;
            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else if( j < 2 && Praznine != 0 ){
                        fprintf(f, ".");
                        Praznine--;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");
                    if( j<2 )
                        Praznine = temp/2;
                                }
                        return 1;
                        }
        if( Praznine%C != 1 ){
        if( Praznine > 2*C ){

            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else if( Praznine != 0 ){
                        fprintf(f, ".");
                        Praznine--;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");
                                }
                        return 1;
                        }
                    }
            else{
            int Granica;

            Granica = Praznine/C;

            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else if( j == Granica-1 && k == C-1 ){
                        fprintf(f, "*");
                        }
                    else if( Praznine != 0 ){
                        fprintf(f, ".");
                        Praznine--;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");
                                }
                        return 1;


                    }
                }
        else if( Praznine%2 == 1 ){
            fprintf(f, "Case #%d:\n",i+1);

            if( Praznine < 2*C );
            else if( Praznine < 2*R );
            else if( Praznine > 2*C ){
                if( Praznine % C == 1 ){

                if( R == 3 && C == 3 && M == 2){
                    fprintf(f, "Impossible\n");
                    return 1;
                    }

                if( Praznine/C < 3 ){
                    for( j = 0; j < R; j++ ){
                        for( k = 0; k < C; k++ ){
                            if( j == 0 && k == 0 ){
                                Praznine--;
                                fprintf(f, "c");continue;}
                            else if( Praznine != 0 && k != C-1 ){
                                fprintf(f, ".");
                                Praznine--;}
                            else
                                fprintf(f, "*");
                                        }
                            fprintf(f, "\n");
                                    }
                            return 1;
                                    }
                else if( Praznine/C > 3 ){
                    int Granica;

                    Granica = Praznine/C;

                    for( j = 0; j < R; j++ ){
                        for( k = 0; k < C; k++ ){
                            if( j == 0 && k == 0 ){
                                Praznine--;
                                fprintf(f, "c");continue;}
                            else if( j == Granica-1 && k == C-1 ){
                                fprintf(f, "*");
                                    }
                            else if( Praznine != 0 ){
                                fprintf(f, ".");
                                Praznine--;}
                            else
                                fprintf(f, "*");
                                        }
                            fprintf(f, "\n");
                                    }
                            return 1;

                                        }
                else if(Praznine/C == 3){
                        if( C == 4 && R < 5 ){
                            for( j = 0; j < R; j++ ){
                                for( k = 0; k < C; k++ ){
                                    if( j == 0 && k == 0 ){
                                        Praznine--;
                                        fprintf(f, "c");continue;}
                                    else if( j==2 && k==3  ){
                                        fprintf(f, "*");
                                        }
                                    else if( Praznine != 0  ){
                                        fprintf(f, ".");
                                        Praznine--;}
                                    else
                                        fprintf(f, "*");
                                            }
                                    fprintf(f, "\n");
                                        }
                                    return 1;
                                        }
                        else if( C == 3 && R < 5 ){
                            for( j = 0; j < R; j++ ){
                                for( k = 0; k < C; k++ ){
                                    if( j == 0 && k == 0 ){
                                        Praznine--;
                                        fprintf(f, "c");continue;}
                                    else if( j==2 && k==2 ){
                                        fprintf(f, "*");
                                        Praznine--;}
                                    else if( Praznine != 0 ){
                                        fprintf(f, ".");
                                        Praznine--;}
                                    else
                                        fprintf(f, "*");
                                            }
                                    fprintf(f, "\n");
                                        }
                                    return 1;
                        }
                        else if( C == 4 ){
                                for( j = 0; j < R; j++ ){
                                    for( k = 0; k < C; k++ ){
                                        if( j == 0 && k == 0 ){
                                            Praznine--;
                                            fprintf(f, "c");continue;}
                                        else if( k == 3 && j == 2 ){
                                            fprintf(f, "*");
                                                }
                                        else if( Praznine != 0 ){
                                            fprintf(f, ".");
                                                  Praznine--;
                                                }
                                        else
                                            fprintf(f, "*");
                                                }
                                        fprintf(f, "\n");
                                                }
                                        return 1;

                                            }
                        else if( C == 3 ){
                                for( j = 0; j < R; j++ ){
                                    for( k = 0; k < C; k++ ){
                                        if( j == 0 && k == 0 ){
                                            Praznine--;
                                            fprintf(f, "c");continue;}
                                        else if( k==2 && j==2 ){
                                                fprintf(f, "*");
                                                }
                                        else if( Praznine != 0 ){
                                                fprintf(f, ".");
                                                Praznine--;
                                                }
                                        else
                                            fprintf(f, "*");
                                                }
                                        fprintf(f, "\n");
                                                }
                                        return 1;
                                            }
                                        }


                        }
                else{
                    for( j = 0; j < R; j++ ){
                        for( k = 0; k < C; k++ ){
                            if( j == 0 && k == 0 ){
                                Praznine--;
                                fprintf(f, "c");continue;}
                            else if( Praznine != 0 ){
                                fprintf(f, ".");
                                Praznine--;}
                            else
                                fprintf(f, "*");
                                    }
                            fprintf(f, "\n");
                                    }
                            return 1;
                            }

                }
            else if( Praznine > 2*R ){

                if( Praznine % R == 1 ){

                if( Praznine/R < 3 ){
                    for( j = 0; j < R; j++ ){
                        for( k = 0; k < C; k++ ){
                            if( j == 0 && k == 0 ){
                                Praznine--;
                                fprintf(f, "c");continue;}
                            else if( Praznine != 0 && j != R-1 && k<2 ){
                                fprintf(f, ".");
                                Praznine--;}
                            else if( Praznine != 0 && j != R-1 && k==2 ){
                                if( j > 2 ) fprintf(f, "*");
                                else {
                                        fprintf(f, ".");
                                        Praznine--;}
                                }
                            else
                                fprintf(f, "*");
                                        }
                            fprintf(f, "\n");
                                    }
                            return 1;
                                    }
                else if( Praznine/R > 3 ){
                    int Granica;

                    Granica = Praznine/R;

                    for( j = 0; j < R; j++ ){
                        for( k = 0; k < C; k++ ){
                            if( j == 0 && k == 0 ){
                                Praznine--;
                                fprintf(f, "c");continue;}
                            else if( Praznine != 0 && k < Granica ){
                                if( j == R-1 ) fprintf(f, "*");
                                else{
                                    fprintf(f, ".");
                                    Praznine--;}
                                    }
                            else if( Praznine != 0 && k < Granica+1 ){
                                if( j > 1 ) fprintf(f, "*");
                                else{
                                    fprintf(f, ".");
                                    Praznine--;
                                    }
                                }
                            else
                                fprintf(f, "*");
                                        }
                            fprintf(f, "\n");
                                    }
                            return 1;
                        }

                else if(Praznine/R == 3){
                        if( R == 4 && C < 5 ){
                                for( j = 0; j < R; j++ ){
                                    for( k = 0; k < C; k++ ){
                                        if( j == 0 && k == 0 ){
                                            Praznine--;
                                            fprintf(f, "c");continue;}
                                        else if( Praznine != 0 && k < 4 ){
                                            if( k == 3 && j == 2 )
                                                fprintf(f, "*");
                                            else {fprintf(f, ".");
                                                  Praznine--;}
                                                }
                                        else
                                            fprintf(f, "*");
                                                }
                                        fprintf(f, "\n");
                                                }
                                        return 1;
                        }
                        else if( R == 3 && C < 5 ){
                                for( j = 0; j < R; j++ ){
                                    for( k = 0; k < C; k++ ){
                                        if( j == 0 && k == 0 ){
                                            Praznine--;
                                            fprintf(f, "c");continue;}
                                        else if( Praznine != 0 && k < 4 ){
                                                fprintf(f, ".");
                                                Praznine--;
                                                }
                                        else
                                            fprintf(f, "*");
                                                }
                                        fprintf(f, "\n");
                                                }
                                        return 1;
                        }
                        else if( R == 4 ){
                                for( j = 0; j < R; j++ ){
                                    for( k = 0; k < C; k++ ){
                                        if( j == 0 && k == 0 ){
                                            Praznine--;
                                            fprintf(f, "c");continue;}
                                        else if( Praznine != 0 && k < 4 ){
                                            if( k == 3 && j == 2 )
                                                fprintf(f, "*");
                                            else {fprintf(f, ".");
                                                  Praznine--;}
                                                }
                                        else
                                            fprintf(f, "*");
                                                }
                                        fprintf(f, "\n");
                                                }
                                        return 1;
                                            }
                        else if( R == 3 ){
                                for( j = 0; j < R; j++ ){
                                    for( k = 0; k < C; k++ ){
                                        if( j == 0 && k == 0 ){
                                            Praznine--;
                                            fprintf(f, "c");continue;}
                                        else if( Praznine != 0 && k < 4 ){
                                                fprintf(f, ".");
                                                Praznine--;
                                                }
                                        else
                                            fprintf(f, "*");
                                                }
                                        fprintf(f, "\n");
                                                }
                                        return 1;
                                            }
                                        }

                        }
                else{
                    int stupci;
                    int retci;

                    stupci = Praznine/R;
                    retci = Praznine%R;

                    for( j = 0; j < R; j++ ){
                        for( k = 0; k < C; k++ ){
                            if( j == 0 && k == 0 ){
                                Praznine--;
                                fprintf(f, "c");continue;}
                            else if( Praznine != 0 && k<stupci+1 ){
                                if( k == stupci && j > retci-1 )
                                    fprintf(f, "*");
                                else{
                                        fprintf(f, ".");
                                        Praznine--;}
                                }
                            else
                                fprintf(f, "*");
                                    }
                            fprintf(f, "\n");
                                    }
                            return 1;
                            }

                    }

        if( Praznine < 2*C || Praznine < 2*R ){
                        if( Praznine < 9 );
                        else if( Praznine >8 ){
                            int Granica;
                            Granica = Praznine;
                            Granica = Granica-3;
                            Granica = Granica/2;

                            for( j = 0; j < R; j++ ){
                                for( k = 0; k < C; k++ ){
                                    if( j == 0 && k == 0 ){
                                        Praznine--;
                                        fprintf(f, "c");continue;}
                                    else if( Praznine != 0 && k<Granica ){
                                        fprintf(f, ".");
                                        Praznine--;}
                                    else
                                        fprintf(f, "*");
                                            }
                                fprintf(f, "\n");
                                    }
                                return 1;
                                }
                        }

        fprintf(f, "Impossible\n");
        return 1;


        }


}



int main(){
    ifstream ulazniTok("C-large.in");

    int T;

    int i;
    int j;


    f = fopen("out.txt", "w");


    ulazniTok >> T;
for( i = 0; i < T ; i++ ){

    int R, C, M;

    int PopunjeniRetci;
    int PopunjeniStupci;
    int OstatakNakonPopunjivanjaRedaka;

    ulazniTok >> R;
    ulazniTok >> C;
    ulazniTok >> M;

    //fprintf(f, "%d %d %d %d\n",i,R,C,M);

    if( M == 0 )
        rjesenje_2(R, C, i);
    else if( R > 2 && C > 2 )
        rjesenje_1(R,C,M,i);
    else if( R == 1 && C == 1 ){
                fprintf(f, "Case #%d:\n",i+1);
                fprintf(f, "c\n");
                continue;
                        }
    else if( R == 2 && C == 2){
            fprintf(f, "Case #%d:\n",i+1);
         if( M == 3 ){
                fprintf(f, "c*\n**\n");
                    }
            else fprintf(f, "Impossible\n");
                }
    else if( R == 1 && C > 1 ){
        int Praznine;
        fprintf(f, "Case #%d:\n",i+1);
        fprintf(f, "c");
        Praznine = R*C - M;
        Praznine--;
        for( int j = 1; j < C; j++ ){
            if(Praznine!=0){
                    fprintf(f,".");
                    Praznine--;
                        }
            else fprintf(f, "*");
                        }
                fprintf(f, "\n");
                }
        else if( R > 1 && C == 1 ){
            int Praznine;
                fprintf(f, "Case #%d:\n",i+1);
                fprintf(f, "c\n");
                Praznine = R*C - M;
                Praznine--;
                for( int j = 1; j < R; j++ ){
                    if(Praznine!=0){
                        fprintf(f,".\n");
                        Praznine--;
                            }
                    else fprintf(f, "*\n");
                        }
                }
        else if( R == 2 && C > 2 ){
            int Praznine;
            int j,k;
                fprintf(f, "Case #%d:\n",i+1);
            Praznine = R*C-M;
            if( Praznine == 1 ){
            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");

                                }
                        continue;
                        }
            if( Praznine < 4 ){
                fprintf(f, "Impossible\n", i+1);
                continue;
                }
            if( Praznine%2 == 1 ) fprintf(f,"Impossible\n");
            else{
                int Granica = Praznine/2;

            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else if( k<Granica && Praznine != 0 ){
                        fprintf(f, ".");
                        Praznine--;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");

                                }
                        continue;
                        }
                  }
        else if( R > 2 && C == 2 ){
            int Praznine;
            int j,k;
                fprintf(f, "Case #%d:\n",i+1);
            Praznine = R*C-M;

            if( Praznine == 1 ){
            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");

                                }
                        continue;
                        }

            if( Praznine < 4 ){
                fprintf(f, "Impossible\n", i+1);
                continue;
                }
            if( Praznine%2 == 1 ) fprintf(f,"Impossible\n");
            else{
                int Granica = Praznine/2;

            for( j = 0; j < R; j++ ){
                for( k = 0; k < C; k++ ){
                    if( j == 0 && k == 0 ){
                        Praznine--;
                        fprintf(f, "c");continue;}
                    else if( j < Granica && Praznine != 0 ){
                        fprintf(f, ".");
                        Praznine--;}
                    else
                        fprintf(f, "*");
                                    }
                    fprintf(f, "\n");

                                }
                        continue;
                        }
                    }

    }



fclose(f);

return 0;

}
