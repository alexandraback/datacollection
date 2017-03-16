/* 
 4
 2 20 10
 2 10 0
 4 25 25 25 25
 3 24 30 21
 
 
 Case #1: 33.333333 66.666667
 Case #2: 0.000000 100.000000
 Case #3: 25.0 25.0 25.0 25.0
 Case #4: 34.666667 26.666667 38.666667

 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
    int noOfCases, noOfContestants,except,exceptTotal;
    int points[200],total;
    double result[200],average;
    int i,j;
    FILE *fi,*fo;
    fi = fopen ("//Users/yingwang/Downloads/A-large.in","r");
    fo = fopen ("//Users/yingwang/Downloads/A-large.out","w");
    if (fi!=NULL)
    {
        fscanf(fi,"%d",&noOfCases);
        for(i=0;i<noOfCases;i++){
            memset(points,0,200*sizeof(int));
            total=0;
            except=0;
        
            fscanf(fi,"%d",&noOfContestants);
            for(j=0;j<noOfContestants;j++){
                fscanf(fi,"%d",&points[j]);
                total+=points[j];
            }
            exceptTotal=total;
            average=((double)total*2)/noOfContestants;
            //printf("%.6lf\n",average);
            for(j=0;j<noOfContestants;j++){
                if(points[j]>=average){
                    result[j]=0;
                    exceptTotal-=points[j];
                    except++;
                }
            }
            average=((double)(total+exceptTotal))/(noOfContestants-except);
            //printf("%.6lf\n",average);
            fprintf(fo,"Case #%d: ",i+1);
            for(j=0;j<noOfContestants;j++){
                if (points[j]>average) {
                    fprintf(fo,"0 ");
                    continue;
                }
                result[j] = (average-points[j])*100/total;
                fprintf(fo,"%.6lf ",result[j]);
            }
            fprintf(fo,"\n");
        }
        
        fclose (fi);
        fclose (fo);
    } 
    return 0;
}

