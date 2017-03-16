#include <stdio.h>
#include <iostream>



int main (){


    int outputs[110];


    int maxl=0;

    int results;
    int A;
    int B;
    int K;
    int length=0;

    int done=0;
    //read data
        FILE * source;
        source = fopen ("B-small-attempt0 (1).in","r");//enter file name
        fscanf(source,"%i",&maxl);
        while(length<maxl){
            fscanf(source,"%i",&A);fscanf(source,"%i",&B);fscanf(source,"%i",&K);

            outputs[length]=0;
            for(int a=0;a<A;a++){
                for(int b=0;b<B;b++){
                    results= a & b;
                        if(results<K){outputs[length]++;}
                }
            }

            length++;
        }

        fclose(source);





    //write output

        source = fopen ("output.in","w");
        for(int a=0;a<maxl;a++){
            //std::cout << outputs[a]<<"\n";

                fprintf(source,"Case #%d: %d\n",(a+1),outputs[a]);


        }
        fclose(source);

    return 0;
}
