#include<stdio.h>
#include<stdlib.h>


int main(){
    FILE* in;
    FILE* out;
    in=fopen("d:/input1.in","r");
    out=fopen("d:/output1.out","w");
    
    int t,n,j;
    double need,need2,total,sum;
    int a[300];
    fscanf(in,"%d",&t);
    for(int i=1;i<=t;i++){
        fprintf(out,"Case #%d: ",i);
        sum=0;
        fscanf(in,"%d",&n);
        for(int j=0;j<n;j++){
            fscanf(in,"%d",&a[j]);
            sum+=a[j];
        }
        need=(sum*2)/n;
        //fprintf(out,"|need = %f |",need);
        
        double newsum=sum;
        int nn=0;
        for(int j=0;j<n;j++){
            if(a[j]<need) {newsum+=a[j]; nn++;}}
        need2=newsum/nn;
        //fprintf(out,"|need2 = %f |",need2);

/*        
        if(nn!=n){
            int newn = 0;
            while(newn!=nn){
                newn=0;
                for(int j=0;j<n;j++){if(a[j]<need2 && a[j]<need) newn++;}
                fprintf(out,"|newn = %d |",newn);
                if(newn==nn) break;
                nn==newn;
                need2=(sum)/newn;
            }
        }
*/       

        int newn=0;
        double need3;
        bool check2=0;
        
        newsum=sum;
        if(nn!=n){
            for(int j=0;j<n;j++){if(a[j]<need2 && a[j]<need) {newsum+=a[j]; newn++;}}
            if(newn!=nn && newn!=0){
                check2=1;
                need3=newsum/newn;
            }
         }
        
        
        bool check=0;
        if(nn!=n)check=1;
              
        
        if(check2) need=need3;
        else if(check) need=need2;
        //fprintf(out,"|need = %f |",need);
        
        
        for(int j=0;j<n;j++)
        {
            if(a[j]>need) total=0; 
            else {
                /*
                if(check2)
                total=(need3-a[j])*100;                   
                else if(check)
                total=(need2-a[j])*100;
                else */
                total=(need-a[j])*100.00;
                total/=sum;
                //if(total<0) total=0;
            }
            fprintf(out,"%lf ",total);
        }
        fprintf(out,"\n");
    }
    //system("pause");
}
