#include <stdio.h>
void winlose(int R, int C, int M,int A,FILE * pf){
    //0 impossible
    //1, R=1
    //2, C=1
    //3, R=2
    //4, C=2
    //5, r=3
    //6, c=3
    //7 win

    fprintf(pf,"Case #%d:\n",(A+1));
    int temp=0;
    int limit=0;
    temp=R*C-M;
    limit=temp/2;

if((R==1)||(C==1)){
            for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    if((c==0)&&(r==0)){fputc('c',pf);temp--;}
                    else{
                        if(temp>0){
                            fputc('.',pf);temp--;
                        }else{
                            fputc('*',pf);
                        }
                    }
                }
                fputc('\n',pf);
            }
}else if((temp%2==0)&&(temp>2)){


            if((temp%C!=1)||(C>limit)){

            for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    if((c==0)&&(r==0)){fputc('c',pf);temp--;}
                    else{
                        if((temp>0)&&(c<limit)){
                            fputc('.',pf);temp--;
                        }else{
                            fputc('*',pf);
                        }
                    }
                }
                fputc('\n',pf);
            }

            }else{
            limit=temp/C-1;

             for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    if((c==0)&&(r==0)){fputc('c',pf);temp--;}
                    else if((c==(C-1))&&(r==limit)){fputc('*',pf);}
                    else{
                        if((temp>0)){
                            fputc('.',pf);temp--;
                        }else{
                            fputc('*',pf);
                        }
                    }
                }
                fputc('\n',pf);
            }
            }


}else if((temp>8)&&(R!=2)&&(C!=2)){
  if(temp%3==0){limit=temp/3;}else{limit=temp/3+1;}
        if(C>limit){
            for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    if((c==0)&&(r==0)){fputc('c',pf);temp--;}
                    else{
                        if((temp>0)&&(c<limit)){
                            fputc('.',pf);temp--;
                        }else{
                            fputc('*',pf);
                        }
                    }
                }
                fputc('\n',pf);
            }
        }else if(temp%C!=1){
            for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    if((c==0)&&(r==0)){fputc('c',pf);temp--;}
                    else{
                        if((temp>0)){
                            fputc('.',pf);temp--;
                        }else{
                            fputc('*',pf);
                        }
                    }
                }
                fputc('\n',pf);
            }
        }else{
            limit=temp/C-1;
            for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    if((c==0)&&(r==0)){fputc('c',pf);temp--;}
                    else if((c==(C-1))&&(r==limit)){fputc('*',pf);}
                    else{
                        if((temp>0)){
                            fputc('.',pf);temp--;
                        }else{
                            fputc('*',pf);
                        }
                    }
                }
                fputc('\n',pf);
            }
        }
}else if(temp==1){
            for(int r=0;r<R;r++){
                for(int c=0;c<C;c++){
                    if((c==0)&&(r==0)){fputc('c',pf);temp--;}
                    else{
                            fputc('*',pf);
                        }

                }
                fputc('\n',pf);
            }
}else{
    fprintf(pf,"Impossible\n");
}
}
int main (){
    int length=0;
    int pos=1;
    int dataR[240];
    int dataC[240];
    int dataM[240];
    int maxl=0;
    int temp=0;
    //read data
        FILE * source;
        source = fopen ("C-large.in","r");//enter file name
        fscanf(source,"%i",&maxl);
        fscanf(source,"%i",&temp);
        dataR[length]=temp;

        while(length<maxl){
            fscanf(source,"%i",&temp);
            if(pos==3){
                length++;
                dataR[length]=temp;
                pos=1;
            }else if(pos==2){
                dataM[length]=temp;
                pos++;
            }else if(pos==1){
                dataC[length]=temp;
                pos++;
            }
        }

        fclose(source);


    //write output
        source = fopen ("output.in","w");
        for(int a=0;a<maxl;a++){
            winlose(dataR[a],dataC[a],dataM[a],a,source);
        }
        fclose(source);

    return 0;
}


