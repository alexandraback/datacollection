#include <stdio.h>

double optmise(double C,double X,double F){

double answer=0;
double Y=0;
double R=2;
bool opti=1;
double t1=0;
double t2=0;

while(opti){
    R=Y*F+2;
    t1=X/R;
    t2=C/R+X/(R+F);
    if(t1<=t2){
        answer=answer+X/R;
        opti=0;
    }else{
        Y=Y+1;
        answer=answer+C/R;
    }
}

return(answer);
}
int main (){
    int length=0;
    int pos=1;
    double dataC[120];
    double dataX[120];
    double dataF[120];
    double state[120];
    int maxl=0;
    double temp=0;
    //read data
        FILE * source;
        source = fopen ("B-large.in","r");//enter file name
        fscanf(source,"%i",&maxl);
        fscanf(source,"%lf",&temp);
        dataC[length]=temp;

        while(length<maxl){
            fscanf(source,"%lf",&temp);
            if(pos==3){
                length++;
                dataC[length]=temp;
                pos=1;
            }else if(pos==2){
                dataX[length]=temp;
                pos++;
            }else if(pos==1){
                dataF[length]=temp;
                pos++;
            }
        }

        fclose(source);

    //do magic
        for(int a=0;a<maxl;a++){
            state[a]=optmise(dataC[a],dataX[a],dataF[a]);
        }
    //write output
        source = fopen ("output.in","w");
        for(int a=0;a<maxl;a++){
            fprintf(source,"Case #%d: %.10lf\n",(a+1),state[a]);
        }


        fclose(source);

    return 0;
}
